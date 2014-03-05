/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */

/****************************************************************
 * File: loci.h
 *
 * DO NOT EDIT
 *
 * This file is automatically generated
 *
 ****************************************************************/


#if !defined(_LOCI_H_)
#define _LOCI_H_


#include <loci/loci_base.h>
#include <loci/of_message.h>
#include <loci/of_match.h>
#include <loci/of_object.h>
#include <loci/loci_classes.h>

/****************************************************************
 *
 * This file is divided into the following sections.
 *
 * A few object specific macros
 * Class typedefs (no struct definitions)
 * Per-data type accessor function typedefs
 * Per-class new/delete function typedefs
 * Per-class static delete functions
 * Per-class, per-member accessor declarations
 * Per-class structure definitions
 * Generic union (inheritance) definitions
 * Pointer set function declarations
 * Some special case macros
 *
 ****************************************************************/


typedef enum loci_log_level {
    LOCI_LOG_LEVEL_TRACE,
    LOCI_LOG_LEVEL_VERBOSE,
    LOCI_LOG_LEVEL_INFO,
    LOCI_LOG_LEVEL_WARN,
    LOCI_LOG_LEVEL_ERROR,
    LOCI_LOG_LEVEL_MSG
} loci_log_level_t;

/**
 * @brief Output a log message.
 * @param level The log level.
 * @param fname The function name.
 * @param file The file name.
 * @param line The line number.
 * @param format The message format string.
 */
typedef int (*loci_logger_f)(loci_log_level_t level,
                             const char *fname, const char *file, int line,
                             const char *format, ...);

/*
 * This variable should be set by the user of the library to redirect logs to
 * their log infrastructure. The default drops all logs.
 */
extern loci_logger_f loci_logger;

/**
 * Map a generic object to the underlying wire buffer
 *
 * Treat as private
 */
#define OF_OBJECT_TO_MESSAGE(obj) \
    ((of_message_t)(WBUF_BUF((obj)->wire_object.wbuf)))

/**
 * Macro for the fixed length part of an object
 *
 * @param obj The object whose extended length is being calculated
 * @returns length in bytes of non-variable part of the object
 */
#define OF_OBJECT_FIXED_LENGTH(obj) \
    (of_object_fixed_len[(obj)->version][(obj)->object_id])

/**
 * Return the length of the object beyond its fixed length
 *
 * @param obj The object whose extended length is being calculated
 * @returns length in bytes of non-variable part of the object
 *
 * Most variable length fields are alone at the end of a structure.
 * Their length is a simple calculation, just the total length of
 * the parent minus the length of the non-variable part of the
 * parent's class type.
 */

#define OF_OBJECT_VARIABLE_LENGTH(obj) \
    ((obj)->length - OF_OBJECT_FIXED_LENGTH(obj))

/* FIXME: Where do these go? */
/* Low level maps btwn wire version + type and object ids */
extern int of_message_is_stats_request(int type, int w_ver);
extern int of_message_is_stats_reply(int type, int w_ver);
extern int of_message_stats_reply_to_object_id(int stats_type, int w_ver);
extern int of_message_stats_request_to_object_id(int stats_type, int w_ver);
extern int of_message_type_to_object_id(int type, int w_ver);

extern int of_wire_buffer_of_match_get(of_object_t *obj, int offset,
                                    of_match_t *match);
extern int of_wire_buffer_of_match_set(of_object_t *obj, int offset,
                                    of_match_t *match, int cur_len);

/****************************************************************
 * Functions for objects that can be initialized by a flow add message.
 * These are defined in a non-autogenerated file
 ****************************************************************/

/**
 * @brief Set up a flow removed message from the original add
 * @param obj The flow removed message being updated
 * @param flow_add The flow_add message to use
 *
 * Initialize the following fields of obj to be identical
 * to what was originally on the wire from the flow_add object:
 *     match
 *     cookie
 *     priority
 *     idle_timeout
 *     hard_timeout
 *
 */

extern int
of_flow_removed_setup_from_flow_add(of_flow_removed_t *obj,
                                    of_flow_add_t *flow_add);


