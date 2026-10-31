import sys
import os
import subprocess
import cv2
from PyQt6.QtWidgets import (QApplication, QMainWindow, QWidget, QHBoxLayout, 
                             QVBoxLayout, QPushButton, QComboBox, QFileDialog, QLabel)
from PyQt6.QtCore import QTimer, Qt
from PyQt6.QtGui import QImage, QPixmap

class VirtualCamGui(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Virtual Camera Controller")
        self.setFixedSize(400, 320)

        self.video_folder = os.getcwd()
        self.process = None
        self.cap_preview = None

        self.timer = QTimer()
        self.timer.timeout.connect(self.update_preview)

        container_widget = QWidget()
        self.setCentralWidget(container_widget)
        outer_layout = QVBoxLayout(container_widget)
        outer_layout.setContentsMargins(10, 10, 10, 10)
        outer_layout.setSpacing(10)

        main_layout = QHBoxLayout()
        main_layout.setSpacing(10)

        left_panel = QWidget()
        left_layout = QVBoxLayout(left_panel)
        left_layout.setContentsMargins(0, 0, 0, 0)
        left_layout.setSpacing(8)

        self.combo_video = QComboBox()
        self.btn_start = QPushButton("Запустить")
        self.btn_stop = QPushButton("Остановить")
        self.btn_folder = QPushButton("Выбрать папку")
        self.btn_refresh = QPushButton("Обновить список")

        left_layout.addWidget(self.combo_video)
        left_layout.addWidget(self.btn_start)
        left_layout.addWidget(self.btn_stop)
        left_layout.addWidget(self.btn_folder)
        left_layout.addWidget(self.btn_refresh)
        left_layout.addStretch()

        self.lbl_cam = QLabel("Не запущенна виртуальная камера")
        self.lbl_cam.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.lbl_cam.setStyleSheet("border: 1px solid black; background-color: #f0f0f0;")

        main_layout.addWidget(left_panel, stretch=1)
        main_layout.addWidget(self.lbl_cam, stretch=2)

        self.lbl_status = QLabel("Нечего не воспроизводиться")
        self.lbl_status.setAlignment(Qt.AlignmentFlag.AlignLeft)

        outer_layout.addLayout(main_layout)
        outer_layout.addWidget(self.lbl_status)

        self.btn_start.clicked.connect(self.start_broadcast)
        self.btn_stop.clicked.connect(self.stop_broadcast)
        self.btn_folder.clicked.connect(self.select_folder)
        self.btn_refresh.clicked.connect(self.update_video_list)

        self.update_video_list()

    def select_folder(self):
        folder = QFileDialog.getExistingDirectory(self, "Выбрать папку", self.video_folder)
        if folder:
            self.video_folder = folder
            self.update_video_list()

    def update_video_list(self):
        self.combo_video.clear()
        if os.path.exists(self.video_folder):
            extensions = ('.mp4', '.mov')
            files = [f for f in os.listdir(self.video_folder) if f.lower().endswith(extensions)]
            self.combo_video.addItems(files)

    def start_broadcast(self):
        if self.process and self.process.poll() is None:
            return

        filename = self.combo_video.currentText()
        if not filename:
            self.lbl_cam.setText("Файл не выбран")
            return

        video_path = os.path.join(self.video_folder, filename)
        
        self.cap_preview = cv2.VideoCapture(video_path)
        if not self.cap_preview.isOpened():
            self.lbl_cam.setText("Ошибка открытия видео")
            return

        fps = int(self.cap_preview.get(cv2.CAP_PROP_FPS)) or 30

        try:
            interpreter = "python" if sys.platform.startswith("win32") else "python3"
            self.process = subprocess.Popen([interpreter, "main.py", video_path])
            
            self.lbl_status.setText(f"Включенно видео {filename}")
            self.timer.start(int(1000 / fps))
        except Exception:
            self.lbl_cam.setText("Не запущенна виртуальная камера")
            self.lbl_status.setText("Нечего не воспроизводиться")
            if self.cap_preview:
                self.cap_preview.release()

    def stop_broadcast(self):
        self.timer.stop()
        
        if self.process:
            self.process.terminate()
            try:
                self.process.wait(timeout=2)
            except subprocess.TimeoutExpired:
                self.process.kill()
            self.process = None

        if self.cap_preview:
            self.cap_preview.release()
            self.cap_preview = None

        self.lbl_cam.clear()
        self.lbl_cam.setText("Не запущенна виртуальная камера")
        self.lbl_status.setText("Нечего не воспроизводиться")

    def update_preview(self):
        if not self.process or self.process.poll() is not None:
            self.stop_broadcast()
            return

        if not self.cap_preview:
            return

        ret, frame = self.cap_preview.read()
        if not ret:
            self.cap_preview.set(cv2.CAP_PROP_POS_FRAMES, 0)
            return

        frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        h, w, ch = frame_rgb.shape
        bytes_per_line = ch * w
        qt_img = QImage(frame_rgb.data, w, h, bytes_per_line, QImage.Format.Format_RGB888)
        pixmap = QPixmap.fromImage(qt_img)
        self.lbl_cam.setPixmap(pixmap.scaled(self.lbl_cam.size(), 
                                             Qt.AspectRatioMode.KeepAspectRatio, 
                                             Qt.TransformationMode.SmoothTransformation))

    def closeEvent(self, event):
        self.stop_broadcast()
        event.accept()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = VirtualCamGui()
    window.show()
    sys.exit(app.exec())
