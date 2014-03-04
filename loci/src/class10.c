/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"


/**
 * \defgroup of_bsn_lacp_stats_entry of_bsn_lacp_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_lacp_stats_entry_push_wire_values(of_bsn_lacp_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_lacp_stats_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_lacp_stats_entry
 */

of_bsn_lacp_stats_entry_t *
of_bsn_lacp_stats_entry_new(of_version_t version)
{
    of_bsn_lacp_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_LACP_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_lacp_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_lacp_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_lacp_stats_entry.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_lacp_stats_entry_init(of_bsn_lacp_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_LACP_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_LACP_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get port_no from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_port_no_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param port_no The value to write into the object
 */
void
of_bsn_lacp_stats_entry_port_no_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_sys_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_sys_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_mac from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_sys_mac_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t *actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_mac in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_sys_mac The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_sys_mac_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 6;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_port_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_port_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_num from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_port_num_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_num in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_port_num The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_port_num_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 14;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_key from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_actor_key_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_key in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param actor_key The value to write into the object
 */
void
of_bsn_lacp_stats_entry_actor_key_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get convergence_status from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param convergence_status Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_convergence_status_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint8_t *convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set convergence_status in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param convergence_status The value to write into the object
 */
void
of_bsn_lacp_stats_entry_convergence_status_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint8_t convergence_status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 18;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, convergence_status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_sys_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_sys_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_sys_mac from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_sys_mac_get(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t *partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_sys_mac in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_sys_mac The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_sys_mac_set(
    of_bsn_lacp_stats_entry_t *obj,
    of_mac_addr_t partner_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 22;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, partner_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_priority from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_port_priority_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_priority in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_priority The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_port_priority_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 28;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_port_num from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_port_num_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_port_num in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_port_num The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_port_num_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 30;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get partner_key from an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_entry_partner_key_get(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t *partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set partner_key in an object of type of_bsn_lacp_stats_entry.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_entry.
 * @param partner_key The value to write into the object
 */
void
of_bsn_lacp_stats_entry_partner_key_set(
    of_bsn_lacp_stats_entry_t *obj,
    uint16_t partner_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, partner_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_lacp_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_lacp_stats_reply of_bsn_lacp_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_lacp_stats_reply_push_wire_values(of_bsn_lacp_stats_reply_t *obj)
{

    of_bsn_lacp_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_lacp_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_lacp_stats_reply
 */

of_bsn_lacp_stats_reply_t *
of_bsn_lacp_stats_reply_new(of_version_t version)
{
    of_bsn_lacp_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_REPLY] + of_object_extra_len[version][OF_BSN_LACP_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_lacp_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_reply_init(obj, version, bytes, 0);

    if (of_bsn_lacp_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_lacp_stats_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_lacp_stats_reply_init(of_bsn_lacp_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_LACP_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_REPLY] + of_object_extra_len[version][OF_BSN_LACP_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_LACP_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_lacp_stats_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_lacp_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_lacp_stats_reply
 */

of_bsn_lacp_stats_reply_t *
of_bsn_lacp_stats_reply_new_from_message(of_message_t msg)
{
    of_bsn_lacp_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_lacp_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_reply_xid_get(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_lacp_stats_reply_xid_set(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_reply_flags_get(
    of_bsn_lacp_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_lacp_stats_reply_flags_set(
    of_bsn_lacp_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_reply_experimenter_get(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_lacp_stats_reply_experimenter_set(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_reply_subtype_get(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_lacp_stats_reply_subtype_set(
    of_bsn_lacp_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_lacp_stats_entry_t to the parent of type of_bsn_lacp_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_lacp_stats_entry_t to be filled out.
 * \ingroup of_bsn_lacp_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_lacp_stats_reply_entries_bind(
    of_bsn_lacp_stats_reply_t *obj,
    of_list_bsn_lacp_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_lacp_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    entries->parent = (of_object_t *)obj;
    entries->wire_object.wbuf = obj->wire_object.wbuf;
    entries->wire_object.obj_offset = abs_offset;
    entries->wire_object.owned = 0;
    entries->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_lacp_stats_entry_t from
 * a of_bsn_lacp_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_lacp_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_lacp_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_lacp_stats_entry_t *
of_bsn_lacp_stats_reply_entries_get(of_bsn_lacp_stats_reply_t *obj) {
    of_list_bsn_lacp_stats_entry_t _entries;
    of_list_bsn_lacp_stats_entry_t *_entries_ptr;

    of_bsn_lacp_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_lacp_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_lacp_stats_reply.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_lacp_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_lacp_stats_reply_entries_set(
    of_bsn_lacp_stats_reply_t *obj,
    of_list_bsn_lacp_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == entries->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (entries->wire_length_set != NULL) {
        entries->wire_length_set((of_object_t *)entries, entries->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_lacp_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x1); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_lacp_stats_request of_bsn_lacp_stats_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_lacp_stats_request_push_wire_values(of_bsn_lacp_stats_request_t *obj)
{

    of_bsn_lacp_stats_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_lacp_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_lacp_stats_request
 */

of_bsn_lacp_stats_request_t *
of_bsn_lacp_stats_request_new(of_version_t version)
{
    of_bsn_lacp_stats_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_LACP_STATS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_lacp_stats_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_request_init(obj, version, bytes, 0);

    if (of_bsn_lacp_stats_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_lacp_stats_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_lacp_stats_request_init(of_bsn_lacp_stats_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_LACP_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_LACP_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_LACP_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_LACP_STATS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_lacp_stats_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_lacp_stats_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_lacp_stats_request
 */

of_bsn_lacp_stats_request_t *
of_bsn_lacp_stats_request_new_from_message(of_message_t msg)
{
    of_bsn_lacp_stats_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_lacp_stats_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_lacp_stats_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_request_xid_get(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_lacp_stats_request_xid_set(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_request_flags_get(
    of_bsn_lacp_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_lacp_stats_request_flags_set(
    of_bsn_lacp_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_request_experimenter_get(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_lacp_stats_request_experimenter_set(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_lacp_stats_request_subtype_get(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_lacp_stats_request.
 * @param obj Pointer to an object of type of_bsn_lacp_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_lacp_stats_request_subtype_set(
    of_bsn_lacp_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_LACP_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"


/**
 * \defgroup of_bsn_port_counter_stats_entry of_bsn_port_counter_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_port_counter_stats_entry_push_wire_values(of_bsn_port_counter_stats_entry_t *obj)
{

    obj->wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_port_counter_stats_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_port_counter_stats_entry
 */

of_bsn_port_counter_stats_entry_t *
of_bsn_port_counter_stats_entry_new(of_version_t version)
{
    of_bsn_port_counter_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_port_counter_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_port_counter_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_port_counter_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_port_counter_stats_entry.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_port_counter_stats_entry_init(of_bsn_port_counter_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_PORT_COUNTER_STATS_ENTRY;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_u16_len_wire_length_get;
    obj->wire_length_set = of_u16_len_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get port_no from an object of type of_bsn_port_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_entry.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_entry_port_no_get(
    of_bsn_port_counter_stats_entry_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_port_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_entry.
 * @param port_no The value to write into the object
 */
void
of_bsn_port_counter_stats_entry_port_no_set(
    of_bsn_port_counter_stats_entry_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_uint64_t to the parent of type of_bsn_port_counter_stats_entry for
 * member values
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_entry.
 * @param values Pointer to the child object of type
 * of_list_uint64_t to be filled out.
 * \ingroup of_bsn_port_counter_stats_entry
 *
 * The parameter values is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_port_counter_stats_entry_values_bind(
    of_bsn_port_counter_stats_entry_t *obj,
    of_list_uint64_t *values)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_uint64_init(values, obj->version, 0, 1);
    /* Attach to parent */
    values->parent = (of_object_t *)obj;
    values->wire_object.wbuf = obj->wire_object.wbuf;
    values->wire_object.obj_offset = abs_offset;
    values->wire_object.owned = 0;
    values->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of values into a new variable of type of_list_uint64_t from
 * a of_bsn_port_counter_stats_entry instance.
 *
 * @param obj Pointer to the source of type of_bsn_port_counter_stats_entry_t
 * @returns A pointer to a new instance of type of_list_uint64_t whose contents
 * match that of values from source
 * @returns NULL if an error occurs
 */
of_list_uint64_t *
of_bsn_port_counter_stats_entry_values_get(of_bsn_port_counter_stats_entry_t *obj) {
    of_list_uint64_t _values;
    of_list_uint64_t *_values_ptr;

    of_bsn_port_counter_stats_entry_values_bind(obj, &_values);
    _values_ptr = (of_list_uint64_t *)of_object_dup(&_values);
    return _values_ptr;
}

/**
 * Set values in an object of type of_bsn_port_counter_stats_entry.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_entry.
 * @param values Pointer to the child of type of_list_uint64_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_port_counter_stats_entry_values_set(
    of_bsn_port_counter_stats_entry_t *obj,
    of_list_uint64_t *values)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = values->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == values->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(values, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(values, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (values->wire_length_set != NULL) {
        values->wire_length_set((of_object_t *)values, values->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_port_counter_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_port_counter_stats_reply of_bsn_port_counter_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_port_counter_stats_reply_push_wire_values(of_bsn_port_counter_stats_reply_t *obj)
{

    of_bsn_port_counter_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_port_counter_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_port_counter_stats_reply
 */

of_bsn_port_counter_stats_reply_t *
of_bsn_port_counter_stats_reply_new(of_version_t version)
{
    of_bsn_port_counter_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REPLY] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_port_counter_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_port_counter_stats_reply_init(obj, version, bytes, 0);

    if (of_bsn_port_counter_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_port_counter_stats_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_port_counter_stats_reply_init(of_bsn_port_counter_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REPLY] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_PORT_COUNTER_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_port_counter_stats_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_port_counter_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_port_counter_stats_reply
 */

of_bsn_port_counter_stats_reply_t *
of_bsn_port_counter_stats_reply_new_from_message(of_message_t msg)
{
    of_bsn_port_counter_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_port_counter_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_port_counter_stats_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_reply_xid_get(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_port_counter_stats_reply_xid_set(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_reply_flags_get(
    of_bsn_port_counter_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_port_counter_stats_reply_flags_set(
    of_bsn_port_counter_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_reply_experimenter_get(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_port_counter_stats_reply_experimenter_set(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_reply_subtype_get(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_port_counter_stats_reply_subtype_set(
    of_bsn_port_counter_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_port_counter_stats_entry_t to the parent of type of_bsn_port_counter_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_port_counter_stats_entry_t to be filled out.
 * \ingroup of_bsn_port_counter_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_port_counter_stats_reply_entries_bind(
    of_bsn_port_counter_stats_reply_t *obj,
    of_list_bsn_port_counter_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_port_counter_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    entries->parent = (of_object_t *)obj;
    entries->wire_object.wbuf = obj->wire_object.wbuf;
    entries->wire_object.obj_offset = abs_offset;
    entries->wire_object.owned = 0;
    entries->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_port_counter_stats_entry_t from
 * a of_bsn_port_counter_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_port_counter_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_port_counter_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_port_counter_stats_entry_t *
of_bsn_port_counter_stats_reply_entries_get(of_bsn_port_counter_stats_reply_t *obj) {
    of_list_bsn_port_counter_stats_entry_t _entries;
    of_list_bsn_port_counter_stats_entry_t *_entries_ptr;

    of_bsn_port_counter_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_port_counter_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_port_counter_stats_reply.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_port_counter_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_port_counter_stats_reply_entries_set(
    of_bsn_port_counter_stats_reply_t *obj,
    of_list_bsn_port_counter_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == entries->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (entries->wire_length_set != NULL) {
        entries->wire_length_set((of_object_t *)entries, entries->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_port_counter_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x8); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_port_counter_stats_request of_bsn_port_counter_stats_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_port_counter_stats_request_push_wire_values(of_bsn_port_counter_stats_request_t *obj)
{

    of_bsn_port_counter_stats_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_port_counter_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_port_counter_stats_request
 */

of_bsn_port_counter_stats_request_t *
of_bsn_port_counter_stats_request_new(of_version_t version)
{
    of_bsn_port_counter_stats_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_port_counter_stats_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_port_counter_stats_request_init(obj, version, bytes, 0);

    if (of_bsn_port_counter_stats_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_port_counter_stats_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_port_counter_stats_request_init(of_bsn_port_counter_stats_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_PORT_COUNTER_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_PORT_COUNTER_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_PORT_COUNTER_STATS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_port_counter_stats_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_port_counter_stats_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_port_counter_stats_request
 */

of_bsn_port_counter_stats_request_t *
of_bsn_port_counter_stats_request_new_from_message(of_message_t msg)
{
    of_bsn_port_counter_stats_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_port_counter_stats_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_port_counter_stats_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_request_xid_get(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_port_counter_stats_request_xid_set(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_request_flags_get(
    of_bsn_port_counter_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_port_counter_stats_request_flags_set(
    of_bsn_port_counter_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_request_experimenter_get(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_port_counter_stats_request_experimenter_set(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_request_subtype_get(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_port_counter_stats_request_subtype_set(
    of_bsn_port_counter_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_no from an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_port_counter_stats_request_port_no_get(
    of_bsn_port_counter_stats_request_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_port_counter_stats_request.
 * @param obj Pointer to an object of type of_bsn_port_counter_stats_request.
 * @param port_no The value to write into the object
 */
void
of_bsn_port_counter_stats_request_port_no_set(
    of_bsn_port_counter_stats_request_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_PORT_COUNTER_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_role_status_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x37); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_role_status of_bsn_role_status
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_role_status_push_wire_values(of_bsn_role_status_t *obj)
{

    of_bsn_role_status_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_role_status object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_role_status
 */

of_bsn_role_status_t *
of_bsn_role_status_new(of_version_t version)
{
    of_bsn_role_status_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_ROLE_STATUS] + of_object_extra_len[version][OF_BSN_ROLE_STATUS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_role_status_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_role_status_init(obj, version, bytes, 0);

    if (of_bsn_role_status_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_role_status.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_role_status_init(of_bsn_role_status_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_ROLE_STATUS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_ROLE_STATUS] + of_object_extra_len[version][OF_BSN_ROLE_STATUS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_ROLE_STATUS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_role_status_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_role_status object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_role_status
 */

of_bsn_role_status_t *
of_bsn_role_status_new_from_message(of_message_t msg)
{
    of_bsn_role_status_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_role_status_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_role_status_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_role_status_xid_get(
    of_bsn_role_status_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param xid The value to write into the object
 */
void
of_bsn_role_status_xid_set(
    of_bsn_role_status_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_role_status_experimenter_get(
    of_bsn_role_status_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param experimenter The value to write into the object
 */
void
of_bsn_role_status_experimenter_set(
    of_bsn_role_status_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_role_status_subtype_get(
    of_bsn_role_status_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param subtype The value to write into the object
 */
void
of_bsn_role_status_subtype_set(
    of_bsn_role_status_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get role from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param role Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_role_status_role_get(
    of_bsn_role_status_t *obj,
    uint32_t *role)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, role);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set role in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param role The value to write into the object
 */
void
of_bsn_role_status_role_set(
    of_bsn_role_status_t *obj,
    uint32_t role)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, role);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get reason from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param reason Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_role_status_reason_get(
    of_bsn_role_status_t *obj,
    uint8_t *reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set reason in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param reason The value to write into the object
 */
void
of_bsn_role_status_reason_set(
    of_bsn_role_status_t *obj,
    uint8_t reason)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, reason);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get generation_id from an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param generation_id Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_role_status_generation_id_get(
    of_bsn_role_status_t *obj,
    uint64_t *generation_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, generation_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set generation_id in an object of type of_bsn_role_status.
 * @param obj Pointer to an object of type of_bsn_role_status.
 * @param generation_id The value to write into the object
 */
void
of_bsn_role_status_generation_id_set(
    of_bsn_role_status_t *obj,
    uint64_t generation_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_ROLE_STATUS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, generation_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_aux_cxns_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x3b); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_aux_cxns_reply of_bsn_set_aux_cxns_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_aux_cxns_reply_push_wire_values(of_bsn_set_aux_cxns_reply_t *obj)
{

    of_bsn_set_aux_cxns_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_aux_cxns_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_aux_cxns_reply
 */

of_bsn_set_aux_cxns_reply_t *
of_bsn_set_aux_cxns_reply_new(of_version_t version)
{
    of_bsn_set_aux_cxns_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REPLY] + of_object_extra_len[version][OF_BSN_SET_AUX_CXNS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_aux_cxns_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_aux_cxns_reply_init(obj, version, bytes, 0);

    if (of_bsn_set_aux_cxns_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_aux_cxns_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_aux_cxns_reply_init(of_bsn_set_aux_cxns_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REPLY] + of_object_extra_len[version][OF_BSN_SET_AUX_CXNS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_AUX_CXNS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_aux_cxns_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_aux_cxns_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_aux_cxns_reply
 */

of_bsn_set_aux_cxns_reply_t *
of_bsn_set_aux_cxns_reply_new_from_message(of_message_t msg)
{
    of_bsn_set_aux_cxns_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_aux_cxns_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_aux_cxns_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_reply_xid_get(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_set_aux_cxns_reply_xid_set(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_reply_experimenter_get(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_aux_cxns_reply_experimenter_set(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_reply_subtype_get(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_aux_cxns_reply_subtype_set(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get num_aux from an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param num_aux Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_reply_num_aux_get(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t *num_aux)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, num_aux);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set num_aux in an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param num_aux The value to write into the object
 */
void
of_bsn_set_aux_cxns_reply_num_aux_set(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t num_aux)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, num_aux);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get status from an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param status Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_reply_status_get(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t *status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set status in an object of type of_bsn_set_aux_cxns_reply.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_reply.
 * @param status The value to write into the object
 */
void
of_bsn_set_aux_cxns_reply_status_set(
    of_bsn_set_aux_cxns_reply_t *obj,
    uint32_t status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_aux_cxns_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x3a); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_aux_cxns_request of_bsn_set_aux_cxns_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_aux_cxns_request_push_wire_values(of_bsn_set_aux_cxns_request_t *obj)
{

    of_bsn_set_aux_cxns_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_aux_cxns_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_aux_cxns_request
 */

of_bsn_set_aux_cxns_request_t *
of_bsn_set_aux_cxns_request_new(of_version_t version)
{
    of_bsn_set_aux_cxns_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REQUEST] + of_object_extra_len[version][OF_BSN_SET_AUX_CXNS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_aux_cxns_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_aux_cxns_request_init(obj, version, bytes, 0);

    if (of_bsn_set_aux_cxns_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_aux_cxns_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_aux_cxns_request_init(of_bsn_set_aux_cxns_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_AUX_CXNS_REQUEST] + of_object_extra_len[version][OF_BSN_SET_AUX_CXNS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_AUX_CXNS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_aux_cxns_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_aux_cxns_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_aux_cxns_request
 */

of_bsn_set_aux_cxns_request_t *
of_bsn_set_aux_cxns_request_new_from_message(of_message_t msg)
{
    of_bsn_set_aux_cxns_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_aux_cxns_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_aux_cxns_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_request_xid_get(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param xid The value to write into the object
 */
void
of_bsn_set_aux_cxns_request_xid_set(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_request_experimenter_get(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_aux_cxns_request_experimenter_set(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_request_subtype_get(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_aux_cxns_request_subtype_set(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get num_aux from an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param num_aux Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_aux_cxns_request_num_aux_get(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t *num_aux)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, num_aux);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set num_aux in an object of type of_bsn_set_aux_cxns_request.
 * @param obj Pointer to an object of type of_bsn_set_aux_cxns_request.
 * @param num_aux The value to write into the object
 */
void
of_bsn_set_aux_cxns_request_num_aux_set(
    of_bsn_set_aux_cxns_request_t *obj,
    uint32_t num_aux)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_AUX_CXNS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, num_aux);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_lacp_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2a); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_lacp_reply of_bsn_set_lacp_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_lacp_reply_push_wire_values(of_bsn_set_lacp_reply_t *obj)
{

    of_bsn_set_lacp_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_lacp_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_lacp_reply
 */

of_bsn_set_lacp_reply_t *
of_bsn_set_lacp_reply_new(of_version_t version)
{
    of_bsn_set_lacp_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_LACP_REPLY] + of_object_extra_len[version][OF_BSN_SET_LACP_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_lacp_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_lacp_reply_init(obj, version, bytes, 0);

    if (of_bsn_set_lacp_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_lacp_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_lacp_reply_init(of_bsn_set_lacp_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_LACP_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_LACP_REPLY] + of_object_extra_len[version][OF_BSN_SET_LACP_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_LACP_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_lacp_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_lacp_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_lacp_reply
 */

of_bsn_set_lacp_reply_t *
of_bsn_set_lacp_reply_new_from_message(of_message_t msg)
{
    of_bsn_set_lacp_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_lacp_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_lacp_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_reply_xid_get(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_set_lacp_reply_xid_set(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_reply_experimenter_get(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_lacp_reply_experimenter_set(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_reply_subtype_get(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_lacp_reply_subtype_set(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get status from an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param status Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_reply_status_get(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t *status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set status in an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param status The value to write into the object
 */
void
of_bsn_set_lacp_reply_status_set(
    of_bsn_set_lacp_reply_t *obj,
    uint32_t status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_no from an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_set_lacp_reply_port_no_get(
    of_bsn_set_lacp_reply_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_set_lacp_reply.
 * @param obj Pointer to an object of type of_bsn_set_lacp_reply.
 * @param port_no The value to write into the object
 */
void
of_bsn_set_lacp_reply_port_no_set(
    of_bsn_set_lacp_reply_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_lacp_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x29); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_lacp_request of_bsn_set_lacp_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_lacp_request_push_wire_values(of_bsn_set_lacp_request_t *obj)
{

    of_bsn_set_lacp_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_lacp_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_lacp_request
 */

of_bsn_set_lacp_request_t *
of_bsn_set_lacp_request_new(of_version_t version)
{
    of_bsn_set_lacp_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_LACP_REQUEST] + of_object_extra_len[version][OF_BSN_SET_LACP_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_lacp_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_lacp_request_init(obj, version, bytes, 0);

    if (of_bsn_set_lacp_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_lacp_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_lacp_request_init(of_bsn_set_lacp_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_LACP_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_LACP_REQUEST] + of_object_extra_len[version][OF_BSN_SET_LACP_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_LACP_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_lacp_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_lacp_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_lacp_request
 */

of_bsn_set_lacp_request_t *
of_bsn_set_lacp_request_new_from_message(of_message_t msg)
{
    of_bsn_set_lacp_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_lacp_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_lacp_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_xid_get(
    of_bsn_set_lacp_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param xid The value to write into the object
 */
void
of_bsn_set_lacp_request_xid_set(
    of_bsn_set_lacp_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_experimenter_get(
    of_bsn_set_lacp_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_lacp_request_experimenter_set(
    of_bsn_set_lacp_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_subtype_get(
    of_bsn_set_lacp_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_lacp_request_subtype_set(
    of_bsn_set_lacp_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get enabled from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param enabled Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_enabled_get(
    of_bsn_set_lacp_request_t *obj,
    uint8_t *enabled)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, enabled);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set enabled in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param enabled The value to write into the object
 */
void
of_bsn_set_lacp_request_enabled_set(
    of_bsn_set_lacp_request_t *obj,
    uint8_t enabled)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, enabled);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get port_no from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param port_no Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_port_no_get(
    of_bsn_set_lacp_request_t *obj,
    of_port_no_t *port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, port_no);
    OF_PORT_NO_VALUE_CHECK(*port_no, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set port_no in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param port_no The value to write into the object
 */
void
of_bsn_set_lacp_request_port_no_set(
    of_bsn_set_lacp_request_t *obj,
    of_port_no_t port_no)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, port_no);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_priority from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_sys_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_actor_sys_priority_get(
    of_bsn_set_lacp_request_t *obj,
    uint16_t *actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_priority in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_sys_priority The value to write into the object
 */
void
of_bsn_set_lacp_request_actor_sys_priority_set(
    of_bsn_set_lacp_request_t *obj,
    uint16_t actor_sys_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_sys_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_sys_mac from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_sys_mac Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_actor_sys_mac_get(
    of_bsn_set_lacp_request_t *obj,
    of_mac_addr_t *actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_sys_mac in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_sys_mac The value to write into the object
 */
void
of_bsn_set_lacp_request_actor_sys_mac_set(
    of_bsn_set_lacp_request_t *obj,
    of_mac_addr_t actor_sys_mac)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 26;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, actor_sys_mac);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_priority from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_port_priority Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_actor_port_priority_get(
    of_bsn_set_lacp_request_t *obj,
    uint16_t *actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_priority in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_port_priority The value to write into the object
 */
void
of_bsn_set_lacp_request_actor_port_priority_set(
    of_bsn_set_lacp_request_t *obj,
    uint16_t actor_port_priority)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 32;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_priority);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_port_num from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_port_num Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_actor_port_num_get(
    of_bsn_set_lacp_request_t *obj,
    uint16_t *actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_port_num in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_port_num The value to write into the object
 */
void
of_bsn_set_lacp_request_actor_port_num_set(
    of_bsn_set_lacp_request_t *obj,
    uint16_t actor_port_num)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 34;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_port_num);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get actor_key from an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_key Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_set_lacp_request_actor_key_get(
    of_bsn_set_lacp_request_t *obj,
    uint16_t *actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set actor_key in an object of type of_bsn_set_lacp_request.
 * @param obj Pointer to an object of type of_bsn_set_lacp_request.
 * @param actor_key The value to write into the object
 */
void
of_bsn_set_lacp_request_actor_key_set(
    of_bsn_set_lacp_request_t *obj,
    uint16_t actor_key)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_LACP_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 36;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, actor_key);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_switch_pipeline_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x36); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_switch_pipeline_reply of_bsn_set_switch_pipeline_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_switch_pipeline_reply_push_wire_values(of_bsn_set_switch_pipeline_reply_t *obj)
{

    of_bsn_set_switch_pipeline_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_switch_pipeline_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_switch_pipeline_reply
 */

of_bsn_set_switch_pipeline_reply_t *
of_bsn_set_switch_pipeline_reply_new(of_version_t version)
{
    of_bsn_set_switch_pipeline_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REPLY] + of_object_extra_len[version][OF_BSN_SET_SWITCH_PIPELINE_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_switch_pipeline_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_switch_pipeline_reply_init(obj, version, bytes, 0);

    if (of_bsn_set_switch_pipeline_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_switch_pipeline_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_switch_pipeline_reply_init(of_bsn_set_switch_pipeline_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REPLY] + of_object_extra_len[version][OF_BSN_SET_SWITCH_PIPELINE_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_SWITCH_PIPELINE_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_switch_pipeline_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_switch_pipeline_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_switch_pipeline_reply
 */

of_bsn_set_switch_pipeline_reply_t *
of_bsn_set_switch_pipeline_reply_new_from_message(of_message_t msg)
{
    of_bsn_set_switch_pipeline_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_switch_pipeline_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_switch_pipeline_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_reply_xid_get(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_set_switch_pipeline_reply_xid_set(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_reply_experimenter_get(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_switch_pipeline_reply_experimenter_set(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_reply_subtype_get(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_switch_pipeline_reply_subtype_set(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get status from an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param status Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_reply_status_get(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t *status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set status in an object of type of_bsn_set_switch_pipeline_reply.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_reply.
 * @param status The value to write into the object
 */
void
of_bsn_set_switch_pipeline_reply_status_set(
    of_bsn_set_switch_pipeline_reply_t *obj,
    uint32_t status)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, status);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_set_switch_pipeline_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x35); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_set_switch_pipeline_request of_bsn_set_switch_pipeline_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_set_switch_pipeline_request_push_wire_values(of_bsn_set_switch_pipeline_request_t *obj)
{

    of_bsn_set_switch_pipeline_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_set_switch_pipeline_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_set_switch_pipeline_request
 */

of_bsn_set_switch_pipeline_request_t *
of_bsn_set_switch_pipeline_request_new(of_version_t version)
{
    of_bsn_set_switch_pipeline_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REQUEST] + of_object_extra_len[version][OF_BSN_SET_SWITCH_PIPELINE_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_set_switch_pipeline_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_set_switch_pipeline_request_init(obj, version, bytes, 0);

    if (of_bsn_set_switch_pipeline_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_set_switch_pipeline_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_set_switch_pipeline_request_init(of_bsn_set_switch_pipeline_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SET_SWITCH_PIPELINE_REQUEST] + of_object_extra_len[version][OF_BSN_SET_SWITCH_PIPELINE_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SET_SWITCH_PIPELINE_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_set_switch_pipeline_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_set_switch_pipeline_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_set_switch_pipeline_request
 */

of_bsn_set_switch_pipeline_request_t *
of_bsn_set_switch_pipeline_request_new_from_message(of_message_t msg)
{
    of_bsn_set_switch_pipeline_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_set_switch_pipeline_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_set_switch_pipeline_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_request_xid_get(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param xid The value to write into the object
 */
void
of_bsn_set_switch_pipeline_request_xid_set(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_request_experimenter_get(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_set_switch_pipeline_request_experimenter_set(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_request_subtype_get(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_set_switch_pipeline_request_subtype_set(
    of_bsn_set_switch_pipeline_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get pipeline from an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param pipeline Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_bsn_set_switch_pipeline_request_pipeline_get(
    of_bsn_set_switch_pipeline_request_t *obj,
    of_desc_str_t *pipeline)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_get(wbuf, abs_offset, pipeline);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set pipeline in an object of type of_bsn_set_switch_pipeline_request.
 * @param obj Pointer to an object of type of_bsn_set_switch_pipeline_request.
 * @param pipeline The value to write into the object
 */
void
of_bsn_set_switch_pipeline_request_pipeline_set(
    of_bsn_set_switch_pipeline_request_t *obj,
    of_desc_str_t pipeline)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SET_SWITCH_PIPELINE_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_set(wbuf, abs_offset, pipeline);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"


/**
 * \defgroup of_bsn_switch_pipeline_stats_entry of_bsn_switch_pipeline_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_switch_pipeline_stats_entry_push_wire_values(of_bsn_switch_pipeline_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_switch_pipeline_stats_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_switch_pipeline_stats_entry
 */

of_bsn_switch_pipeline_stats_entry_t *
of_bsn_switch_pipeline_stats_entry_new(of_version_t version)
{
    of_bsn_switch_pipeline_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_switch_pipeline_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_switch_pipeline_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_switch_pipeline_stats_entry.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_switch_pipeline_stats_entry_init(of_bsn_switch_pipeline_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SWITCH_PIPELINE_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get pipeline from an object of type of_bsn_switch_pipeline_stats_entry.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_entry.
 * @param pipeline Pointer to the child object of type
 * of_desc_str_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_entry_pipeline_get(
    of_bsn_switch_pipeline_stats_entry_t *obj,
    of_desc_str_t *pipeline)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_get(wbuf, abs_offset, pipeline);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set pipeline in an object of type of_bsn_switch_pipeline_stats_entry.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_entry.
 * @param pipeline The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_entry_pipeline_set(
    of_bsn_switch_pipeline_stats_entry_t *obj,
    of_desc_str_t pipeline)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_desc_str_set(wbuf, abs_offset, pipeline);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_switch_pipeline_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_switch_pipeline_stats_reply of_bsn_switch_pipeline_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_switch_pipeline_stats_reply_push_wire_values(of_bsn_switch_pipeline_stats_reply_t *obj)
{

    of_bsn_switch_pipeline_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_switch_pipeline_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_switch_pipeline_stats_reply
 */

of_bsn_switch_pipeline_stats_reply_t *
of_bsn_switch_pipeline_stats_reply_new(of_version_t version)
{
    of_bsn_switch_pipeline_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_switch_pipeline_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_reply_init(obj, version, bytes, 0);

    if (of_bsn_switch_pipeline_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_switch_pipeline_stats_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_switch_pipeline_stats_reply_init(of_bsn_switch_pipeline_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SWITCH_PIPELINE_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_switch_pipeline_stats_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_switch_pipeline_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_switch_pipeline_stats_reply
 */

of_bsn_switch_pipeline_stats_reply_t *
of_bsn_switch_pipeline_stats_reply_new_from_message(of_message_t msg)
{
    of_bsn_switch_pipeline_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_switch_pipeline_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_xid_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_xid_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_flags_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_flags_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_experimenter_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_experimenter_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_subtype_get(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_reply_subtype_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_switch_pipeline_stats_entry_t to the parent of type of_bsn_switch_pipeline_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_switch_pipeline_stats_entry_t to be filled out.
 * \ingroup of_bsn_switch_pipeline_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_switch_pipeline_stats_reply_entries_bind(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    of_list_bsn_switch_pipeline_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_switch_pipeline_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    entries->parent = (of_object_t *)obj;
    entries->wire_object.wbuf = obj->wire_object.wbuf;
    entries->wire_object.obj_offset = abs_offset;
    entries->wire_object.owned = 0;
    entries->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_switch_pipeline_stats_entry_t from
 * a of_bsn_switch_pipeline_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_switch_pipeline_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_switch_pipeline_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_switch_pipeline_stats_entry_t *
of_bsn_switch_pipeline_stats_reply_entries_get(of_bsn_switch_pipeline_stats_reply_t *obj) {
    of_list_bsn_switch_pipeline_stats_entry_t _entries;
    of_list_bsn_switch_pipeline_stats_entry_t *_entries_ptr;

    of_bsn_switch_pipeline_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_switch_pipeline_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_switch_pipeline_stats_reply.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_switch_pipeline_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_switch_pipeline_stats_reply_entries_set(
    of_bsn_switch_pipeline_stats_reply_t *obj,
    of_list_bsn_switch_pipeline_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == entries->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (entries->wire_length_set != NULL) {
        entries->wire_length_set((of_object_t *)entries, entries->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_switch_pipeline_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0x6); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_switch_pipeline_stats_request of_bsn_switch_pipeline_stats_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_switch_pipeline_stats_request_push_wire_values(of_bsn_switch_pipeline_stats_request_t *obj)
{

    of_bsn_switch_pipeline_stats_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_switch_pipeline_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_switch_pipeline_stats_request
 */

of_bsn_switch_pipeline_stats_request_t *
of_bsn_switch_pipeline_stats_request_new(of_version_t version)
{
    of_bsn_switch_pipeline_stats_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_switch_pipeline_stats_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_request_init(obj, version, bytes, 0);

    if (of_bsn_switch_pipeline_stats_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_switch_pipeline_stats_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_switch_pipeline_stats_request_init(of_bsn_switch_pipeline_stats_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_SWITCH_PIPELINE_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_SWITCH_PIPELINE_STATS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_switch_pipeline_stats_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_switch_pipeline_stats_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_switch_pipeline_stats_request
 */

of_bsn_switch_pipeline_stats_request_t *
of_bsn_switch_pipeline_stats_request_new_from_message(of_message_t msg)
{
    of_bsn_switch_pipeline_stats_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_switch_pipeline_stats_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_switch_pipeline_stats_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_xid_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_xid_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_flags_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_flags_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_experimenter_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_experimenter_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_switch_pipeline_stats_request_subtype_get(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_switch_pipeline_stats_request.
 * @param obj Pointer to an object of type of_bsn_switch_pipeline_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_switch_pipeline_stats_request_subtype_set(
    of_bsn_switch_pipeline_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_SWITCH_PIPELINE_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"


/**
 * \defgroup of_bsn_table_checksum_stats_entry of_bsn_table_checksum_stats_entry
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_table_checksum_stats_entry_push_wire_values(of_bsn_table_checksum_stats_entry_t *obj)
{

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_table_checksum_stats_entry object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_table_checksum_stats_entry
 */

of_bsn_table_checksum_stats_entry_t *
of_bsn_table_checksum_stats_entry_new(of_version_t version)
{
    of_bsn_table_checksum_stats_entry_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_table_checksum_stats_entry_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_entry_init(obj, version, bytes, 0);

    if (of_bsn_table_checksum_stats_entry_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_entry.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_table_checksum_stats_entry_init(of_bsn_table_checksum_stats_entry_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_ENTRY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_ENTRY;

    /* Set up the object's function pointers */

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get table_id from an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param table_id Pointer to the child object of type
 * uint8_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_entry_table_id_get(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint8_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param table_id The value to write into the object
 */
void
of_bsn_table_checksum_stats_entry_table_id_set(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint8_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 0;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u8_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get checksum from an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param checksum Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_entry_checksum_get(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint64_t *checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set checksum in an object of type of_bsn_table_checksum_stats_entry.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_entry.
 * @param checksum The value to write into the object
 */
void
of_bsn_table_checksum_stats_entry_checksum_set(
    of_bsn_table_checksum_stats_entry_t *obj,
    uint64_t checksum)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_ENTRY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 1;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, checksum);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_table_checksum_stats_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x13; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_table_checksum_stats_reply of_bsn_table_checksum_stats_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_table_checksum_stats_reply_push_wire_values(of_bsn_table_checksum_stats_reply_t *obj)
{

    of_bsn_table_checksum_stats_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_table_checksum_stats_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_table_checksum_stats_reply
 */

of_bsn_table_checksum_stats_reply_t *
of_bsn_table_checksum_stats_reply_new(of_version_t version)
{
    of_bsn_table_checksum_stats_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_table_checksum_stats_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_reply_init(obj, version, bytes, 0);

    if (of_bsn_table_checksum_stats_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_table_checksum_stats_reply_init(of_bsn_table_checksum_stats_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_table_checksum_stats_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_table_checksum_stats_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_table_checksum_stats_reply
 */

of_bsn_table_checksum_stats_reply_t *
of_bsn_table_checksum_stats_reply_new_from_message(of_message_t msg)
{
    of_bsn_table_checksum_stats_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_table_checksum_stats_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_xid_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_xid_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_flags_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param flags The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_flags_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_experimenter_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_experimenter_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_reply_subtype_get(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_checksum_stats_reply_subtype_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Bind an object of type of_list_bsn_table_checksum_stats_entry_t to the parent of type of_bsn_table_checksum_stats_reply for
 * member entries
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param entries Pointer to the child object of type
 * of_list_bsn_table_checksum_stats_entry_t to be filled out.
 * \ingroup of_bsn_table_checksum_stats_reply
 *
 * The parameter entries is filled out to point to the same underlying
 * wire buffer as its parent.
 *
 */
void
of_bsn_table_checksum_stats_reply_entries_bind(
    of_bsn_table_checksum_stats_reply_t *obj,
    of_list_bsn_table_checksum_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* Initialize child */
    of_list_bsn_table_checksum_stats_entry_init(entries, obj->version, 0, 1);
    /* Attach to parent */
    entries->parent = (of_object_t *)obj;
    entries->wire_object.wbuf = obj->wire_object.wbuf;
    entries->wire_object.obj_offset = abs_offset;
    entries->wire_object.owned = 0;
    entries->length = cur_len;

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Create a copy of entries into a new variable of type of_list_bsn_table_checksum_stats_entry_t from
 * a of_bsn_table_checksum_stats_reply instance.
 *
 * @param obj Pointer to the source of type of_bsn_table_checksum_stats_reply_t
 * @returns A pointer to a new instance of type of_list_bsn_table_checksum_stats_entry_t whose contents
 * match that of entries from source
 * @returns NULL if an error occurs
 */
of_list_bsn_table_checksum_stats_entry_t *
of_bsn_table_checksum_stats_reply_entries_get(of_bsn_table_checksum_stats_reply_t *obj) {
    of_list_bsn_table_checksum_stats_entry_t _entries;
    of_list_bsn_table_checksum_stats_entry_t *_entries_ptr;

    of_bsn_table_checksum_stats_reply_entries_bind(obj, &_entries);
    _entries_ptr = (of_list_bsn_table_checksum_stats_entry_t *)of_object_dup(&_entries);
    return _entries_ptr;
}

/**
 * Set entries in an object of type of_bsn_table_checksum_stats_reply.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_reply.
 * @param entries Pointer to the child of type of_list_bsn_table_checksum_stats_entry_t.
 *
 * If the child's wire buffer is the same as the parent's, then
 * nothing is done as the changes have already been registered in the
 * parent.  Otherwise, the data in the child's wire buffer is inserted
 * into the parent's and the appropriate lengths are updated.
 */
int WARN_UNUSED_RESULT
of_bsn_table_checksum_stats_reply_entries_set(
    of_bsn_table_checksum_stats_reply_t *obj,
    of_list_bsn_table_checksum_stats_entry_t *entries)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 24;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);

    /* LOCI object type */
    new_len = entries->length;
    /* If underlying buffer already shared; nothing to do */
    if (obj->wire_object.wbuf == entries->wire_object.wbuf) {
        of_wire_buffer_grow(wbuf, abs_offset + new_len);
        /* Verify that the offsets are correct */
        LOCI_ASSERT(abs_offset == OF_OBJECT_ABSOLUTE_OFFSET(entries, 0));
        /* LOCI_ASSERT(new_len == cur_len); */ /* fixme: may fail for OXM lists */
        return OF_ERROR_NONE;
    }

    /* Otherwise, replace existing object in data buffer */
    of_wire_buffer_replace_data(wbuf, abs_offset, cur_len,
        OF_OBJECT_BUFFER_INDEX(entries, 0), new_len);

    /* @fixme Shouldn't this precede copying value's data to buffer? */
    if (entries->wire_length_set != NULL) {
        entries->wire_length_set((of_object_t *)entries, entries->length);
    }

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_table_checksum_stats_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x12; /* type */
        *(uint16_t *)(buf + 8) = htobe16(0xffff); /* stats_type */
        *(uint32_t *)(buf + 16) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 20) = htobe32(0xb); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_table_checksum_stats_request of_bsn_table_checksum_stats_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_table_checksum_stats_request_push_wire_values(of_bsn_table_checksum_stats_request_t *obj)
{

    of_bsn_table_checksum_stats_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_table_checksum_stats_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_table_checksum_stats_request
 */

of_bsn_table_checksum_stats_request_t *
of_bsn_table_checksum_stats_request_new(of_version_t version)
{
    of_bsn_table_checksum_stats_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_table_checksum_stats_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_request_init(obj, version, bytes, 0);

    if (of_bsn_table_checksum_stats_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_checksum_stats_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_table_checksum_stats_request_init(of_bsn_table_checksum_stats_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST] + of_object_extra_len[version][OF_BSN_TABLE_CHECKSUM_STATS_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_CHECKSUM_STATS_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_table_checksum_stats_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_table_checksum_stats_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_table_checksum_stats_request
 */

of_bsn_table_checksum_stats_request_t *
of_bsn_table_checksum_stats_request_new_from_message(of_message_t msg)
{
    of_bsn_table_checksum_stats_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_table_checksum_stats_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_table_checksum_stats_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_xid_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param xid The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_xid_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get flags from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param flags Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_flags_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint16_t *flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set flags in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param flags The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_flags_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint16_t flags)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 10;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, flags);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_experimenter_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_experimenter_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_checksum_stats_request_subtype_get(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_checksum_stats_request.
 * @param obj Pointer to an object of type of_bsn_table_checksum_stats_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_checksum_stats_request_subtype_set(
    of_bsn_table_checksum_stats_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_CHECKSUM_STATS_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_table_set_buckets_size_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x3d); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_table_set_buckets_size of_bsn_table_set_buckets_size
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_table_set_buckets_size_push_wire_values(of_bsn_table_set_buckets_size_t *obj)
{

    of_bsn_table_set_buckets_size_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_table_set_buckets_size object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_table_set_buckets_size
 */

of_bsn_table_set_buckets_size_t *
of_bsn_table_set_buckets_size_new(of_version_t version)
{
    of_bsn_table_set_buckets_size_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE] + of_object_extra_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_table_set_buckets_size_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_table_set_buckets_size_init(obj, version, bytes, 0);

    if (of_bsn_table_set_buckets_size_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_table_set_buckets_size.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_table_set_buckets_size_init(of_bsn_table_set_buckets_size_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE] + of_object_extra_len[version][OF_BSN_TABLE_SET_BUCKETS_SIZE];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TABLE_SET_BUCKETS_SIZE;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_table_set_buckets_size_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_table_set_buckets_size object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_table_set_buckets_size
 */

of_bsn_table_set_buckets_size_t *
of_bsn_table_set_buckets_size_new_from_message(of_message_t msg)
{
    of_bsn_table_set_buckets_size_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_table_set_buckets_size_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_table_set_buckets_size_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_xid_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param xid The value to write into the object
 */
void
of_bsn_table_set_buckets_size_xid_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_experimenter_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param experimenter The value to write into the object
 */
void
of_bsn_table_set_buckets_size_experimenter_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_subtype_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param subtype The value to write into the object
 */
void
of_bsn_table_set_buckets_size_subtype_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get table_id from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param table_id Pointer to the child object of type
 * uint16_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_table_id_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint16_t *table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_get(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set table_id in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param table_id The value to write into the object
 */
void
of_bsn_table_set_buckets_size_table_id_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint16_t table_id)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u16_set(wbuf, abs_offset, table_id);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get buckets_size from an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param buckets_size Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_table_set_buckets_size_buckets_size_get(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t *buckets_size)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, buckets_size);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set buckets_size in an object of type of_bsn_table_set_buckets_size.
 * @param obj Pointer to an object of type of_bsn_table_set_buckets_size.
 * @param buckets_size The value to write into the object
 */
void
of_bsn_table_set_buckets_size_buckets_size_set(
    of_bsn_table_set_buckets_size_t *obj,
    uint32_t buckets_size)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TABLE_SET_BUCKETS_SIZE);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 20;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, buckets_size);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_time_reply_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2d); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_time_reply of_bsn_time_reply
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_time_reply_push_wire_values(of_bsn_time_reply_t *obj)
{

    of_bsn_time_reply_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_time_reply object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_time_reply
 */

of_bsn_time_reply_t *
of_bsn_time_reply_new(of_version_t version)
{
    of_bsn_time_reply_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TIME_REPLY] + of_object_extra_len[version][OF_BSN_TIME_REPLY];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_time_reply_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_time_reply_init(obj, version, bytes, 0);

    if (of_bsn_time_reply_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_time_reply.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_time_reply_init(of_bsn_time_reply_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TIME_REPLY] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TIME_REPLY] + of_object_extra_len[version][OF_BSN_TIME_REPLY];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TIME_REPLY;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_time_reply_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_time_reply object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_time_reply
 */

of_bsn_time_reply_t *
of_bsn_time_reply_new_from_message(of_message_t msg)
{
    of_bsn_time_reply_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_time_reply_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_time_reply_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_xid_get(
    of_bsn_time_reply_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param xid The value to write into the object
 */
void
of_bsn_time_reply_xid_set(
    of_bsn_time_reply_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_experimenter_get(
    of_bsn_time_reply_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param experimenter The value to write into the object
 */
void
of_bsn_time_reply_experimenter_set(
    of_bsn_time_reply_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_reply_subtype_get(
    of_bsn_time_reply_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param subtype The value to write into the object
 */
void
of_bsn_time_reply_subtype_set(
    of_bsn_time_reply_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get time_ms from an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param time_ms Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_time_reply_time_ms_get(
    of_bsn_time_reply_t *obj,
    uint64_t *time_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, time_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set time_ms in an object of type of_bsn_time_reply.
 * @param obj Pointer to an object of type of_bsn_time_reply.
 * @param time_ms The value to write into the object
 */
void
of_bsn_time_reply_time_ms_set(
    of_bsn_time_reply_t *obj,
    uint64_t time_ms)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REPLY);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 16;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, time_ms);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_time_request_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint8_t *)(buf + 0) = obj->version; /* version */
        *(uint8_t *)(buf + 1) = 0x4; /* type */
        *(uint32_t *)(buf + 8) = htobe32(0x5c16c7); /* experimenter */
        *(uint32_t *)(buf + 12) = htobe32(0x2c); /* subtype */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_time_request of_bsn_time_request
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_time_request_push_wire_values(of_bsn_time_request_t *obj)
{

    of_bsn_time_request_push_wire_types(obj);

    /* Message obj; set length */
    of_message_t msg;

    if ((msg = OF_OBJECT_TO_MESSAGE(obj)) != NULL) {
        of_message_length_set(msg, obj->length);
    }

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_time_request object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_time_request
 */

of_bsn_time_request_t *
of_bsn_time_request_new(of_version_t version)
{
    of_bsn_time_request_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TIME_REQUEST] + of_object_extra_len[version][OF_BSN_TIME_REQUEST];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_time_request_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_time_request_init(obj, version, bytes, 0);

    if (of_bsn_time_request_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_time_request.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_time_request_init(of_bsn_time_request_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TIME_REQUEST] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TIME_REQUEST] + of_object_extra_len[version][OF_BSN_TIME_REQUEST];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TIME_REQUEST;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_time_request_push_wire_types;

    obj->wire_length_get = of_object_message_wire_length_get;
    obj->wire_length_set = of_object_message_wire_length_set;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Create a new of_bsn_time_request object and bind it to an existing message
 *
 * @param msg The message to bind the new object to
 * @return Pointer to the newly create object or NULL on error
 *
 * \ingroup of_bsn_time_request
 */

of_bsn_time_request_t *
of_bsn_time_request_new_from_message(of_message_t msg)
{
    of_bsn_time_request_t *obj = NULL;
    of_version_t version;
    int length;

    if (msg == NULL) return NULL;

    version = of_message_version_get(msg);
    if (!OF_VERSION_OKAY(version)) return NULL;

    length = of_message_length_get(msg);

    if ((obj = (of_bsn_time_request_t *)of_object_new(-1)) == NULL) {
        return NULL;
    }

    of_bsn_time_request_init(obj, version, 0, 0);

    if ((of_object_buffer_bind((of_object_t *)obj, OF_MESSAGE_TO_BUFFER(msg),
                               length, OF_MESSAGE_FREE_FUNCTION)) < 0) {
       FREE(obj);
       return NULL;
    }
    obj->length = length;
    obj->version = version;

    return obj;
}

/**
 * Get xid from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param xid Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_xid_get(
    of_bsn_time_request_t *obj,
    uint32_t *xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set xid in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param xid The value to write into the object
 */
void
of_bsn_time_request_xid_set(
    of_bsn_time_request_t *obj,
    uint32_t xid)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, xid);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get experimenter from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param experimenter Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_experimenter_get(
    of_bsn_time_request_t *obj,
    uint32_t *experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set experimenter in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param experimenter The value to write into the object
 */
void
of_bsn_time_request_experimenter_set(
    of_bsn_time_request_t *obj,
    uint32_t experimenter)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 8;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, experimenter);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Get subtype from an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param subtype Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_time_request_subtype_get(
    of_bsn_time_request_t *obj,
    uint32_t *subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set subtype in an object of type of_bsn_time_request.
 * @param obj Pointer to an object of type of_bsn_time_request.
 * @param subtype The value to write into the object
 */
void
of_bsn_time_request_subtype_set(
    of_bsn_time_request_t *obj,
    uint32_t subtype)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TIME_REQUEST);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 12;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, subtype);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"


/**
 * \defgroup of_bsn_tlv of_bsn_tlv
 */

/**
 * Create a new of_bsn_tlv object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv
 */

of_bsn_tlv_t *
of_bsn_tlv_new(of_version_t version)
{
    of_bsn_tlv_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV] + of_object_extra_len[version][OF_BSN_TLV];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_init(obj, version, bytes, 0);

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_init(of_bsn_tlv_t *obj_p,
    of_version_t version, int bytes, int clean_wire)
{
    of_bsn_tlv_header_t *obj;

    obj = &obj_p->header;  /* Need instantiable subclass */

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV] + of_object_extra_len[version][OF_BSN_TLV];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV;

    /* Set up the object's function pointers */

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}

/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_broadcast_query_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xa); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_broadcast_query_timeout of_bsn_tlv_broadcast_query_timeout
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_broadcast_query_timeout_push_wire_values(of_bsn_tlv_broadcast_query_timeout_t *obj)
{

    of_bsn_tlv_broadcast_query_timeout_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_broadcast_query_timeout object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_broadcast_query_timeout
 */

of_bsn_tlv_broadcast_query_timeout_t *
of_bsn_tlv_broadcast_query_timeout_new(of_version_t version)
{
    of_bsn_tlv_broadcast_query_timeout_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_broadcast_query_timeout_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_broadcast_query_timeout_init(obj, version, bytes, 0);

    if (of_bsn_tlv_broadcast_query_timeout_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_broadcast_query_timeout.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_broadcast_query_timeout_init(of_bsn_tlv_broadcast_query_timeout_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_broadcast_query_timeout_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_broadcast_query_timeout_value_get(
    of_bsn_tlv_broadcast_query_timeout_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_broadcast_query_timeout.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_broadcast_query_timeout_value_set(
    of_bsn_tlv_broadcast_query_timeout_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_BROADCAST_QUERY_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_circuit_id_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xe); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_circuit_id of_bsn_tlv_circuit_id
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_circuit_id_push_wire_values(of_bsn_tlv_circuit_id_t *obj)
{

    of_bsn_tlv_circuit_id_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_circuit_id object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_circuit_id
 */

of_bsn_tlv_circuit_id_t *
of_bsn_tlv_circuit_id_new(of_version_t version)
{
    of_bsn_tlv_circuit_id_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID] + of_object_extra_len[version][OF_BSN_TLV_CIRCUIT_ID];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_circuit_id_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_circuit_id_init(obj, version, bytes, 0);

    if (of_bsn_tlv_circuit_id_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_circuit_id.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_circuit_id_init(of_bsn_tlv_circuit_id_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_CIRCUIT_ID] + of_object_extra_len[version][OF_BSN_TLV_CIRCUIT_ID];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_CIRCUIT_ID;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_circuit_id_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_circuit_id.
 * @param obj Pointer to an object of type of_bsn_tlv_circuit_id.
 * @param value Pointer to the child object of type
 * of_octets_t to be filled out.
 *
 */
void
of_bsn_tlv_circuit_id_value_get(
    of_bsn_tlv_circuit_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_CIRCUIT_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    LOCI_ASSERT(cur_len + abs_offset <= WBUF_CURRENT_BYTES(wbuf));
    value->bytes = cur_len;
    value->data = OF_WIRE_BUFFER_INDEX(wbuf, abs_offset);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_circuit_id.
 * @param obj Pointer to an object of type of_bsn_tlv_circuit_id.
 * @param value The value to write into the object
 */
int WARN_UNUSED_RESULT
of_bsn_tlv_circuit_id_value_set(
    of_bsn_tlv_circuit_id_t *obj,
    of_octets_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;
    int cur_len = 0; /* Current length of object data */
    int new_len, delta; /* For set, need new length and delta */

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_CIRCUIT_ID);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        cur_len = _END_LEN(obj, offset);
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    LOCI_ASSERT(cur_len >= 0 && cur_len < 64 * 1024);
    new_len = value->bytes;
    of_wire_buffer_grow(wbuf, abs_offset + (new_len - cur_len));
    of_wire_buffer_octets_data_set(wbuf, abs_offset, value, cur_len);

    /* Not scalar, update lengths if needed */
    delta = new_len - cur_len;
    if (delta != 0) {
        /* Update parent(s) */
        of_object_parent_length_update((of_object_t *)obj, delta);
    }

    OF_LENGTH_CHECK_ASSERT(obj);

    return OF_ERROR_NONE;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_idle_notification_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x7); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_idle_notification of_bsn_tlv_idle_notification
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_idle_notification_push_wire_values(of_bsn_tlv_idle_notification_t *obj)
{

    of_bsn_tlv_idle_notification_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_idle_notification object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_idle_notification
 */

of_bsn_tlv_idle_notification_t *
of_bsn_tlv_idle_notification_new(of_version_t version)
{
    of_bsn_tlv_idle_notification_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_NOTIFICATION] + of_object_extra_len[version][OF_BSN_TLV_IDLE_NOTIFICATION];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_idle_notification_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_idle_notification_init(obj, version, bytes, 0);

    if (of_bsn_tlv_idle_notification_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_idle_notification.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_idle_notification_init(of_bsn_tlv_idle_notification_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_IDLE_NOTIFICATION] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_NOTIFICATION] + of_object_extra_len[version][OF_BSN_TLV_IDLE_NOTIFICATION];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_IDLE_NOTIFICATION;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_idle_notification_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}

/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_idle_time_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x5); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_idle_time of_bsn_tlv_idle_time
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_idle_time_push_wire_values(of_bsn_tlv_idle_time_t *obj)
{

    of_bsn_tlv_idle_time_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_idle_time object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_idle_time
 */

of_bsn_tlv_idle_time_t *
of_bsn_tlv_idle_time_new(of_version_t version)
{
    of_bsn_tlv_idle_time_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIME] + of_object_extra_len[version][OF_BSN_TLV_IDLE_TIME];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_idle_time_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_idle_time_init(obj, version, bytes, 0);

    if (of_bsn_tlv_idle_time_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_idle_time.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_idle_time_init(of_bsn_tlv_idle_time_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIME] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIME] + of_object_extra_len[version][OF_BSN_TLV_IDLE_TIME];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_IDLE_TIME;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_idle_time_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_idle_time.
 * @param obj Pointer to an object of type of_bsn_tlv_idle_time.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_idle_time_value_get(
    of_bsn_tlv_idle_time_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IDLE_TIME);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_idle_time.
 * @param obj Pointer to an object of type of_bsn_tlv_idle_time.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_idle_time_value_set(
    of_bsn_tlv_idle_time_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IDLE_TIME);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_idle_timeout_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x8); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_idle_timeout of_bsn_tlv_idle_timeout
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_idle_timeout_push_wire_values(of_bsn_tlv_idle_timeout_t *obj)
{

    of_bsn_tlv_idle_timeout_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_idle_timeout object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_idle_timeout
 */

of_bsn_tlv_idle_timeout_t *
of_bsn_tlv_idle_timeout_new(of_version_t version)
{
    of_bsn_tlv_idle_timeout_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_IDLE_TIMEOUT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_idle_timeout_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_idle_timeout_init(obj, version, bytes, 0);

    if (of_bsn_tlv_idle_timeout_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_idle_timeout.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_idle_timeout_init(of_bsn_tlv_idle_timeout_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIMEOUT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_IDLE_TIMEOUT] + of_object_extra_len[version][OF_BSN_TLV_IDLE_TIMEOUT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_IDLE_TIMEOUT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_idle_timeout_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_idle_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_idle_timeout.
 * @param value Pointer to the child object of type
 * uint32_t to be filled out.
 *
 */
void
of_bsn_tlv_idle_timeout_value_get(
    of_bsn_tlv_idle_timeout_t *obj,
    uint32_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IDLE_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_idle_timeout.
 * @param obj Pointer to an object of type of_bsn_tlv_idle_timeout.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_idle_timeout_value_set(
    of_bsn_tlv_idle_timeout_t *obj,
    uint32_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IDLE_TIMEOUT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u32_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_ipv4_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x4); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_ipv4 of_bsn_tlv_ipv4
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_ipv4_push_wire_values(of_bsn_tlv_ipv4_t *obj)
{

    of_bsn_tlv_ipv4_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_ipv4 object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_ipv4
 */

of_bsn_tlv_ipv4_t *
of_bsn_tlv_ipv4_new(of_version_t version)
{
    of_bsn_tlv_ipv4_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_IPV4] + of_object_extra_len[version][OF_BSN_TLV_IPV4];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_ipv4_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_ipv4_init(obj, version, bytes, 0);

    if (of_bsn_tlv_ipv4_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_ipv4.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_ipv4_init(of_bsn_tlv_ipv4_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_IPV4] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_IPV4] + of_object_extra_len[version][OF_BSN_TLV_IPV4];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_IPV4;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_ipv4_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_ipv4.
 * @param obj Pointer to an object of type of_bsn_tlv_ipv4.
 * @param value Pointer to the child object of type
 * of_ipv4_t to be filled out.
 *
 */
void
of_bsn_tlv_ipv4_value_get(
    of_bsn_tlv_ipv4_t *obj,
    of_ipv4_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IPV4);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_ipv4.
 * @param obj Pointer to an object of type of_bsn_tlv_ipv4.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_ipv4_value_set(
    of_bsn_tlv_ipv4_t *obj,
    of_ipv4_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_IPV4);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_ipv4_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_mac_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x1); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_mac of_bsn_tlv_mac
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_mac_push_wire_values(of_bsn_tlv_mac_t *obj)
{

    of_bsn_tlv_mac_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_mac object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_mac
 */

of_bsn_tlv_mac_t *
of_bsn_tlv_mac_new(of_version_t version)
{
    of_bsn_tlv_mac_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_MAC] + of_object_extra_len[version][OF_BSN_TLV_MAC];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_mac_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_mac_init(obj, version, bytes, 0);

    if (of_bsn_tlv_mac_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_mac.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_mac_init(of_bsn_tlv_mac_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_MAC] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_MAC] + of_object_extra_len[version][OF_BSN_TLV_MAC];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_MAC;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_mac_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_mac.
 * @param obj Pointer to an object of type of_bsn_tlv_mac.
 * @param value Pointer to the child object of type
 * of_mac_addr_t to be filled out.
 *
 */
void
of_bsn_tlv_mac_value_get(
    of_bsn_tlv_mac_t *obj,
    of_mac_addr_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_MAC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_mac.
 * @param obj Pointer to an object of type of_bsn_tlv_mac.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_mac_value_set(
    of_bsn_tlv_mac_t *obj,
    of_mac_addr_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_MAC);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_mac_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_miss_packets_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0xd); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_miss_packets of_bsn_tlv_miss_packets
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_miss_packets_push_wire_values(of_bsn_tlv_miss_packets_t *obj)
{

    of_bsn_tlv_miss_packets_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_miss_packets object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_miss_packets
 */

of_bsn_tlv_miss_packets_t *
of_bsn_tlv_miss_packets_new(of_version_t version)
{
    of_bsn_tlv_miss_packets_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_MISS_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_MISS_PACKETS];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_miss_packets_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_miss_packets_init(obj, version, bytes, 0);

    if (of_bsn_tlv_miss_packets_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_miss_packets.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_miss_packets_init(of_bsn_tlv_miss_packets_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_MISS_PACKETS] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_MISS_PACKETS] + of_object_extra_len[version][OF_BSN_TLV_MISS_PACKETS];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_MISS_PACKETS;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_miss_packets_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_miss_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_miss_packets.
 * @param value Pointer to the child object of type
 * uint64_t to be filled out.
 *
 */
void
of_bsn_tlv_miss_packets_value_get(
    of_bsn_tlv_miss_packets_t *obj,
    uint64_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_MISS_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_get(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_miss_packets.
 * @param obj Pointer to an object of type of_bsn_tlv_miss_packets.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_miss_packets_value_set(
    of_bsn_tlv_miss_packets_t *obj,
    uint64_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_MISS_PACKETS);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_u64_set(wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
/* Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University */
/* Copyright (c) 2011, 2012 Open Networking Foundation */
/* Copyright (c) 2012, 2013 Big Switch Networks, Inc. */
/* See the file LICENSE.loci which should have been included in the source distribution */
#ifdef __GNUC__

#ifdef __linux__
/* glibc */
#include <features.h>
#else
/* NetBSD etc */
#include <sys/cdefs.h>
#ifdef __GNUC_PREREQ__
#define __GNUC_PREREQ __GNUC_PREREQ__
#endif
#endif

#ifndef __GNUC_PREREQ
/* fallback */
#define __GNUC_PREREQ(maj, min) 0
#endif

#if __GNUC_PREREQ(4,6)
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

#endif

#include "loci_log.h"
#include "loci_int.h"

static void
of_bsn_tlv_port_push_wire_types(of_object_t *obj)
{
    unsigned char *buf = OF_OBJECT_BUFFER_INDEX(obj, 0);
    switch (obj->version) {
    case OF_VERSION_1_3:
        *(uint16_t *)(buf + 0) = htobe16(0x0); /* type */
        break;
    default:
        UNREACHABLE();
    }
}


/**
 * \defgroup of_bsn_tlv_port of_bsn_tlv_port
 */

/**
 * Helper function to push values into the wire buffer
 */
static inline int
of_bsn_tlv_port_push_wire_values(of_bsn_tlv_port_t *obj)
{

    of_bsn_tlv_port_push_wire_types(obj);

    /* TLV obj; set length */
    of_tlv16_wire_length_set((of_object_t *)obj, obj->length);

    return OF_ERROR_NONE;
}

/**
 * Create a new of_bsn_tlv_port object
 *
 * @param version The wire version to use for the object
 * @return Pointer to the newly create object or NULL on error
 *
 * Initializes the new object with it's default fixed length associating
 * a new underlying wire buffer.
 *
 * Use new_from_message to bind an existing message to a message object,
 * or a _get function for non-message objects.
 *
 * \ingroup of_bsn_tlv_port
 */

of_bsn_tlv_port_t *
of_bsn_tlv_port_new(of_version_t version)
{
    of_bsn_tlv_port_t *obj;
    int bytes;

    bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT] + of_object_extra_len[version][OF_BSN_TLV_PORT];

    /* Allocate a maximum-length wire buffer assuming we'll be appending to it. */
    if ((obj = (of_bsn_tlv_port_t *)of_object_new(OF_WIRE_BUFFER_MAX_LENGTH)) == NULL) {
        return NULL;
    }

    of_bsn_tlv_port_init(obj, version, bytes, 0);

    if (of_bsn_tlv_port_push_wire_values(obj) < 0) {
        FREE(obj);
        return NULL;
    }

    return obj;
}

/**
 * Initialize an object of type of_bsn_tlv_port.
 *
 * @param obj Pointer to the object to initialize
 * @param version The wire version to use for the object
 * @param bytes How many bytes in the object
 * @param clean_wire Boolean: If true, clear the wire object control struct
 *
 * If bytes < 0, then the default fixed length is used for the object
 *
 * This is a "coerce" function that sets up the pointers for the
 * accessors properly.
 *
 * If anything other than 0 is passed in for the buffer size, the underlying
 * wire buffer will have 'grow' called.
 */

void
of_bsn_tlv_port_init(of_bsn_tlv_port_t *obj,
    of_version_t version, int bytes, int clean_wire)
{

    LOCI_ASSERT(of_object_fixed_len[version][OF_BSN_TLV_PORT] >= 0);
    if (clean_wire) {
        MEMSET(obj, 0, sizeof(*obj));
    }
    if (bytes < 0) {
        bytes = of_object_fixed_len[version][OF_BSN_TLV_PORT] + of_object_extra_len[version][OF_BSN_TLV_PORT];
    }
    obj->version = version;
    obj->length = bytes;
    obj->object_id = OF_BSN_TLV_PORT;

    /* Set up the object's function pointers */

    obj->wire_type_set = of_bsn_tlv_port_push_wire_types;

    obj->wire_length_set = of_tlv16_wire_length_set;

    obj->wire_length_get = of_tlv16_wire_length_get;

    obj->wire_type_get = of_bsn_tlv_wire_object_id_get;

    /* Grow the wire buffer */
    if (obj->wire_object.wbuf != NULL) {
        int tot_bytes;

        tot_bytes = bytes + obj->wire_object.obj_offset;
        of_wire_buffer_grow(obj->wire_object.wbuf, tot_bytes);
    }
}


/**
 * Get value from an object of type of_bsn_tlv_port.
 * @param obj Pointer to an object of type of_bsn_tlv_port.
 * @param value Pointer to the child object of type
 * of_port_no_t to be filled out.
 *
 */
void
of_bsn_tlv_port_value_get(
    of_bsn_tlv_port_t *obj,
    of_port_no_t *value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_get(ver, wbuf, abs_offset, value);
    OF_PORT_NO_VALUE_CHECK(*value, ver);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}

/**
 * Set value in an object of type of_bsn_tlv_port.
 * @param obj Pointer to an object of type of_bsn_tlv_port.
 * @param value The value to write into the object
 */
void
of_bsn_tlv_port_value_set(
    of_bsn_tlv_port_t *obj,
    of_port_no_t value)
{
    of_wire_buffer_t *wbuf;
    int offset = 0; /* Offset of value relative to the start obj */
    int abs_offset; /* Offset of value relative to start of wbuf */
    of_version_t ver;

    LOCI_ASSERT(obj->object_id == OF_BSN_TLV_PORT);
    ver = obj->version;
    wbuf = OF_OBJECT_TO_WBUF(obj);
    LOCI_ASSERT(wbuf != NULL);

    /* By version, determine offset and current length (where needed) */
    switch (ver) {
    case OF_VERSION_1_3:
        offset = 4;
        break;
    default:
        LOCI_ASSERT(0);
    }

    abs_offset = OF_OBJECT_ABSOLUTE_OFFSET(obj, offset);
    LOCI_ASSERT(abs_offset >= 0);
    of_wire_buffer_port_no_set(ver, wbuf, abs_offset, value);

    OF_LENGTH_CHECK_ASSERT(obj);

    return ;
}
