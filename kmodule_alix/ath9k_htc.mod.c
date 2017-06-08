#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xffef374e, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x670ed5ec, __VMLINUX_SYMBOL_STR(ath9k_hw_set_txq_props) },
	{ 0xe7b9a863, __VMLINUX_SYMBOL_STR(ath9k_hw_init) },
	{ 0x95e4dabf, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xc7788777, __VMLINUX_SYMBOL_STR(ath9k_cmn_get_channel) },
	{ 0xa17fab59, __VMLINUX_SYMBOL_STR(ath9k_hw_deinit) },
	{ 0x528c709d, __VMLINUX_SYMBOL_STR(simple_read_from_buffer) },
	{ 0x75c51cfa, __VMLINUX_SYMBOL_STR(ath9k_hw_cfg_output) },
	{ 0x68e2f221, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x2fc2d7d3, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x661bb108, __VMLINUX_SYMBOL_STR(device_release_driver) },
	{ 0xdb4e86a1, __VMLINUX_SYMBOL_STR(ath9k_hw_set_gpio) },
	{ 0xe75f7fa2, __VMLINUX_SYMBOL_STR(ath9k_cmn_init_crypto) },
	{ 0xd63be9e9, __VMLINUX_SYMBOL_STR(ieee80211_queue_work) },
	{ 0xded2f9f2, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xd281d53, __VMLINUX_SYMBOL_STR(led_classdev_register) },
	{ 0x2810cd28, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_enable) },
	{ 0xa4be36f, __VMLINUX_SYMBOL_STR(ath9k_hw_wait) },
	{ 0xec455899, __VMLINUX_SYMBOL_STR(ath9k_cmn_get_hw_crypto_keytype) },
	{ 0xbf4f8c28, __VMLINUX_SYMBOL_STR(ath9k_hw_stopdmarecv) },
	{ 0x2d32fce9, __VMLINUX_SYMBOL_STR(ath_key_delete) },
	{ 0x42e98caf, __VMLINUX_SYMBOL_STR(ath9k_cmn_update_txpow) },
	{ 0xa4eb4eff, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x7ef39823, __VMLINUX_SYMBOL_STR(ieee80211_hdrlen) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0xa1d462b2, __VMLINUX_SYMBOL_STR(ieee80211_beacon_get_tim) },
	{ 0x143efa3c, __VMLINUX_SYMBOL_STR(ath9k_hw_gpio_get) },
	{ 0xd80eefc5, __VMLINUX_SYMBOL_STR(ath_regd_init) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x55b887de, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xe2fae716, __VMLINUX_SYMBOL_STR(kmemdup) },
	{ 0xe8858e5b, __VMLINUX_SYMBOL_STR(ieee80211_unregister_hw) },
	{ 0xeae3dfd6, __VMLINUX_SYMBOL_STR(__const_udelay) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x24d7b4eb, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x20ad6287, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x1c1d8ccc, __VMLINUX_SYMBOL_STR(ieee80211_iterate_active_interfaces_atomic) },
	{ 0x3d7a9a02, __VMLINUX_SYMBOL_STR(ath9k_hw_setrxfilter) },
	{ 0x9c324271, __VMLINUX_SYMBOL_STR(ath9k_hw_get_txq_props) },
	{ 0x71ab83be, __VMLINUX_SYMBOL_STR(ath9k_hw_releasetxqueue) },
	{ 0xa46ade34, __VMLINUX_SYMBOL_STR(ath9k_hw_reset_tsf) },
	{ 0x98d2eeaa, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x2723008a, __VMLINUX_SYMBOL_STR(wiphy_rfkill_start_polling) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x7e1e8a26, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0xac4f072a, __VMLINUX_SYMBOL_STR(ieee80211_stop_queues) },
	{ 0x44e82500, __VMLINUX_SYMBOL_STR(usb_unanchor_urb) },
	{ 0x128a5cf9, __VMLINUX_SYMBOL_STR(complete_all) },
	{ 0xcc7b55ae, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0x58fa8a98, __VMLINUX_SYMBOL_STR(ieee80211_tx_status) },
	{ 0x3071fca, __VMLINUX_SYMBOL_STR(ath_printk) },
	{ 0x68dfc59f, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x1071e4ee, __VMLINUX_SYMBOL_STR(ath9k_hw_setopmode) },
	{ 0x3fa58ef8, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0xd28bdf93, __VMLINUX_SYMBOL_STR(ath9k_hw_disable) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0x9394b8b0, __VMLINUX_SYMBOL_STR(ath9k_hw_resettxqueue) },
	{ 0x5e211883, __VMLINUX_SYMBOL_STR(ath9k_hw_gettsf64) },
	{ 0xfdb746c1, __VMLINUX_SYMBOL_STR(default_llseek) },
	{ 0x1e3f768f, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf97456ea, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x4ca1a6ac, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x1bde9153, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd9f39037, __VMLINUX_SYMBOL_STR(ath9k_hw_set_sta_beacon_timers) },
	{ 0x4f9819ea, __VMLINUX_SYMBOL_STR(ath9k_hw_set_tsfadjust) },
	{ 0xfd54835a, __VMLINUX_SYMBOL_STR(ieee80211_wake_queues) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xaa2caefb, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_disable) },
	{ 0xa617632f, __VMLINUX_SYMBOL_STR(ath9k_hw_getrxfilter) },
	{ 0x9b1fbc54, __VMLINUX_SYMBOL_STR(ath9k_hw_ani_monitor) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
	{ 0xd1111dae, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0x6c2e3320, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x4e2481d5, __VMLINUX_SYMBOL_STR(ath_is_world_regd) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x4b5f994c, __VMLINUX_SYMBOL_STR(ieee80211_rx) },
	{ 0xdfea7bba, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xe0f5dd33, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x4c1182cb, __VMLINUX_SYMBOL_STR(bitmap_scnprintf) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x8834396c, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0x6bbc05ac, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x4f06483f, __VMLINUX_SYMBOL_STR(simple_open) },
	{ 0x14cc292f, __VMLINUX_SYMBOL_STR(wiphy_rfkill_stop_polling) },
	{ 0xff314fdf, __VMLINUX_SYMBOL_STR(request_firmware_nowait) },
	{ 0xe7cdad9f, __VMLINUX_SYMBOL_STR(ath9k_hw_write_associd) },
	{ 0xa7e048bb, __VMLINUX_SYMBOL_STR(ieee80211_queue_delayed_work) },
	{ 0xdf5f7fdb, __VMLINUX_SYMBOL_STR(dev_kfree_skb_any) },
	{ 0xf11543ff, __VMLINUX_SYMBOL_STR(find_first_zero_bit) },
	{ 0x5c1274ff, __VMLINUX_SYMBOL_STR(ath_reg_notifier_apply) },
	{ 0xb1c5162c, __VMLINUX_SYMBOL_STR(wiphy_to_ieee80211_hw) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0xa327038e, __VMLINUX_SYMBOL_STR(ath9k_hw_init_btcoex_hw) },
	{ 0xedf1b022, __VMLINUX_SYMBOL_STR(ieee80211_stop_tx_ba_cb_irqsafe) },
	{ 0x9d13ee97, __VMLINUX_SYMBOL_STR(skb_queue_tail) },
	{ 0xe0fc598a, __VMLINUX_SYMBOL_STR(ath9k_hw_beaconq_setup) },
	{ 0xac3f3ed0, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xf2cfc292, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xaf17a253, __VMLINUX_SYMBOL_STR(ath9k_hw_name) },
	{ 0x64ecfa5e, __VMLINUX_SYMBOL_STR(ath9k_hw_init_global_settings) },
	{ 0x13d21a92, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0xcdaefae9, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0xaea68a11, __VMLINUX_SYMBOL_STR(usb_kill_anchored_urbs) },
	{ 0xd2981357, __VMLINUX_SYMBOL_STR(ath9k_cmn_count_streams) },
	{ 0xb3d7d83d, __VMLINUX_SYMBOL_STR(ath9k_hw_settsf64) },
	{ 0x8bf826c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x95a8b888, __VMLINUX_SYMBOL_STR(wiphy_rfkill_set_hw_state) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0x355e1aac, __VMLINUX_SYMBOL_STR(usb_bulk_msg) },
	{ 0x2645b018, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0x86a4889a, __VMLINUX_SYMBOL_STR(kmalloc_order_trace) },
	{ 0xbbd1613d, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x47a5f53a, __VMLINUX_SYMBOL_STR(ath9k_hw_beaconinit) },
	{ 0x54a9db5f, __VMLINUX_SYMBOL_STR(_kstrtoul) },
	{ 0x5fa1598, __VMLINUX_SYMBOL_STR(ieee80211_find_sta) },
	{ 0xe746711d, __VMLINUX_SYMBOL_STR(ieee80211_get_buffered_bc) },
	{ 0xf8d46b74, __VMLINUX_SYMBOL_STR(usb_interrupt_msg) },
	{ 0xa0e3066d, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_bt_stomp) },
	{ 0x327fa09d, __VMLINUX_SYMBOL_STR(ath9k_hw_setrxabort) },
	{ 0x16f85937, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x67f7403e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xbd12af74, __VMLINUX_SYMBOL_STR(ath_hw_setbssidmask) },
	{ 0x21fb443e, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x76a42487, __VMLINUX_SYMBOL_STR(ath9k_hw_phy_disable) },
	{ 0x774fdf23, __VMLINUX_SYMBOL_STR(ieee80211_get_hdrlen_from_skb) },
	{ 0x924f9540, __VMLINUX_SYMBOL_STR(ath9k_hw_setpower) },
	{ 0x1926c1f5, __VMLINUX_SYMBOL_STR(__ieee80211_create_tpt_led_trigger) },
	{ 0xbc970931, __VMLINUX_SYMBOL_STR(ieee80211_register_hw) },
	{ 0xf03bbed8, __VMLINUX_SYMBOL_STR(led_classdev_unregister) },
	{ 0x48fd79a2, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_set_weight) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x6235a68f, __VMLINUX_SYMBOL_STR(regulatory_hint) },
	{ 0x2e60bace, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x23cadbad, __VMLINUX_SYMBOL_STR(ath9k_hw_setmcastfilter) },
	{ 0xa1fc36c4, __VMLINUX_SYMBOL_STR(ieee80211_start_tx_ba_session) },
	{ 0x97409617, __VMLINUX_SYMBOL_STR(ieee80211_alloc_hw) },
	{ 0xd1085f64, __VMLINUX_SYMBOL_STR(ath9k_hw_startpcureceive) },
	{ 0x4e904314, __VMLINUX_SYMBOL_STR(ath9k_hw_setuptxqueue) },
	{ 0xf9e73082, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0x2b367561, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x18424155, __VMLINUX_SYMBOL_STR(request_firmware) },
	{ 0x7f79223f, __VMLINUX_SYMBOL_STR(ath9k_hw_reset) },
	{ 0xa290dc66, __VMLINUX_SYMBOL_STR(ieee80211_free_hw) },
	{ 0x4cbbd171, __VMLINUX_SYMBOL_STR(__bitmap_weight) },
	{ 0xec2a6c8e, __VMLINUX_SYMBOL_STR(skb_dequeue) },
	{ 0x56fe732, __VMLINUX_SYMBOL_STR(usb_ifnum_to_if) },
	{ 0x19a9e62b, __VMLINUX_SYMBOL_STR(complete) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x8235805b, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x68326d58, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_init_3wire) },
	{ 0x81594860, __VMLINUX_SYMBOL_STR(ath_key_config) },
	{ 0xb61d7a01, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xb1d9523e, __VMLINUX_SYMBOL_STR(wait_for_completion_timeout) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x6163519b, __VMLINUX_SYMBOL_STR(ath9k_hw_reset_calvalid) },
	{ 0x5ff5b007, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xfc87ad21, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x906f67b, __VMLINUX_SYMBOL_STR(release_firmware) },
	{ 0xffbbeafe, __VMLINUX_SYMBOL_STR(ieee80211_start_tx_ba_cb_irqsafe) },
	{ 0x114bc0fb, __VMLINUX_SYMBOL_STR(usb_anchor_urb) },
	{ 0xd4aedb4c, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=ath9k_hw,ath9k_common,mac80211,ath,cfg80211";

MODULE_ALIAS("usb:v0CF3p9271d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3p1006d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p9030d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07D1p3A10d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3327d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3328d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3346d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3348d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3349d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3350d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04CAp4605d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v040Dp3801d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3pB003d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3pB002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v057Cp8403d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3p7015d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1668p1200d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3p7010d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p9018d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v083ApA704d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p017Fd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04DAp3904d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0CF3p20FFd*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "76D0CC269ACAA11EA825B93");
