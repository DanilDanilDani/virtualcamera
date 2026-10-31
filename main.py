import sys
import os
import signal
import cv2
import pyvirtualcam

class BackgroundBroadcaster:
    def __init__(self, video_path):
        self.video_path = video_path
        self.cap = None
        self.vcam = None
        self.running = True
        
        signal.signal(signal.SIGINT, self.handle_exit)
        signal.signal(signal.SIGTERM, self.handle_exit)

    def handle_exit(self, signum, frame):
        self.running = False

    def run(self):
        self.cap = cv2.VideoCapture(self.video_path)
        if not self.cap.isOpened():
            sys.exit(1)

        width = int(self.cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
        fps = int(self.cap.get(cv2.CAP_PROP_FPS)) or 30

        kwargs = {}
        if sys.platform.startswith('linux'):
            kwargs['device'] = '/dev/video10'

        try:
            with pyvirtualcam.Camera(width=width, height=height, fps=fps, **kwargs) as cam:
                while self.running:
                    ret, frame = self.cap.read()
                    
                    if not ret:
                        self.cap.set(cv2.CAP_PROP_POS_FRAMES, 0)
                        continue
                        
                    frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                    cam.send(frame_rgb)
                    cam.sleep_until_next_frame()
        except Exception:
            sys.exit(1)
        finally:
            if self.cap:
                self.cap.release()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(1)
        
    target_video = sys.argv[1]
    broadcaster = BackgroundBroadcaster(target_video)
    broadcaster.run()
