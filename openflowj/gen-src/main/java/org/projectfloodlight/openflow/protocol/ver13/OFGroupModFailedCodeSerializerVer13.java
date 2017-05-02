// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_serializer.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.projectfloodlight.openflow.protocol.OFGroupModFailedCode;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFGroupModFailedCodeSerializerVer13 {

    public final static short GROUP_EXISTS_VAL = (short) 0x0;
    public final static short INVALID_GROUP_VAL = (short) 0x1;
    public final static short WEIGHT_UNSUPPORTED_VAL = (short) 0x2;
    public final static short OUT_OF_GROUPS_VAL = (short) 0x3;
    public final static short OUT_OF_BUCKETS_VAL = (short) 0x4;
    public final static short CHAINING_UNSUPPORTED_VAL = (short) 0x5;
    public final static short WATCH_UNSUPPORTED_VAL = (short) 0x6;
    public final static short LOOP_VAL = (short) 0x7;
    public final static short UNKNOWN_GROUP_VAL = (short) 0x8;
    public final static short CHAINED_GROUP_VAL = (short) 0x9;
    public final static short BAD_TYPE_VAL = (short) 0xa;
    public final static short BAD_COMMAND_VAL = (short) 0xb;
    public final static short BAD_BUCKET_VAL = (short) 0xc;
    public final static short BAD_WATCH_VAL = (short) 0xd;
    public final static short EPERM_VAL = (short) 0xe;

    public static OFGroupModFailedCode readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readShort());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFGroupModFailedCode e) {
        bb.writeShort(toWireValue(e));
    }

    public static void putTo(OFGroupModFailedCode e, PrimitiveSink sink) {
        sink.putShort(toWireValue(e));
    }

    public static OFGroupModFailedCode ofWireValue(short val) {
        switch(val) {
            case GROUP_EXISTS_VAL:
                return OFGroupModFailedCode.GROUP_EXISTS;
            case INVALID_GROUP_VAL:
                return OFGroupModFailedCode.INVALID_GROUP;
            case WEIGHT_UNSUPPORTED_VAL:
                return OFGroupModFailedCode.WEIGHT_UNSUPPORTED;
            case OUT_OF_GROUPS_VAL:
                return OFGroupModFailedCode.OUT_OF_GROUPS;
            case OUT_OF_BUCKETS_VAL:
                return OFGroupModFailedCode.OUT_OF_BUCKETS;
            case CHAINING_UNSUPPORTED_VAL:
                return OFGroupModFailedCode.CHAINING_UNSUPPORTED;
            case WATCH_UNSUPPORTED_VAL:
                return OFGroupModFailedCode.WATCH_UNSUPPORTED;
            case LOOP_VAL:
                return OFGroupModFailedCode.LOOP;
            case UNKNOWN_GROUP_VAL:
                return OFGroupModFailedCode.UNKNOWN_GROUP;
            case CHAINED_GROUP_VAL:
                return OFGroupModFailedCode.CHAINED_GROUP;
            case BAD_TYPE_VAL:
                return OFGroupModFailedCode.BAD_TYPE;
            case BAD_COMMAND_VAL:
                return OFGroupModFailedCode.BAD_COMMAND;
            case BAD_BUCKET_VAL:
                return OFGroupModFailedCode.BAD_BUCKET;
            case BAD_WATCH_VAL:
                return OFGroupModFailedCode.BAD_WATCH;
            case EPERM_VAL:
                return OFGroupModFailedCode.EPERM;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFGroupModFailedCode in version 1.3: " + val);
        }
    }


    public static short toWireValue(OFGroupModFailedCode e) {
        switch(e) {
            case GROUP_EXISTS:
                return GROUP_EXISTS_VAL;
            case INVALID_GROUP:
                return INVALID_GROUP_VAL;
            case WEIGHT_UNSUPPORTED:
                return WEIGHT_UNSUPPORTED_VAL;
            case OUT_OF_GROUPS:
                return OUT_OF_GROUPS_VAL;
            case OUT_OF_BUCKETS:
                return OUT_OF_BUCKETS_VAL;
            case CHAINING_UNSUPPORTED:
                return CHAINING_UNSUPPORTED_VAL;
            case WATCH_UNSUPPORTED:
                return WATCH_UNSUPPORTED_VAL;
            case LOOP:
                return LOOP_VAL;
            case UNKNOWN_GROUP:
                return UNKNOWN_GROUP_VAL;
            case CHAINED_GROUP:
                return CHAINED_GROUP_VAL;
            case BAD_TYPE:
                return BAD_TYPE_VAL;
            case BAD_COMMAND:
                return BAD_COMMAND_VAL;
            case BAD_BUCKET:
                return BAD_BUCKET_VAL;
            case BAD_WATCH:
                return BAD_WATCH_VAL;
            case EPERM:
                return EPERM_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFGroupModFailedCode in version 1.3: " + e);
        }
    }

}