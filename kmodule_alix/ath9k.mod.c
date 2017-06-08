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
	{ 0x63f17cc5, __VMLINUX_SYMBOL_STR(ar9003_paprd_is_done) },
	{ 0x670ed5ec, __VMLINUX_SYMBOL_STR(ath9k_hw_set_txq_props) },
	{ 0x6082fc52, __VMLINUX_SYMBOL_STR(ieee80211_csa_finish) },
	{ 0xe7b9a863, __VMLINUX_SYMBOL_STR(ath9k_hw_init) },
	{ 0x95e4dabf, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xa3a680d6, __VMLINUX_SYMBOL_STR(pci_bus_read_config_byte) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xc7788777, __VMLINUX_SYMBOL_STR(ath9k_cmn_get_channel) },
	{ 0xa17fab59, __VMLINUX_SYMBOL_STR(ath9k_hw_deinit) },
	{ 0x528c709d, __VMLINUX_SYMBOL_STR(simple_read_from_buffer) },
	{ 0xb63835e, __VMLINUX_SYMBOL_STR(devm_ioremap_nocache) },
	{ 0x75c51cfa, __VMLINUX_SYMBOL_STR(ath9k_hw_cfg_output) },
	{ 0x68e2f221, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x2fc2d7d3, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0xbfa10214, __VMLINUX_SYMBOL_STR(mem_map) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x9ce704f3, __VMLINUX_SYMBOL_STR(ar9003_mci_send_wlan_channels) },
	{ 0x41f2adbe, __VMLINUX_SYMBOL_STR(pcim_enable_device) },
	{ 0xa0603c65, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x35cd8d0e, __VMLINUX_SYMBOL_STR(debugfs_create_u8) },
	{ 0xb6b46a7c, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x73fec5a8, __VMLINUX_SYMBOL_STR(ath9k_hw_setantenna) },
	{ 0xd0d8621b, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x619cefe4, __VMLINUX_SYMBOL_STR(ath9k_hw_gen_timer_start) },
	{ 0xdb4e86a1, __VMLINUX_SYMBOL_STR(ath9k_hw_set_gpio) },
	{ 0xe75f7fa2, __VMLINUX_SYMBOL_STR(ath9k_cmn_init_crypto) },
	{ 0xd63be9e9, __VMLINUX_SYMBOL_STR(ieee80211_queue_work) },
	{ 0xded2f9f2, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xd281d53, __VMLINUX_SYMBOL_STR(led_classdev_register) },
	{ 0x582f839a, __VMLINUX_SYMBOL_STR(pcim_iomap_table) },
	{ 0xe23057b, __VMLINUX_SYMBOL_STR(relay_file_operations) },
	{ 0x1ba041ab, __VMLINUX_SYMBOL_STR(ieee80211_csa_is_complete) },
	{ 0x32435cfb, __VMLINUX_SYMBOL_STR(ath9k_hw_numtxpending) },
	{ 0xefd37cc, __VMLINUX_SYMBOL_STR(ar9003_paprd_setup_gain_table) },
	{ 0x2810cd28, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_enable) },
	{ 0x2329d7ea, __VMLINUX_SYMBOL_STR(dma_set_mask) },
	{ 0xa4be36f, __VMLINUX_SYMBOL_STR(ath9k_hw_wait) },
	{ 0x7a610053, __VMLINUX_SYMBOL_STR(ath9k_hw_set_interrupts) },
	{ 0xf45f19b, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0xec455899, __VMLINUX_SYMBOL_STR(ath9k_cmn_get_hw_crypto_keytype) },
	{ 0xbf4f8c28, __VMLINUX_SYMBOL_STR(ath9k_hw_stopdmarecv) },
	{ 0x66cf9428, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_init_mci) },
	{ 0xc15c8611, __VMLINUX_SYMBOL_STR(cfg80211_chandef_create) },
	{ 0x49d746de, __VMLINUX_SYMBOL_STR(ar9003_paprd_enable) },
	{ 0xa283803e, __VMLINUX_SYMBOL_STR(ath9k_hw_getchan_noise) },
	{ 0x2d32fce9, __VMLINUX_SYMBOL_STR(ath_key_delete) },
	{ 0x42e98caf, __VMLINUX_SYMBOL_STR(ath9k_cmn_update_txpow) },
	{ 0x46735e62, __VMLINUX_SYMBOL_STR(ath9k_hw_computetxtime) },
	{ 0xa4eb4eff, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0xe78e8f90, __VMLINUX_SYMBOL_STR(ath9k_hw_disable_interrupts) },
	{ 0x7ef39823, __VMLINUX_SYMBOL_STR(ieee80211_hdrlen) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0x560f87e6, __VMLINUX_SYMBOL_STR(ath9k_hw_bstuck_nfcal) },
	{ 0xa1d462b2, __VMLINUX_SYMBOL_STR(ieee80211_beacon_get_tim) },
	{ 0x143efa3c, __VMLINUX_SYMBOL_STR(ath9k_hw_gpio_get) },
	{ 0xfd485ec8, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xd80eefc5, __VMLINUX_SYMBOL_STR(ath_regd_init) },
	{ 0x4205ad24, __VMLINUX_SYMBOL_STR(cancel_work_sync) },
	{ 0x9d769b50, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xd64546b1, __VMLINUX_SYMBOL_STR(ath9k_hw_gettxbuf) },
	{ 0xdbd3296b, __VMLINUX_SYMBOL_STR(dfs_pattern_detector_init) },
	{ 0xe8858e5b, __VMLINUX_SYMBOL_STR(ieee80211_unregister_hw) },
	{ 0xb7ca8f27, __VMLINUX_SYMBOL_STR(rate_control_send_low) },
	{ 0x593a99b, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x29354c4d, __VMLINUX_SYMBOL_STR(pcie_capability_clear_and_set_word) },
	{ 0x24d7b4eb, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x20ad6287, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x1c1d8ccc, __VMLINUX_SYMBOL_STR(ieee80211_iterate_active_interfaces_atomic) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0xf84e435e, __VMLINUX_SYMBOL_STR(ath_gen_timer_free) },
	{ 0x3d7a9a02, __VMLINUX_SYMBOL_STR(ath9k_hw_setrxfilter) },
	{ 0x9c324271, __VMLINUX_SYMBOL_STR(ath9k_hw_get_txq_props) },
	{ 0x71ab83be, __VMLINUX_SYMBOL_STR(ath9k_hw_releasetxqueue) },
	{ 0xa46ade34, __VMLINUX_SYMBOL_STR(ath9k_hw_reset_tsf) },
	{ 0x98d2eeaa, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x2723008a, __VMLINUX_SYMBOL_STR(wiphy_rfkill_start_polling) },
	{ 0x54efb5d6, __VMLINUX_SYMBOL_STR(cpu_number) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0xf16c110a, __VMLINUX_SYMBOL_STR(ath9k_hw_cfg_gpio_input) },
	{ 0xf2f9e40f, __VMLINUX_SYMBOL_STR(ath9k_hw_kill_interrupts) },
	{ 0x84c905f, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xf8aa4964, __VMLINUX_SYMBOL_STR(relay_switch_subbuf) },
	{ 0xe00dcf79, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0xd59198e0, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x7e1e8a26, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0xac4f072a, __VMLINUX_SYMBOL_STR(ieee80211_stop_queues) },
	{ 0x58f2453d, __VMLINUX_SYMBOL_STR(ieee80211_stop_queue) },
	{ 0x58fa8a98, __VMLINUX_SYMBOL_STR(ieee80211_tx_status) },
	{ 0x3071fca, __VMLINUX_SYMBOL_STR(ath_printk) },
	{ 0x68dfc59f, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xcbf162cc, __VMLINUX_SYMBOL_STR(ath9k_hw_process_rxdesc_edma) },
	{ 0xd9c1f207, __VMLINUX_SYMBOL_STR(ar9003_paprd_populate_single_table) },
	{ 0x165ddc97, __VMLINUX_SYMBOL_STR(debugfs_create_u32) },
	{ 0x1071e4ee, __VMLINUX_SYMBOL_STR(ath9k_hw_setopmode) },
	{ 0x3fa58ef8, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x5d41c87c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x9c19283e, __VMLINUX_SYMBOL_STR(pci_set_master) },
	{ 0xd28bdf93, __VMLINUX_SYMBOL_STR(ath9k_hw_disable) },
	{ 0xd5f2172f, __VMLINUX_SYMBOL_STR(del_timer_sync) },
	{ 0x9394b8b0, __VMLINUX_SYMBOL_STR(ath9k_hw_resettxqueue) },
	{ 0xb9c9ec86, __VMLINUX_SYMBOL_STR(ath_gen_timer_isr) },
	{ 0xafc3377d, __VMLINUX_SYMBOL_STR(ath9k_hw_rxprocdesc) },
	{ 0x9d81e97e, __VMLINUX_SYMBOL_STR(relay_close) },
	{ 0x5e211883, __VMLINUX_SYMBOL_STR(ath9k_hw_gettsf64) },
	{ 0x2bc95bd4, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xfdb746c1, __VMLINUX_SYMBOL_STR(default_llseek) },
	{ 0x1e3f768f, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf97456ea, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0xdfb52242, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x4f8664a7, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_init_2wire) },
	{ 0x37befc70, __VMLINUX_SYMBOL_STR(jiffies_to_msecs) },
	{ 0x1bde9153, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x5f5f3290, __VMLINUX_SYMBOL_STR(ieee80211_free_txskb) },
	{ 0x2b415273, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0xd9f39037, __VMLINUX_SYMBOL_STR(ath9k_hw_set_sta_beacon_timers) },
	{ 0x5152e605, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x47e49752, __VMLINUX_SYMBOL_STR(ar9003_hw_bb_watchdog_dbg_info) },
	{ 0xf0e67d25, __VMLINUX_SYMBOL_STR(ar9003_paprd_create_curve) },
	{ 0x8c332f5d, __VMLINUX_SYMBOL_STR(ieee80211_rate_control_register) },
	{ 0x4f9819ea, __VMLINUX_SYMBOL_STR(ath9k_hw_set_tsfadjust) },
	{ 0xfd54835a, __VMLINUX_SYMBOL_STR(ieee80211_wake_queues) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xaa2caefb, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_disable) },
	{ 0xa617632f, __VMLINUX_SYMBOL_STR(ath9k_hw_getrxfilter) },
	{ 0xb6ed1e53, __VMLINUX_SYMBOL_STR(strncpy) },
	{ 0x9b1fbc54, __VMLINUX_SYMBOL_STR(ath9k_hw_ani_monitor) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
	{ 0x6c2e3320, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x7808fc3b, __VMLINUX_SYMBOL_STR(ath9k_hw_gen_timer_stop) },
	{ 0x6c8ef224, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0x4e2481d5, __VMLINUX_SYMBOL_STR(ath_is_world_regd) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x749f049f, __VMLINUX_SYMBOL_STR(pci_bus_write_config_dword) },
	{ 0x4b5f994c, __VMLINUX_SYMBOL_STR(ieee80211_rx) },
	{ 0xdfea7bba, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0xe0f5dd33, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x48748e70, __VMLINUX_SYMBOL_STR(ath9k_hw_addrxbuf_edma) },
	{ 0x1e6d26a8, __VMLINUX_SYMBOL_STR(strstr) },
	{ 0x8577aaa7, __VMLINUX_SYMBOL_STR(platform_get_resource) },
	{ 0x413011c, __VMLINUX_SYMBOL_STR(ieee80211_find_sta_by_ifaddr) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x8834396c, __VMLINUX_SYMBOL_STR(mod_timer) },
	{ 0xd797ca1d, __VMLINUX_SYMBOL_STR(ath9k_hw_setup_statusring) },
	{ 0x2072ee9b, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x6bbc05ac, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x6acb92cb, __VMLINUX_SYMBOL_STR(device_init_wakeup) },
	{ 0x4f06483f, __VMLINUX_SYMBOL_STR(simple_open) },
	{ 0x14cc292f, __VMLINUX_SYMBOL_STR(wiphy_rfkill_stop_polling) },
	{ 0x95bc8603, __VMLINUX_SYMBOL_STR(debugfs_create_bool) },
	{ 0xff314fdf, __VMLINUX_SYMBOL_STR(request_firmware_nowait) },
	{ 0xdd55d06d, __VMLINUX_SYMBOL_STR(ar9003_mci_get_next_gpm_offset) },
	{ 0xe7cdad9f, __VMLINUX_SYMBOL_STR(ath9k_hw_write_associd) },
	{ 0xa7e048bb, __VMLINUX_SYMBOL_STR(ieee80211_queue_delayed_work) },
	{ 0xdf5f7fdb, __VMLINUX_SYMBOL_STR(dev_kfree_skb_any) },
	{ 0x7ea1c06f, __VMLINUX_SYMBOL_STR(pcim_iomap_regions) },
	{ 0xe523ad75, __VMLINUX_SYMBOL_STR(synchronize_irq) },
	{ 0x5c1274ff, __VMLINUX_SYMBOL_STR(ath_reg_notifier_apply) },
	{ 0xdf762353, __VMLINUX_SYMBOL_STR(ath9k_hw_puttxbuf) },
	{ 0xb1c5162c, __VMLINUX_SYMBOL_STR(wiphy_to_ieee80211_hw) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x8964d1a2, __VMLINUX_SYMBOL_STR(ar9003_mci_state) },
	{ 0xe726193f, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_init_scheme) },
	{ 0xa327038e, __VMLINUX_SYMBOL_STR(ath9k_hw_init_btcoex_hw) },
	{ 0xedf1b022, __VMLINUX_SYMBOL_STR(ieee80211_stop_tx_ba_cb_irqsafe) },
	{ 0xe0fc598a, __VMLINUX_SYMBOL_STR(ath9k_hw_beaconq_setup) },
	{ 0xac3f3ed0, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xaf17a253, __VMLINUX_SYMBOL_STR(ath9k_hw_name) },
	{ 0x8ff4079b, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xec4898f2, __VMLINUX_SYMBOL_STR(ath9k_hw_abortpcurecv) },
	{ 0x64ecfa5e, __VMLINUX_SYMBOL_STR(ath9k_hw_init_global_settings) },
	{ 0x13d21a92, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0xd2981357, __VMLINUX_SYMBOL_STR(ath9k_cmn_count_streams) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0xce7d1d3b, __VMLINUX_SYMBOL_STR(pci_bus_read_config_dword) },
	{ 0xb3d7d83d, __VMLINUX_SYMBOL_STR(ath9k_hw_settsf64) },
	{ 0x8bf826c, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xf0fdf6cb, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x95a8b888, __VMLINUX_SYMBOL_STR(wiphy_rfkill_set_hw_state) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0x9376f2, __VMLINUX_SYMBOL_STR(ieee80211_sta_set_buffered) },
	{ 0x765a15d8, __VMLINUX_SYMBOL_STR(ar9003_mci_get_interrupt) },
	{ 0xbbd1613d, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0x47a5f53a, __VMLINUX_SYMBOL_STR(ath9k_hw_beaconinit) },
	{ 0x6a697a5b, __VMLINUX_SYMBOL_STR(ieee80211_send_bar) },
	{ 0x6215d9a2, __VMLINUX_SYMBOL_STR(ath9k_hw_updatetxtriglevel) },
	{ 0xa19b0fcd, __VMLINUX_SYMBOL_STR(ath_hw_cycle_counters_update) },
	{ 0x6e284070, __VMLINUX_SYMBOL_STR(ar9003_mci_set_bt_version) },
	{ 0xbcc15e55, __VMLINUX_SYMBOL_STR(ath9k_hw_set_rx_bufsize) },
	{ 0x3580abd0, __VMLINUX_SYMBOL_STR(ieee80211_get_tx_rates) },
	{ 0x706e5363, __VMLINUX_SYMBOL_STR(ar9003_is_paprd_enabled) },
	{ 0x54a9db5f, __VMLINUX_SYMBOL_STR(_kstrtoul) },
	{ 0xb21b0081, __VMLINUX_SYMBOL_STR(ar9003_get_pll_sqsum_dvc) },
	{ 0x44eeb3c2, __VMLINUX_SYMBOL_STR(ar9003_mci_send_message) },
	{ 0xe746711d, __VMLINUX_SYMBOL_STR(ieee80211_get_buffered_bc) },
	{ 0x9fdd5d29, __VMLINUX_SYMBOL_STR(ar9003_mci_cleanup) },
	{ 0xd22fec8f, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0x9eadc1cb, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xa0e3066d, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_bt_stomp) },
	{ 0x206cb611, __VMLINUX_SYMBOL_STR(ath9k_hw_txstart) },
	{ 0x327fa09d, __VMLINUX_SYMBOL_STR(ath9k_hw_setrxabort) },
	{ 0x5a1191c2, __VMLINUX_SYMBOL_STR(ath9k_hw_check_alive) },
	{ 0x1ca10556, __VMLINUX_SYMBOL_STR(pci_unregister_driver) },
	{ 0x16f85937, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x67f7403e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xb21dcce7, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_set_concur_txprio) },
	{ 0xbd12af74, __VMLINUX_SYMBOL_STR(ath_hw_setbssidmask) },
	{ 0x21fb443e, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x70c8a41a, __VMLINUX_SYMBOL_STR(ieee80211_wake_queue) },
	{ 0x76a42487, __VMLINUX_SYMBOL_STR(ath9k_hw_phy_disable) },
	{ 0x264150b4, __VMLINUX_SYMBOL_STR(__ieee80211_get_radio_led_name) },
	{ 0xafa9df0, __VMLINUX_SYMBOL_STR(ar9003_mci_setup) },
	{ 0x774fdf23, __VMLINUX_SYMBOL_STR(ieee80211_get_hdrlen_from_skb) },
	{ 0x1d253f88, __VMLINUX_SYMBOL_STR(ieee80211_rate_control_unregister) },
	{ 0x924f9540, __VMLINUX_SYMBOL_STR(ath9k_hw_setpower) },
	{ 0x9c5e6334, __VMLINUX_SYMBOL_STR(ieee80211_sta_eosp) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0xc6bff950, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x1926c1f5, __VMLINUX_SYMBOL_STR(__ieee80211_create_tpt_led_trigger) },
	{ 0x6b2a0496, __VMLINUX_SYMBOL_STR(pci_bus_write_config_byte) },
	{ 0xf03bbed8, __VMLINUX_SYMBOL_STR(led_classdev_unregister) },
	{ 0xbc970931, __VMLINUX_SYMBOL_STR(ieee80211_register_hw) },
	{ 0x714d72af, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x48fd79a2, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_set_weight) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x6235a68f, __VMLINUX_SYMBOL_STR(regulatory_hint) },
	{ 0x69ad2f20, __VMLINUX_SYMBOL_STR(kstrtouint) },
	{ 0x2e60bace, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x23cadbad, __VMLINUX_SYMBOL_STR(ath9k_hw_setmcastfilter) },
	{ 0xa1fc36c4, __VMLINUX_SYMBOL_STR(ieee80211_start_tx_ba_session) },
	{ 0x97409617, __VMLINUX_SYMBOL_STR(ieee80211_alloc_hw) },
	{ 0xe5e63514, __VMLINUX_SYMBOL_STR(ath9k_hw_check_nav) },
	{ 0xee453cb7, __VMLINUX_SYMBOL_STR(ath9k_hw_putrxbuf) },
	{ 0xe9a17cc0, __VMLINUX_SYMBOL_STR(dma_supported) },
	{ 0x78f16667, __VMLINUX_SYMBOL_STR(ath_rxbuf_alloc) },
	{ 0xa3d22839, __VMLINUX_SYMBOL_STR(ar9003_paprd_init_table) },
	{ 0xf5b61b38, __VMLINUX_SYMBOL_STR(__pci_register_driver) },
	{ 0xd1085f64, __VMLINUX_SYMBOL_STR(ath9k_hw_startpcureceive) },
	{ 0x8f2c817a, __VMLINUX_SYMBOL_STR(ath9k_hw_setuprxdesc) },
	{ 0x4e904314, __VMLINUX_SYMBOL_STR(ath9k_hw_setuptxqueue) },
	{ 0xf9e73082, __VMLINUX_SYMBOL_STR(scnprintf) },
	{ 0xf2e8bdec, __VMLINUX_SYMBOL_STR(ath9k_hw_abort_tx_dma) },
	{ 0x7f79223f, __VMLINUX_SYMBOL_STR(ath9k_hw_reset) },
	{ 0xa290dc66, __VMLINUX_SYMBOL_STR(ieee80211_free_hw) },
	{ 0xb108e015, __VMLINUX_SYMBOL_STR(relay_open) },
	{ 0x19a9e62b, __VMLINUX_SYMBOL_STR(complete) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x8235805b, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0xdb10f6ee, __VMLINUX_SYMBOL_STR(ath_gen_timer_alloc) },
	{ 0x68326d58, __VMLINUX_SYMBOL_STR(ath9k_hw_btcoex_init_3wire) },
	{ 0xbc4ee44c, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x13fc08b0, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x81594860, __VMLINUX_SYMBOL_STR(ath_key_config) },
	{ 0x9163a90c, __VMLINUX_SYMBOL_STR(ath9k_hw_enable_interrupts) },
	{ 0x436c2179, __VMLINUX_SYMBOL_STR(iowrite32) },
	{ 0xb61d7a01, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x68dfc1d4, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0xb1d9523e, __VMLINUX_SYMBOL_STR(wait_for_completion_timeout) },
	{ 0xada0952b, __VMLINUX_SYMBOL_STR(ath9k_hw_intrpend) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x47c8baf4, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0x6163519b, __VMLINUX_SYMBOL_STR(ath9k_hw_reset_calvalid) },
	{ 0x5ff5b007, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0x906f67b, __VMLINUX_SYMBOL_STR(release_firmware) },
	{ 0xffbbeafe, __VMLINUX_SYMBOL_STR(ieee80211_start_tx_ba_cb_irqsafe) },
	{ 0x947dcbd9, __VMLINUX_SYMBOL_STR(dma_ops) },
	{ 0xe484e35f, __VMLINUX_SYMBOL_STR(ioread32) },
	{ 0xafbe7f75, __VMLINUX_SYMBOL_STR(device_set_wakeup_enable) },
	{ 0xd5c3f95f, __VMLINUX_SYMBOL_STR(pcie_capability_read_word) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0xb47f78db, __VMLINUX_SYMBOL_STR(dmam_alloc_coherent) },
	{ 0xa66d1bdd, __VMLINUX_SYMBOL_STR(ath9k_hw_set_txpowerlimit) },
	{ 0x4b7982fc, __VMLINUX_SYMBOL_STR(ath9k_hw_stop_dma_queue) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=ath9k_hw,mac80211,ath9k_common,cfg80211,ath";

MODULE_ALIAS("pci:v0000168Cd00000023sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000027sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000029sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv00001A3Bsd00001C71bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv0000105Bsd0000E01Fbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv000011ADsd00006632bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv000011ADsd00006642bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv00001A32sd00000306bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv0000185Fsd0000309Dbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv000010CFsd0000147Cbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv000010CFsd0000147Dbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Asv000010CFsd00001536bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Bsv00001A3Bsd00002C37bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd0000002Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000030sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00002086bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00001237bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00002126bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd0000126Abc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00002152bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000105Bsd0000E075bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000168Csd00003119bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000168Csd00003122bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000185Fsd00003119bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000185Fsd00003027bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd00004105bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd00004106bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000410Dbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000410Ebc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000410Fbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000C706bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000C680bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Dsd0000C708bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv000017AAsd00003218bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv000017AAsd00003219bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00002C97bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00002100bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001C56sd00004001bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv000011ADsd00006627bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv000011ADsd00006628bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000105Bsd0000E04Ebc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000105Bsd0000E04Fbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv0000144Fsd00007197bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001B9Asd00002000bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001B9Asd00002001bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00001186bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00001F86bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00001195bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001A3Bsd00001F95bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001B9Asd00001C00bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001B9Asd00001C01bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv00001043sd0000850Dbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000033sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv00001A3Bsd00002116bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000011ADsd00006661bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv0000168Csd00003117bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000017AAsd00003214bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv00001969sd00000091bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv00001A3Bsd00002110bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv00001043sd0000850Ebc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000011ADsd00006631bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000011ADsd00006641bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv0000103Csd00001864bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000014CDsd00000063bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000014CDsd00000064bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv000010CFsd00001783bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000037sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd00003028bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001A3Bsd00002176bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000105Bsd0000E068bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000185Fsd0000A119bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000632bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00006671bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001B9Asd00002811bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001B9Asd00002812bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd00003025bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd00003026bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd0000302Bbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000105Bsd0000E069bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000185Fsd00003028bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000622bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000672bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000662bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001A3Bsd0000213Abc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000017AAsd00003026bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000103Csd000018E3bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000103Csd0000217Fbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001028sd0000020Ebc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Dsd0000411Abc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Dsd0000411Bbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Dsd0000411Cbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Dsd0000411Dbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Dsd0000411Ebc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd00003027bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000168Csd0000302Cbc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000642bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000652bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv000011ADsd00000612bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001A3Bsd00002130bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000144Fsd00007202bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv00001B9Asd00002810bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv0000185Fsd00003027bc*sc*i*");
MODULE_ALIAS("pci:v0000168Cd00000036sv*sd*bc*sc*i*");
MODULE_ALIAS("platform:ath9k");
MODULE_ALIAS("platform:ar933x_wmac");
MODULE_ALIAS("platform:ar934x_wmac");
MODULE_ALIAS("platform:qca955x_wmac");

MODULE_INFO(srcversion, "AB95C24779EC8BF68CCF297");
