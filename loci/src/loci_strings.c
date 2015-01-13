/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#include <loci/loci.h>
#include <loci/of_object.h>
#include "loci_log.h"
#include "loci_int.h"

const char *const of_object_id_str[] = {
    "of_object",
    "of_aggregate_stats_reply",
    "of_aggregate_stats_request",
    "of_async_config_failed_error_msg",
    "of_async_get_reply",
    "of_async_get_request",
    "of_async_set",
    "of_bad_action_error_msg",
    "of_bad_instruction_error_msg",
    "of_bad_match_error_msg",
    "of_bad_property_error_msg",
    "of_bad_request_error_msg",
    "of_barrier_reply",
    "of_barrier_request",
    "of_bsn_arp_idle",
    "of_bsn_bw_clear_data_reply",
    "of_bsn_bw_clear_data_request",
    "of_bsn_bw_enable_get_reply",
    "of_bsn_bw_enable_get_request",
    "of_bsn_bw_enable_set_reply",
    "of_bsn_bw_enable_set_request",
    "of_bsn_controller_connections_reply",
    "of_bsn_controller_connections_request",
    "of_bsn_debug_counter_desc_stats_reply",
    "of_bsn_debug_counter_desc_stats_request",
    "of_bsn_debug_counter_stats_reply",
    "of_bsn_debug_counter_stats_request",
    "of_bsn_flow_checksum_bucket_stats_reply",
    "of_bsn_flow_checksum_bucket_stats_request",
    "of_bsn_flow_idle",
    "of_bsn_flow_idle_enable_get_reply",
    "of_bsn_flow_idle_enable_get_request",
    "of_bsn_flow_idle_enable_set_reply",
    "of_bsn_flow_idle_enable_set_request",
    "of_bsn_generic_stats_reply",
    "of_bsn_generic_stats_request",
    "of_bsn_gentable_bucket_stats_reply",
    "of_bsn_gentable_bucket_stats_request",
    "of_bsn_gentable_clear_reply",
    "of_bsn_gentable_clear_request",
    "of_bsn_gentable_desc_stats_reply",
    "of_bsn_gentable_desc_stats_request",
    "of_bsn_gentable_entry_add",
    "of_bsn_gentable_entry_delete",
    "of_bsn_gentable_entry_desc_stats_reply",
    "of_bsn_gentable_entry_desc_stats_request",
    "of_bsn_gentable_entry_stats_reply",
    "of_bsn_gentable_entry_stats_request",
    "of_bsn_gentable_set_buckets_size",
    "of_bsn_gentable_stats_reply",
    "of_bsn_gentable_stats_request",
    "of_bsn_get_interfaces_reply",
    "of_bsn_get_interfaces_request",
    "of_bsn_get_ip_mask_reply",
    "of_bsn_get_ip_mask_request",
    "of_bsn_get_l2_table_reply",
    "of_bsn_get_l2_table_request",
    "of_bsn_get_mirroring_reply",
    "of_bsn_get_mirroring_request",
    "of_bsn_get_switch_pipeline_reply",
    "of_bsn_get_switch_pipeline_request",
    "of_bsn_header",
    "of_bsn_hybrid_get_reply",
    "of_bsn_hybrid_get_request",
    "of_bsn_image_desc_stats_reply",
    "of_bsn_image_desc_stats_request",
    "of_bsn_lacp_convergence_notif",
    "of_bsn_lacp_stats_reply",
    "of_bsn_lacp_stats_request",
    "of_bsn_log",
    "of_bsn_lua_command_reply",
    "of_bsn_lua_command_request",
    "of_bsn_lua_notification",
    "of_bsn_lua_upload",
    "of_bsn_pdu_rx_reply",
    "of_bsn_pdu_rx_request",
    "of_bsn_pdu_rx_timeout",
    "of_bsn_pdu_tx_reply",
    "of_bsn_pdu_tx_request",
    "of_bsn_port_counter_stats_reply",
    "of_bsn_port_counter_stats_request",
    "of_bsn_role_status",
    "of_bsn_set_aux_cxns_reply",
    "of_bsn_set_aux_cxns_request",
    "of_bsn_set_ip_mask",
    "of_bsn_set_l2_table_reply",
    "of_bsn_set_l2_table_request",
    "of_bsn_set_lacp_reply",
    "of_bsn_set_lacp_request",
    "of_bsn_set_mirroring",
    "of_bsn_set_pktin_suppression_reply",
    "of_bsn_set_pktin_suppression_request",
    "of_bsn_set_switch_pipeline_reply",
    "of_bsn_set_switch_pipeline_request",
    "of_bsn_shell_command",
    "of_bsn_shell_output",
    "of_bsn_shell_status",
    "of_bsn_stats_reply",
    "of_bsn_stats_request",
    "of_bsn_switch_pipeline_stats_reply",
    "of_bsn_switch_pipeline_stats_request",
    "of_bsn_table_checksum_stats_reply",
    "of_bsn_table_checksum_stats_request",
    "of_bsn_table_set_buckets_size",
    "of_bsn_time_reply",
    "of_bsn_time_request",
    "of_bsn_virtual_port_create_reply",
    "of_bsn_virtual_port_create_request",
    "of_bsn_virtual_port_remove_reply",
    "of_bsn_virtual_port_remove_request",
    "of_bsn_vlan_counter_stats_reply",
    "of_bsn_vlan_counter_stats_request",
    "of_bsn_vrf_counter_stats_reply",
    "of_bsn_vrf_counter_stats_request",
    "of_bundle_add_msg",
    "of_bundle_ctrl_msg",
    "of_bundle_failed_error_msg",
    "of_desc_stats_reply",
    "of_desc_stats_request",
    "of_echo_reply",
    "of_echo_request",
    "of_error_msg",
    "of_experimenter",
    "of_experimenter_error_msg",
    "of_experimenter_stats_reply",
    "of_experimenter_stats_request",
    "of_features_reply",
    "of_features_request",
    "of_flow_add",
    "of_flow_delete",
    "of_flow_delete_strict",
    "of_flow_mod",
    "of_flow_mod_failed_error_msg",
    "of_flow_modify",
    "of_flow_modify_strict",
    "of_flow_monitor_failed_error_msg",
    "of_flow_removed",
    "of_flow_stats_reply",
    "of_flow_stats_request",
    "of_get_config_reply",
    "of_get_config_request",
    "of_group_add",
    "of_group_delete",
    "of_group_desc_stats_reply",
    "of_group_desc_stats_request",
    "of_group_features_stats_reply",
    "of_group_features_stats_request",
    "of_group_mod",
    "of_group_mod_failed_error_msg",
    "of_group_modify",
    "of_group_stats_reply",
    "of_group_stats_request",
    "of_header",
    "of_hello",
    "of_hello_failed_error_msg",
    "of_meter_config_stats_reply",
    "of_meter_config_stats_request",
    "of_meter_features_stats_reply",
    "of_meter_features_stats_request",
    "of_meter_mod",
    "of_meter_mod_failed_error_msg",
    "of_meter_stats_reply",
    "of_meter_stats_request",
    "of_nicira_controller_role_reply",
    "of_nicira_controller_role_request",
    "of_nicira_header",
    "of_packet_in",
    "of_packet_out",
    "of_port_desc_stats_reply",
    "of_port_desc_stats_request",
    "of_port_mod",
    "of_port_mod_failed_error_msg",
    "of_port_stats_reply",
    "of_port_stats_request",
    "of_port_status",
    "of_queue_desc_stats_reply",
    "of_queue_desc_stats_request",
    "of_queue_get_config_reply",
    "of_queue_get_config_request",
    "of_queue_op_failed_error_msg",
    "of_queue_stats_reply",
    "of_queue_stats_request",
    "of_requestforward",
    "of_role_reply",
    "of_role_request",
    "of_role_request_failed_error_msg",
    "of_role_status",
    "of_set_config",
    "of_stats_reply",
    "of_stats_request",
    "of_switch_config_failed_error_msg",
    "of_table_desc_stats_reply",
    "of_table_desc_stats_request",
    "of_table_features_failed_error_msg",
    "of_table_features_stats_reply",
    "of_table_features_stats_request",
    "of_table_mod",
    "of_table_mod_failed_error_msg",
    "of_table_stats_reply",
    "of_table_stats_request",
    "of_table_status",
    "of_action",
    "of_action_bsn",
    "of_action_bsn_checksum",
    "of_action_bsn_gentable",
    "of_action_bsn_mirror",
    "of_action_bsn_set_tunnel_dst",
    "of_action_copy_ttl_in",
    "of_action_copy_ttl_out",
    "of_action_dec_mpls_ttl",
    "of_action_dec_nw_ttl",
    "of_action_enqueue",
    "of_action_experimenter",
    "of_action_group",
    "of_action_id",
    "of_action_id_bsn",
    "of_action_id_bsn_checksum",
    "of_action_id_bsn_gentable",
    "of_action_id_bsn_mirror",
    "of_action_id_bsn_set_tunnel_dst",
    "of_action_id_copy_ttl_in",
    "of_action_id_copy_ttl_out",
    "of_action_id_dec_mpls_ttl",
    "of_action_id_dec_nw_ttl",
    "of_action_id_experimenter",
    "of_action_id_group",
    "of_action_id_nicira",
    "of_action_id_nicira_dec_ttl",
    "of_action_id_output",
    "of_action_id_pop_mpls",
    "of_action_id_pop_pbb",
    "of_action_id_pop_vlan",
    "of_action_id_push_mpls",
    "of_action_id_push_pbb",
    "of_action_id_push_vlan",
    "of_action_id_set_field",
    "of_action_id_set_mpls_ttl",
    "of_action_id_set_nw_ttl",
    "of_action_id_set_queue",
    "of_action_nicira",
    "of_action_nicira_dec_ttl",
    "of_action_output",
    "of_action_pop_mpls",
    "of_action_pop_pbb",
    "of_action_pop_vlan",
    "of_action_push_mpls",
    "of_action_push_pbb",
    "of_action_push_vlan",
    "of_action_set_dl_dst",
    "of_action_set_dl_src",
    "of_action_set_field",
    "of_action_set_mpls_label",
    "of_action_set_mpls_tc",
    "of_action_set_mpls_ttl",
    "of_action_set_nw_dst",
    "of_action_set_nw_ecn",
    "of_action_set_nw_src",
    "of_action_set_nw_tos",
    "of_action_set_nw_ttl",
    "of_action_set_queue",
    "of_action_set_tp_dst",
    "of_action_set_tp_src",
    "of_action_set_vlan_pcp",
    "of_action_set_vlan_vid",
    "of_action_strip_vlan",
    "of_async_config_prop",
    "of_async_config_prop_experimenter_master",
    "of_async_config_prop_experimenter_slave",
    "of_async_config_prop_flow_removed_master",
    "of_async_config_prop_flow_removed_slave",
    "of_async_config_prop_packet_in_master",
    "of_async_config_prop_packet_in_slave",
    "of_async_config_prop_port_status_master",
    "of_async_config_prop_port_status_slave",
    "of_async_config_prop_requestforward_master",
    "of_async_config_prop_requestforward_slave",
    "of_async_config_prop_role_status_master",
    "of_async_config_prop_role_status_slave",
    "of_async_config_prop_table_status_master",
    "of_async_config_prop_table_status_slave",
    "of_bsn_controller_connection",
    "of_bsn_debug_counter_desc_stats_entry",
    "of_bsn_debug_counter_stats_entry",
    "of_bsn_flow_checksum_bucket_stats_entry",
    "of_bsn_generic_stats_entry",
    "of_bsn_gentable_bucket_stats_entry",
    "of_bsn_gentable_desc_stats_entry",
    "of_bsn_gentable_entry_desc_stats_entry",
    "of_bsn_gentable_entry_stats_entry",
    "of_bsn_gentable_stats_entry",
    "of_bsn_interface",
    "of_bsn_lacp_stats_entry",
    "of_bsn_port_counter_stats_entry",
    "of_bsn_switch_pipeline_stats_entry",
    "of_bsn_table_checksum_stats_entry",
    "of_bsn_tlv",
    "of_bsn_tlv_actor_key",
    "of_bsn_tlv_actor_port_num",
    "of_bsn_tlv_actor_port_priority",
    "of_bsn_tlv_actor_state",
    "of_bsn_tlv_actor_system_mac",
    "of_bsn_tlv_actor_system_priority",
    "of_bsn_tlv_broadcast_query_timeout",
    "of_bsn_tlv_bucket",
    "of_bsn_tlv_circuit_id",
    "of_bsn_tlv_convergence_status",
    "of_bsn_tlv_crc_enabled",
    "of_bsn_tlv_data",
    "of_bsn_tlv_eth_dst",
    "of_bsn_tlv_eth_src",
    "of_bsn_tlv_external_gateway_ip",
    "of_bsn_tlv_external_gateway_mac",
    "of_bsn_tlv_external_ip",
    "of_bsn_tlv_external_mac",
    "of_bsn_tlv_external_netmask",
    "of_bsn_tlv_header_size",
    "of_bsn_tlv_icmp_code",
    "of_bsn_tlv_icmp_id",
    "of_bsn_tlv_icmp_type",
    "of_bsn_tlv_idle_notification",
    "of_bsn_tlv_idle_time",
    "of_bsn_tlv_idle_timeout",
    "of_bsn_tlv_internal_gateway_mac",
    "of_bsn_tlv_internal_mac",
    "of_bsn_tlv_interval",
    "of_bsn_tlv_ip_proto",
    "of_bsn_tlv_ipv4",
    "of_bsn_tlv_ipv4_dst",
    "of_bsn_tlv_ipv4_netmask",
    "of_bsn_tlv_ipv4_src",
    "of_bsn_tlv_mac",
    "of_bsn_tlv_mac_mask",
    "of_bsn_tlv_miss_packets",
    "of_bsn_tlv_mpls_control_word",
    "of_bsn_tlv_mpls_label",
    "of_bsn_tlv_mpls_sequenced",
    "of_bsn_tlv_name",
    "of_bsn_tlv_partner_key",
    "of_bsn_tlv_partner_port_num",
    "of_bsn_tlv_partner_port_priority",
    "of_bsn_tlv_partner_state",
    "of_bsn_tlv_partner_system_mac",
    "of_bsn_tlv_partner_system_priority",
    "of_bsn_tlv_port",
    "of_bsn_tlv_priority",
    "of_bsn_tlv_queue_id",
    "of_bsn_tlv_queue_weight",
    "of_bsn_tlv_reference",
    "of_bsn_tlv_reply_packets",
    "of_bsn_tlv_request_packets",
    "of_bsn_tlv_rx_packets",
    "of_bsn_tlv_sampling_rate",
    "of_bsn_tlv_sub_agent_id",
    "of_bsn_tlv_tcp_dst",
    "of_bsn_tlv_tcp_src",
    "of_bsn_tlv_tx_bytes",
    "of_bsn_tlv_tx_packets",
    "of_bsn_tlv_udf_anchor",
    "of_bsn_tlv_udf_id",
    "of_bsn_tlv_udf_length",
    "of_bsn_tlv_udf_offset",
    "of_bsn_tlv_udp_dst",
    "of_bsn_tlv_udp_src",
    "of_bsn_tlv_unicast_query_timeout",
    "of_bsn_tlv_vlan_vid",
    "of_bsn_tlv_vrf",
    "of_bsn_vlan_counter_stats_entry",
    "of_bsn_vport",
    "of_bsn_vport_l2gre",
    "of_bsn_vport_q_in_q",
    "of_bsn_vrf_counter_stats_entry",
    "of_bucket",
    "of_bucket_counter",
    "of_bundle_prop",
    "of_bundle_prop_experimenter",
    "of_flow_stats_entry",
    "of_group_desc_stats_entry",
    "of_group_stats_entry",
    "of_hello_elem",
    "of_hello_elem_versionbitmap",
    "of_instruction",
    "of_instruction_apply_actions",
    "of_instruction_bsn",
    "of_instruction_bsn_arp_offload",
    "of_instruction_bsn_auto_negotiation",
    "of_instruction_bsn_deny",
    "of_instruction_bsn_dhcp_offload",
    "of_instruction_bsn_disable_split_horizon_check",
    "of_instruction_bsn_disable_src_mac_check",
    "of_instruction_bsn_disable_vlan_counters",
    "of_instruction_bsn_packet_of_death",
    "of_instruction_bsn_permit",
    "of_instruction_bsn_prioritize_pdus",
    "of_instruction_bsn_require_vlan_xlate",
    "of_instruction_bsn_span_destination",
    "of_instruction_clear_actions",
    "of_instruction_experimenter",
    "of_instruction_goto_table",
    "of_instruction_id",
    "of_instruction_id_apply_actions",
    "of_instruction_id_bsn",
    "of_instruction_id_bsn_arp_offload",
    "of_instruction_id_bsn_auto_negotiation",
    "of_instruction_id_bsn_deny",
    "of_instruction_id_bsn_dhcp_offload",
    "of_instruction_id_bsn_disable_split_horizon_check",
    "of_instruction_id_bsn_disable_src_mac_check",
    "of_instruction_id_bsn_disable_vlan_counters",
    "of_instruction_id_bsn_packet_of_death",
    "of_instruction_id_bsn_permit",
    "of_instruction_id_bsn_prioritize_pdus",
    "of_instruction_id_bsn_require_vlan_xlate",
    "of_instruction_id_bsn_span_destination",
    "of_instruction_id_clear_actions",
    "of_instruction_id_experimenter",
    "of_instruction_id_goto_table",
    "of_instruction_id_meter",
    "of_instruction_id_write_actions",
    "of_instruction_id_write_metadata",
    "of_instruction_meter",
    "of_instruction_write_actions",
    "of_instruction_write_metadata",
    "of_match_v1",
    "of_match_v2",
    "of_match_v3",
    "of_meter_band",
    "of_meter_band_drop",
    "of_meter_band_dscp_remark",
    "of_meter_band_experimenter",
    "of_meter_band_stats",
    "of_meter_config",
    "of_meter_features",
    "of_meter_stats",
    "of_oxm",
    "of_oxm_arp_op",
    "of_oxm_arp_op_masked",
    "of_oxm_arp_sha",
    "of_oxm_arp_sha_masked",
    "of_oxm_arp_spa",
    "of_oxm_arp_spa_masked",
    "of_oxm_arp_tha",
    "of_oxm_arp_tha_masked",
    "of_oxm_arp_tpa",
    "of_oxm_arp_tpa_masked",
    "of_oxm_bsn_egr_port_group_id",
    "of_oxm_bsn_egr_port_group_id_masked",
    "of_oxm_bsn_global_vrf_allowed",
    "of_oxm_bsn_global_vrf_allowed_masked",
    "of_oxm_bsn_in_ports_128",
    "of_oxm_bsn_in_ports_128_masked",
    "of_oxm_bsn_in_ports_512",
    "of_oxm_bsn_in_ports_512_masked",
    "of_oxm_bsn_l2_cache_hit",
    "of_oxm_bsn_l2_cache_hit_masked",
    "of_oxm_bsn_l3_dst_class_id",
    "of_oxm_bsn_l3_dst_class_id_masked",
    "of_oxm_bsn_l3_interface_class_id",
    "of_oxm_bsn_l3_interface_class_id_masked",
    "of_oxm_bsn_l3_src_class_id",
    "of_oxm_bsn_l3_src_class_id_masked",
    "of_oxm_bsn_lag_id",
    "of_oxm_bsn_lag_id_masked",
    "of_oxm_bsn_tcp_flags",
    "of_oxm_bsn_tcp_flags_masked",
    "of_oxm_bsn_udf0",
    "of_oxm_bsn_udf0_masked",
    "of_oxm_bsn_udf1",
    "of_oxm_bsn_udf1_masked",
    "of_oxm_bsn_udf2",
    "of_oxm_bsn_udf2_masked",
    "of_oxm_bsn_udf3",
    "of_oxm_bsn_udf3_masked",
    "of_oxm_bsn_udf4",
    "of_oxm_bsn_udf4_masked",
    "of_oxm_bsn_udf5",
    "of_oxm_bsn_udf5_masked",
    "of_oxm_bsn_udf6",
    "of_oxm_bsn_udf6_masked",
    "of_oxm_bsn_udf7",
    "of_oxm_bsn_udf7_masked",
    "of_oxm_bsn_vlan_xlate_port_group_id",
    "of_oxm_bsn_vlan_xlate_port_group_id_masked",
    "of_oxm_bsn_vrf",
    "of_oxm_bsn_vrf_masked",
    "of_oxm_eth_dst",
    "of_oxm_eth_dst_masked",
    "of_oxm_eth_src",
    "of_oxm_eth_src_masked",
    "of_oxm_eth_type",
    "of_oxm_eth_type_masked",
    "of_oxm_icmpv4_code",
    "of_oxm_icmpv4_code_masked",
    "of_oxm_icmpv4_type",
    "of_oxm_icmpv4_type_masked",
    "of_oxm_icmpv6_code",
    "of_oxm_icmpv6_code_masked",
    "of_oxm_icmpv6_type",
    "of_oxm_icmpv6_type_masked",
    "of_oxm_in_phy_port",
    "of_oxm_in_phy_port_masked",
    "of_oxm_in_port",
    "of_oxm_in_port_masked",
    "of_oxm_ip_dscp",
    "of_oxm_ip_dscp_masked",
    "of_oxm_ip_ecn",
    "of_oxm_ip_ecn_masked",
    "of_oxm_ip_proto",
    "of_oxm_ip_proto_masked",
    "of_oxm_ipv4_dst",
    "of_oxm_ipv4_dst_masked",
    "of_oxm_ipv4_src",
    "of_oxm_ipv4_src_masked",
    "of_oxm_ipv6_dst",
    "of_oxm_ipv6_dst_masked",
    "of_oxm_ipv6_exthdr",
    "of_oxm_ipv6_exthdr_masked",
    "of_oxm_ipv6_flabel",
    "of_oxm_ipv6_flabel_masked",
    "of_oxm_ipv6_nd_sll",
    "of_oxm_ipv6_nd_sll_masked",
    "of_oxm_ipv6_nd_target",
    "of_oxm_ipv6_nd_target_masked",
    "of_oxm_ipv6_nd_tll",
    "of_oxm_ipv6_nd_tll_masked",
    "of_oxm_ipv6_src",
    "of_oxm_ipv6_src_masked",
    "of_oxm_metadata",
    "of_oxm_metadata_masked",
    "of_oxm_mpls_bos",
    "of_oxm_mpls_bos_masked",
    "of_oxm_mpls_label",
    "of_oxm_mpls_label_masked",
    "of_oxm_mpls_tc",
    "of_oxm_mpls_tc_masked",
    "of_oxm_pbb_uca",
    "of_oxm_pbb_uca_masked",
    "of_oxm_sctp_dst",
    "of_oxm_sctp_dst_masked",
    "of_oxm_sctp_src",
    "of_oxm_sctp_src_masked",
    "of_oxm_tcp_dst",
    "of_oxm_tcp_dst_masked",
    "of_oxm_tcp_src",
    "of_oxm_tcp_src_masked",
    "of_oxm_tunnel_id",
    "of_oxm_tunnel_id_masked",
    "of_oxm_tunnel_ipv4_dst",
    "of_oxm_tunnel_ipv4_dst_masked",
    "of_oxm_tunnel_ipv4_src",
    "of_oxm_tunnel_ipv4_src_masked",
    "of_oxm_udp_dst",
    "of_oxm_udp_dst_masked",
    "of_oxm_udp_src",
    "of_oxm_udp_src_masked",
    "of_oxm_vlan_pcp",
    "of_oxm_vlan_pcp_masked",
    "of_oxm_vlan_vid",
    "of_oxm_vlan_vid_masked",
    "of_packet_queue",
    "of_port_desc",
    "of_port_desc_prop",
    "of_port_desc_prop_ethernet",
    "of_port_desc_prop_experimenter",
    "of_port_desc_prop_optical",
    "of_port_mod_prop",
    "of_port_mod_prop_ethernet",
    "of_port_mod_prop_experimenter",
    "of_port_mod_prop_optical",
    "of_port_stats_entry",
    "of_port_stats_prop",
    "of_port_stats_prop_ethernet",
    "of_port_stats_prop_experimenter",
    "of_port_stats_prop_optical",
    "of_queue_desc",
    "of_queue_desc_prop",
    "of_queue_desc_prop_experimenter",
    "of_queue_desc_prop_max_rate",
    "of_queue_desc_prop_min_rate",
    "of_queue_prop",
    "of_queue_prop_experimenter",
    "of_queue_prop_max_rate",
    "of_queue_prop_min_rate",
    "of_queue_stats_entry",
    "of_queue_stats_prop",
    "of_queue_stats_prop_experimenter",
    "of_role_prop",
    "of_role_prop_experimenter",
    "of_table_desc",
    "of_table_feature_prop",
    "of_table_feature_prop_apply_actions",
    "of_table_feature_prop_apply_actions_miss",
    "of_table_feature_prop_apply_setfield",
    "of_table_feature_prop_apply_setfield_miss",
    "of_table_feature_prop_experimenter",
    "of_table_feature_prop_experimenter_miss",
    "of_table_feature_prop_instructions",
    "of_table_feature_prop_instructions_miss",
    "of_table_feature_prop_match",
    "of_table_feature_prop_next_tables",
    "of_table_feature_prop_next_tables_miss",
    "of_table_feature_prop_table_sync_from",
    "of_table_feature_prop_wildcards",
    "of_table_feature_prop_write_actions",
    "of_table_feature_prop_write_actions_miss",
    "of_table_feature_prop_write_setfield",
    "of_table_feature_prop_write_setfield_miss",
    "of_table_features",
    "of_table_mod_prop",
    "of_table_mod_prop_eviction",
    "of_table_mod_prop_experimenter",
    "of_table_mod_prop_vacancy",
    "of_table_stats_entry",
    "of_uint32",
    "of_uint64",
    "of_uint8",
    "of_list_action",
    "of_list_action_id",
    "of_list_async_config_prop",
    "of_list_bsn_controller_connection",
    "of_list_bsn_debug_counter_desc_stats_entry",
    "of_list_bsn_debug_counter_stats_entry",
    "of_list_bsn_flow_checksum_bucket_stats_entry",
    "of_list_bsn_generic_stats_entry",
    "of_list_bsn_gentable_bucket_stats_entry",
    "of_list_bsn_gentable_desc_stats_entry",
    "of_list_bsn_gentable_entry_desc_stats_entry",
    "of_list_bsn_gentable_entry_stats_entry",
    "of_list_bsn_gentable_stats_entry",
    "of_list_bsn_interface",
    "of_list_bsn_lacp_stats_entry",
    "of_list_bsn_port_counter_stats_entry",
    "of_list_bsn_switch_pipeline_stats_entry",
    "of_list_bsn_table_checksum_stats_entry",
    "of_list_bsn_tlv",
    "of_list_bsn_vlan_counter_stats_entry",
    "of_list_bsn_vrf_counter_stats_entry",
    "of_list_bucket",
    "of_list_bucket_counter",
    "of_list_bundle_prop",
    "of_list_flow_stats_entry",
    "of_list_group_desc_stats_entry",
    "of_list_group_stats_entry",
    "of_list_hello_elem",
    "of_list_instruction",
    "of_list_instruction_id",
    "of_list_meter_band",
    "of_list_meter_band_stats",
    "of_list_meter_stats",
    "of_list_oxm",
    "of_list_packet_queue",
    "of_list_port_desc",
    "of_list_port_desc_prop",
    "of_list_port_mod_prop",
    "of_list_port_stats_entry",
    "of_list_port_stats_prop",
    "of_list_queue_desc",
    "of_list_queue_desc_prop",
    "of_list_queue_prop",
    "of_list_queue_stats_entry",
    "of_list_queue_stats_prop",
    "of_list_role_prop",
    "of_list_table_desc",
    "of_list_table_feature_prop",
    "of_list_table_features",
    "of_list_table_mod_prop",
    "of_list_table_stats_entry",
    "of_list_uint32",
    "of_list_uint64",
    "of_list_uint8",
    "of_unknown_object",
};

const char *const of_version_str[] = {
    "Unknown OpenFlow Version",
    "OpenFlow-1.0",
    "OpenFlow-1.1",
    "OpenFlow-1.2"
};

const of_mac_addr_t of_mac_addr_all_ones = {
    {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    }
};
/* Just to be explicit; static duration vars are init'd to 0 */
const of_mac_addr_t of_mac_addr_all_zeros = {
    {
        0, 0, 0, 0, 0, 0
    }
};

const of_ipv6_t of_ipv6_all_ones = {
    {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    }
};
/* Just to be explicit; static duration vars are init'd to 0 */
const of_ipv6_t of_ipv6_all_zeros = {
    {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    }
};

const of_bitmap_512_t of_bitmap_512_all_ones = {
    { -1, -1, -1, -1, -1, -1, -1, -1, }
};

const of_bitmap_512_t of_bitmap_512_all_zeroes;

/** @var of_error_strings
 * The error string map; use abs value to index
 */
const char *const of_error_strings[] = { OF_ERROR_STRINGS };