/**
 * @brief Set up the packet in match structure from the original add
 * @param obj The packet in message being updated
 * @param flow_add The flow_add message to use
 * @returns Indigo error code.  Does not return a version error if
 * the version does not require initializing obj.
 *
 * Initialize the match member of obj to be identical to what was originally
 * on the wire from the flow_add object.  If applicable, the table ID is also
 * initialized from the flow_add object.
 *
 * This API applies to 1.2 and later only.
 */

extern int
of_packet_in_setup_from_flow_add(of_packet_in_t *obj,
                                 of_flow_add_t *flow_add);


/**
 * @brief Set up the flow stats entry from the original add
 * @param obj The packet in message being updated
 * @param flow_add The flow_add message to use
 * @param effects Optional actions or instructions; see below.
 *
 * Initialize the following fields of obj to be identical
 * to what was originally on the wire from the flow_add object:
 *     match
 *     actions/instructions (effects)
 *     cookie
 *     priority
 *     idle_timeout
 *     hard_timeout
 *
 * Note that the actions/instructions of a flow may be modified by a
 * subsequent flow modify message.  To facilitate implementations,
 * the "effects" parameter is provided.  If effects is NULL, the
 * actions/instructions are taken from the flow_add message.
 * Otherwise, effects is coerced to the proper type (actions or
 * instructions) and used to init obj.
 */

extern int
of_flow_stats_entry_setup_from_flow_add(of_flow_stats_entry_t *obj,
                                        of_flow_add_t *flow_add,
                                        of_object_t *effects);

/****************************************************************
 *
 * Declarations of maps between on-the-wire type values and LOCI identifiers
 *
 ****************************************************************/

/**
 * Generic experimenter type value.  Applies to all except
 * top level message: Action, instruction, error, stats, queue_props, oxm
 */
#define OF_EXPERIMENTER_TYPE 0xffff

int of_experimenter_stats_request_to_object_id(uint32_t experimenter, uint32_t subtype, int ver);
int of_experimenter_stats_reply_to_object_id(uint32_t experimenter, uint32_t subtype, int ver);

of_object_id_t of_action_to_object_id(int action, of_version_t version);
of_object_id_t of_action_id_to_object_id(int action_id, of_version_t version);
of_object_id_t of_instruction_to_object_id(int instruction, of_version_t version);
of_object_id_t of_instruction_id_to_object_id(int instruction, of_version_t version);
of_object_id_t of_queue_prop_to_object_id(int queue_prop, of_version_t version);
of_object_id_t of_table_feature_prop_to_object_id(int table_feature_prop, of_version_t version);
of_object_id_t of_meter_band_to_object_id(int meter_band, of_version_t version);
of_object_id_t of_hello_elem_to_object_id(int hello_elem, of_version_t version);
of_object_id_t of_stats_reply_to_object_id(int stats_reply, of_version_t version);
of_object_id_t of_stats_request_to_object_id(int stats_request, of_version_t version);
of_object_id_t of_error_msg_to_object_id(uint16_t error_msg, of_version_t version);
of_object_id_t of_flow_mod_to_object_id(int flow_mod, of_version_t version);
of_object_id_t of_group_mod_to_object_id(int group_mod, of_version_t version);
of_object_id_t of_oxm_to_object_id(uint32_t type_len, of_version_t version);
of_object_id_t of_message_experimenter_to_object_id(of_message_t msg, of_version_t version);
of_object_id_t of_message_to_object_id(of_message_t msg, int length);
of_object_id_t of_bsn_tlv_to_object_id(int tlv_type, of_version_t version);

int of_object_wire_init(of_object_t *obj, of_object_id_t base_object_id, int max_len);

extern const int *const of_object_fixed_len[OF_VERSION_ARRAY_MAX];
extern const int *const of_object_extra_len[OF_VERSION_ARRAY_MAX];

/****************************************************************
 *
 * The following declarations are for type and length calculations.
 * Implementations may be found in of_type_maps.c
 *
 ****************************************************************/
/*
 * Special case length functions for objects with
 */

/**
 * Special length calculation for of_packet_out->data.
 * @param obj An object of type of_packet_out to check for
 * length of data
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is actions.
 */
extern int of_length_packet_out_data_get(
    of_packet_out_t *obj, int *bytes);

/**
 * Special offset calculation for of_packet_out->data.
 * @param obj An object of type of_packet_out to check for
 * length of data
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is actions.
 */
extern int of_offset_packet_out_data_get(
    of_packet_out_t *obj, int *offset);

