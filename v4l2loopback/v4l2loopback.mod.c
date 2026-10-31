#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7a5ffe84, "init_wait_entry" },
	{ 0xc281f1fb, "prepare_to_wait_event" },
	{ 0xd272d446, "schedule" },
	{ 0xb730487b, "finish_wait" },
	{ 0x788f072d, "v4l2_fh_init" },
	{ 0xd3fd0ba0, "v4l2_fh_add" },
	{ 0x1899fa1f, "kobject_uevent_env" },
	{ 0x003f084b, "_dev_warn" },
	{ 0x5a844b26, "__x86_indirect_thunk_rax" },
	{ 0x64fa11da, "v4l2_event_pending" },
	{ 0x1ec601f7, "vmalloc_to_page" },
	{ 0x9c6ed254, "vm_insert_page" },
	{ 0x52c8bf80, "v4l2_format_info" },
	{ 0x0e675b65, "___ratelimit" },
	{ 0x5cb46e6d, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0xd3fd0ba0, "v4l2_fh_del" },
	{ 0xe3116ba9, "v4l2_fh_exit" },
	{ 0xc1cd8d94, "noop_llseek" },
	{ 0x6d6d291d, "nonseekable_open" },
	{ 0xbf62d904, "v4l2_event_unsubscribe" },
	{ 0xe7f8b003, "video_ioctl2" },
	{ 0x5a2322a3, "param_ops_int" },
	{ 0x5a2322a3, "param_array_ops" },
	{ 0x5a2322a3, "param_ops_bool" },
	{ 0x5a2322a3, "param_ops_charp" },
	{ 0xd272d446, "__fentry__" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x217c2bfe, "v4l2_event_queue" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0x8b881dc5, "const_current_task" },
	{ 0xe8213e80, "_printk" },
	{ 0xf1de9e85, "vfree" },
	{ 0x9aa6980d, "mutex_lock" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0xc38cbf46, "device_remove_file" },
	{ 0xa44ac2c6, "v4l2_ctrl_handler_free" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0xe082a81b, "video_unregister_device" },
	{ 0x9a654cdd, "v4l2_device_unregister" },
	{ 0x6b412821, "idr_remove" },
	{ 0x9a8a840e, "idr_find" },
	{ 0xdd6830c7, "sprintf" },
	{ 0x40a621c5, "snprintf" },
	{ 0xbd069841, "kstrtoull" },
	{ 0xd7a59a65, "vzalloc_noprof" },
	{ 0x5af09d8b, "_raw_spin_lock" },
	{ 0x5af09d8b, "_raw_spin_unlock" },
	{ 0x058c185a, "jiffies" },
	{ 0x32feeafc, "mod_timer" },
	{ 0x68a1b6c6, "__wake_up" },
	{ 0xa3b1701a, "v4l2_fill_pixfmt" },
	{ 0x4f9e2bc9, "v4l2_fill_pixfmt_mp" },
	{ 0xe4de56b4, "__ubsan_handle_load_invalid_value" },
	{ 0x5af09d8b, "_raw_spin_lock_bh" },
	{ 0x5af09d8b, "_raw_spin_unlock_bh" },
	{ 0x7057d579, "mutex_lock_killable" },
	{ 0x534ed5f3, "__msecs_to_jiffies" },
	{ 0x7e133bcf, "v4l2_event_subscribe" },
	{ 0xf30181ef, "v4l2_ctrl_subscribe_event" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xc4fee520, "kmalloc_caches" },
	{ 0x4574d0c7, "__kmalloc_cache_noprof" },
	{ 0xb33f96dc, "idr_alloc" },
	{ 0x51adc338, "v4l2_device_register" },
	{ 0x83225b64, "video_device_alloc" },
	{ 0xe082a81b, "video_device_release" },
	{ 0x9aa6980d, "mutex_init_generic" },
	{ 0xe804603d, "__init_waitqueue_head" },
	{ 0x02f9bbf0, "timer_init_key" },
	{ 0x94d6684a, "v4l2_ctrl_handler_init_class" },
	{ 0xc96344c9, "v4l2_ctrl_new_custom" },
	{ 0xa44ac2c6, "v4l2_ctrl_handler_setup" },
	{ 0x68fbce2d, "__video_register_device" },
	{ 0xb26586da, "device_create_file" },
	{ 0x003f084b, "_dev_err" },
	{ 0xe98a2697, "misc_register" },
	{ 0xea5b02be, "idr_for_each" },
	{ 0xfc66744b, "idr_destroy" },
	{ 0x155e60e3, "misc_deregister" },
	{ 0x2352b148, "timer_delete_sync" },
	{ 0x4f1e5fd0, "__list_del_entry_valid_or_report" },
	{ 0xdc352a3b, "__list_add_valid_or_report" },
	{ 0xd7a59a65, "vmalloc_noprof" },
	{ 0x680628e7, "ktime_get_ts64" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x173ec8da, "sscanf" },
	{ 0x4e9f8ddf, "video_devdata" },
	{ 0x7851be11, "__SCT__might_resched" },
	{ 0xfbe7861b, "memcpy" },
	{ 0xe9196a28, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x7a5ffe84,
	0xc281f1fb,
	0xd272d446,
	0xb730487b,
	0x788f072d,
	0xd3fd0ba0,
	0x1899fa1f,
	0x003f084b,
	0x5a844b26,
	0x64fa11da,
	0x1ec601f7,
	0x9c6ed254,
	0x52c8bf80,
	0x0e675b65,
	0x5cb46e6d,
	0xa61fd7aa,
	0xd3fd0ba0,
	0xe3116ba9,
	0xc1cd8d94,
	0x6d6d291d,
	0xbf62d904,
	0xe7f8b003,
	0x5a2322a3,
	0x5a2322a3,
	0x5a2322a3,
	0x5a2322a3,
	0xd272d446,
	0xd272d446,
	0xbd03ed67,
	0x217c2bfe,
	0xd272d446,
	0x90a48d82,
	0x8b881dc5,
	0xe8213e80,
	0xf1de9e85,
	0x9aa6980d,
	0x9aa6980d,
	0xc38cbf46,
	0xa44ac2c6,
	0xcb8b6ec6,
	0xe082a81b,
	0x9a654cdd,
	0x6b412821,
	0x9a8a840e,
	0xdd6830c7,
	0x40a621c5,
	0xbd069841,
	0xd7a59a65,
	0x5af09d8b,
	0x5af09d8b,
	0x058c185a,
	0x32feeafc,
	0x68a1b6c6,
	0xa3b1701a,
	0x4f9e2bc9,
	0xe4de56b4,
	0x5af09d8b,
	0x5af09d8b,
	0x7057d579,
	0x534ed5f3,
	0x7e133bcf,
	0xf30181ef,
	0xbd03ed67,
	0xc4fee520,
	0x4574d0c7,
	0xb33f96dc,
	0x51adc338,
	0x83225b64,
	0xe082a81b,
	0x9aa6980d,
	0xe804603d,
	0x02f9bbf0,
	0x94d6684a,
	0xc96344c9,
	0xa44ac2c6,
	0x68fbce2d,
	0xb26586da,
	0x003f084b,
	0xe98a2697,
	0xea5b02be,
	0xfc66744b,
	0x155e60e3,
	0x2352b148,
	0x4f1e5fd0,
	0xdc352a3b,
	0xd7a59a65,
	0x680628e7,
	0x092a35a2,
	0x092a35a2,
	0x173ec8da,
	0x4e9f8ddf,
	0x7851be11,
	0xfbe7861b,
	0xe9196a28,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"init_wait_entry\0"
	"prepare_to_wait_event\0"
	"schedule\0"
	"finish_wait\0"
	"v4l2_fh_init\0"
	"v4l2_fh_add\0"
	"kobject_uevent_env\0"
	"_dev_warn\0"
	"__x86_indirect_thunk_rax\0"
	"v4l2_event_pending\0"
	"vmalloc_to_page\0"
	"vm_insert_page\0"
	"v4l2_format_info\0"
	"___ratelimit\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"v4l2_fh_del\0"
	"v4l2_fh_exit\0"
	"noop_llseek\0"
	"nonseekable_open\0"
	"v4l2_event_unsubscribe\0"
	"video_ioctl2\0"
	"param_ops_int\0"
	"param_array_ops\0"
	"param_ops_bool\0"
	"param_ops_charp\0"
	"__fentry__\0"
	"__x86_return_thunk\0"
	"__ref_stack_chk_guard\0"
	"v4l2_event_queue\0"
	"__stack_chk_fail\0"
	"__ubsan_handle_out_of_bounds\0"
	"const_current_task\0"
	"_printk\0"
	"vfree\0"
	"mutex_lock\0"
	"mutex_unlock\0"
	"device_remove_file\0"
	"v4l2_ctrl_handler_free\0"
	"kfree\0"
	"video_unregister_device\0"
	"v4l2_device_unregister\0"
	"idr_remove\0"
	"idr_find\0"
	"sprintf\0"
	"snprintf\0"
	"kstrtoull\0"
	"vzalloc_noprof\0"
	"_raw_spin_lock\0"
	"_raw_spin_unlock\0"
	"jiffies\0"
	"mod_timer\0"
	"__wake_up\0"
	"v4l2_fill_pixfmt\0"
	"v4l2_fill_pixfmt_mp\0"
	"__ubsan_handle_load_invalid_value\0"
	"_raw_spin_lock_bh\0"
	"_raw_spin_unlock_bh\0"
	"mutex_lock_killable\0"
	"__msecs_to_jiffies\0"
	"v4l2_event_subscribe\0"
	"v4l2_ctrl_subscribe_event\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"__kmalloc_cache_noprof\0"
	"idr_alloc\0"
	"v4l2_device_register\0"
	"video_device_alloc\0"
	"video_device_release\0"
	"mutex_init_generic\0"
	"__init_waitqueue_head\0"
	"timer_init_key\0"
	"v4l2_ctrl_handler_init_class\0"
	"v4l2_ctrl_new_custom\0"
	"v4l2_ctrl_handler_setup\0"
	"__video_register_device\0"
	"device_create_file\0"
	"_dev_err\0"
	"misc_register\0"
	"idr_for_each\0"
	"idr_destroy\0"
	"misc_deregister\0"
	"timer_delete_sync\0"
	"__list_del_entry_valid_or_report\0"
	"__list_add_valid_or_report\0"
	"vmalloc_noprof\0"
	"ktime_get_ts64\0"
	"_copy_from_user\0"
	"_copy_to_user\0"
	"sscanf\0"
	"video_devdata\0"
	"__SCT__might_resched\0"
	"memcpy\0"
	"module_layout\0"
;

MODULE_INFO(depends, "videodev");


MODULE_INFO(srcversion, "53727100B442476040B3195");