/**
 * Special length calculation for of_flow_delete_strict->instructions.
 * @param obj An object of type of_flow_delete_strict to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_delete_strict_instructions_get(
    of_flow_delete_strict_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_delete_strict->instructions.
 * @param obj An object of type of_flow_delete_strict to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_delete_strict_instructions_get(
    of_flow_delete_strict_t *obj, int *offset);

/**
 * Special length calculation for of_flow_stats_entry->instructions.
 * @param obj An object of type of_flow_stats_entry to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_stats_entry_instructions_get(
    of_flow_stats_entry_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_stats_entry->instructions.
 * @param obj An object of type of_flow_stats_entry to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_stats_entry_instructions_get(
    of_flow_stats_entry_t *obj, int *offset);

/**
 * Special length calculation for of_packet_in->data.
 * @param obj An object of type of_packet_in to check for
 * length of data
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is pad.
 */
extern int of_length_packet_in_data_get(
    of_packet_in_t *obj, int *bytes);

/**
 * Special offset calculation for of_packet_in->data.
 * @param obj An object of type of_packet_in to check for
 * length of data
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is pad.
 */
extern int of_offset_packet_in_data_get(
    of_packet_in_t *obj, int *offset);

/**
 * Special length calculation for of_flow_modify_strict->instructions.
 * @param obj An object of type of_flow_modify_strict to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_modify_strict_instructions_get(
    of_flow_modify_strict_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_modify_strict->instructions.
 * @param obj An object of type of_flow_modify_strict to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_modify_strict_instructions_get(
    of_flow_modify_strict_t *obj, int *offset);

/**
 * Special length calculation for of_flow_modify->instructions.
 * @param obj An object of type of_flow_modify to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_modify_instructions_get(
    of_flow_modify_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_modify->instructions.
 * @param obj An object of type of_flow_modify to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_modify_instructions_get(
    of_flow_modify_t *obj, int *offset);

/**
 * Special length calculation for of_bsn_gentable_entry_add->value.
 * @param obj An object of type of_bsn_gentable_entry_add to check for
 * length of value
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_length_bsn_gentable_entry_add_value_get(
    of_bsn_gentable_entry_add_t *obj, int *bytes);

/**
 * Special offset calculation for of_bsn_gentable_entry_add->value.
 * @param obj An object of type of_bsn_gentable_entry_add to check for
 * length of value
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_offset_bsn_gentable_entry_add_value_get(
    of_bsn_gentable_entry_add_t *obj, int *offset);

/**
 * Special length calculation for of_bsn_gentable_entry_stats_entry->stats.
 * @param obj An object of type of_bsn_gentable_entry_stats_entry to check for
 * length of stats
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_length_bsn_gentable_entry_stats_entry_stats_get(
    of_bsn_gentable_entry_stats_entry_t *obj, int *bytes);

/**
 * Special offset calculation for of_bsn_gentable_entry_stats_entry->stats.
 * @param obj An object of type of_bsn_gentable_entry_stats_entry to check for
 * length of stats
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_offset_bsn_gentable_entry_stats_entry_stats_get(
    of_bsn_gentable_entry_stats_entry_t *obj, int *offset);

/**
 * Special length calculation for of_flow_delete->instructions.
 * @param obj An object of type of_flow_delete to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_delete_instructions_get(
    of_flow_delete_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_delete->instructions.
 * @param obj An object of type of_flow_delete to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_delete_instructions_get(
    of_flow_delete_t *obj, int *offset);

/**
 * Special length calculation for of_bsn_gentable_entry_desc_stats_entry->value.
 * @param obj An object of type of_bsn_gentable_entry_desc_stats_entry to check for
 * length of value
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_length_bsn_gentable_entry_desc_stats_entry_value_get(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int *bytes);

/**
 * Special offset calculation for of_bsn_gentable_entry_desc_stats_entry->value.
 * @param obj An object of type of_bsn_gentable_entry_desc_stats_entry to check for
 * length of value
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is key.
 */
extern int of_offset_bsn_gentable_entry_desc_stats_entry_value_get(
    of_bsn_gentable_entry_desc_stats_entry_t *obj, int *offset);

/**
 * Special length calculation for of_flow_mod->instructions.
 * @param obj An object of type of_flow_mod to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_mod_instructions_get(
    of_flow_mod_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_mod->instructions.
 * @param obj An object of type of_flow_mod to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_mod_instructions_get(
    of_flow_mod_t *obj, int *offset);

/**
 * Special length calculation for of_flow_add->instructions.
 * @param obj An object of type of_flow_add to check for
 * length of instructions
 * @param bytes[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_length_flow_add_instructions_get(
    of_flow_add_t *obj, int *bytes);

/**
 * Special offset calculation for of_flow_add->instructions.
 * @param obj An object of type of_flow_add to check for
 * length of instructions
 * @param offset[out] Where to store the calculated length
 *
 * Preceding data member is match.
 */
extern int of_offset_flow_add_instructions_get(
    of_flow_add_t *obj, int *offset);

/****************************************************************
 * Wire type/length functions.
 ****************************************************************/

extern void of_object_message_wire_length_get(of_object_t *obj, int *bytes);
extern void of_object_message_wire_length_set(of_object_t *obj, int bytes);

extern void of_oxm_wire_length_get(of_object_t *obj, int *bytes);
extern void of_oxm_wire_object_id_get(of_object_t *obj, of_object_id_t *id);

extern void of_tlv16_wire_length_get(of_object_t *obj, int *bytes);
extern void of_tlv16_wire_length_set(of_object_t *obj, int bytes);

/* Wire length is uint16 at front of structure */
extern void of_u16_len_wire_length_get(of_object_t *obj, int *bytes);
extern void of_u16_len_wire_length_set(of_object_t *obj, int bytes);

extern void of_action_wire_object_id_get(of_object_t *obj, of_object_id_t *id);
extern void of_action_id_wire_object_id_get(of_object_t *obj, of_object_id_t *id);
extern void of_instruction_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_instruction_id_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_queue_prop_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_table_feature_prop_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_meter_band_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_hello_elem_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);
extern void of_bsn_tlv_wire_object_id_get(of_object_t *obj,
    of_object_id_t *id);

#define OF_OXM_LENGTH_GET(hdr) (((hdr) & 0xff) + 4)
#define OF_OXM_LENGTH_SET(hdr, val)                         \
    (hdr) = ((hdr) & 0xffffff00) + (((val) - 4) & 0xff)

extern void of_packet_queue_wire_length_get(of_object_t *obj, int *bytes);
extern void of_packet_queue_wire_length_set(of_object_t *obj, int bytes);

extern void of_list_meter_band_stats_wire_length_get(of_object_t *obj,
                                                    int *bytes);
extern void of_meter_stats_wire_length_get(of_object_t *obj, int *bytes);
extern void of_meter_stats_wire_length_set(of_object_t *obj, int bytes);
extern int of_extension_object_wire_push(of_object_t *obj);


/*
 * Match serialize/deserialize declarations
 * Wire match conversion function declarations
 */
extern int of_match_serialize(of_version_t version, of_match_t *match,
                              of_octets_t *octets);
extern int of_match_deserialize(of_version_t version, of_match_t *match,
                                of_octets_t *octets);
extern int of_match_v1_to_match(of_match_v1_t *src, of_match_t *dst);
extern int of_match_v2_to_match(of_match_v2_t *src, of_match_t *dst);
extern int of_match_v3_to_match(of_match_v3_t *src, of_match_t *dst);
extern int of_match_to_wire_match_v1(of_match_t *src, of_match_v1_t *dst);
extern int of_match_to_wire_match_v2(of_match_t *src, of_match_v2_t *dst);
extern int of_match_to_wire_match_v3(of_match_t *src, of_match_v3_t *dst);

/**
 * Macro to check consistency of length for top level objects
 *
 * If the object has no parent then its length should match the
 * underlying wire buffer's current bytes.
 */
#define OF_LENGTH_CHECK_ASSERT(obj) \
    LOCI_ASSERT(((obj)->parent != NULL) || \
     ((obj)->wire_object.wbuf == NULL) || \
     (WBUF_CURRENT_BYTES((obj)->wire_object.wbuf) == (obj)->length))

#define OF_DEBUG_DUMP
#if defined(OF_DEBUG_DUMP)
extern void dump_match(of_match_t *match);
#endif /* OF_DEBUG_DUMP */

#endif /* Top header file */
