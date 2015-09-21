// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_serializer.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver14;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.projectfloodlight.openflow.protocol.OFFlowModFailedCode;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFFlowModFailedCodeSerializerVer14 {

    public final static short UNKNOWN_VAL = (short) 0x0;
    public final static short TABLE_FULL_VAL = (short) 0x1;
    public final static short BAD_TABLE_ID_VAL = (short) 0x2;
    public final static short OVERLAP_VAL = (short) 0x3;
    public final static short EPERM_VAL = (short) 0x4;
    public final static short BAD_TIMEOUT_VAL = (short) 0x5;
    public final static short BAD_COMMAND_VAL = (short) 0x6;
    public final static short BAD_FLAGS_VAL = (short) 0x7;
    public final static short CANT_SYNC_VAL = (short) 0x8;
    public final static short BAD_PRIORITY_VAL = (short) 0x9;

    public static OFFlowModFailedCode readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readShort());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFFlowModFailedCode e) {
        bb.writeShort(toWireValue(e));
    }

    public static void putTo(OFFlowModFailedCode e, PrimitiveSink sink) {
        sink.putShort(toWireValue(e));
    }

    public static OFFlowModFailedCode ofWireValue(short val) {
        switch(val) {
            case UNKNOWN_VAL:
                return OFFlowModFailedCode.UNKNOWN;
            case TABLE_FULL_VAL:
                return OFFlowModFailedCode.TABLE_FULL;
            case BAD_TABLE_ID_VAL:
                return OFFlowModFailedCode.BAD_TABLE_ID;
            case OVERLAP_VAL:
                return OFFlowModFailedCode.OVERLAP;
            case EPERM_VAL:
                return OFFlowModFailedCode.EPERM;
            case BAD_TIMEOUT_VAL:
                return OFFlowModFailedCode.BAD_TIMEOUT;
            case BAD_COMMAND_VAL:
                return OFFlowModFailedCode.BAD_COMMAND;
            case BAD_FLAGS_VAL:
                return OFFlowModFailedCode.BAD_FLAGS;
            case CANT_SYNC_VAL:
                return OFFlowModFailedCode.CANT_SYNC;
            case BAD_PRIORITY_VAL:
                return OFFlowModFailedCode.BAD_PRIORITY;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFFlowModFailedCode in version 1.4: " + val);
        }
    }


    public static short toWireValue(OFFlowModFailedCode e) {
        switch(e) {
            case UNKNOWN:
                return UNKNOWN_VAL;
            case TABLE_FULL:
                return TABLE_FULL_VAL;
            case BAD_TABLE_ID:
                return BAD_TABLE_ID_VAL;
            case OVERLAP:
                return OVERLAP_VAL;
            case EPERM:
                return EPERM_VAL;
            case BAD_TIMEOUT:
                return BAD_TIMEOUT_VAL;
            case BAD_COMMAND:
                return BAD_COMMAND_VAL;
            case BAD_FLAGS:
                return BAD_FLAGS_VAL;
            case CANT_SYNC:
                return CANT_SYNC_VAL;
            case BAD_PRIORITY:
                return BAD_PRIORITY_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFFlowModFailedCode in version 1.4: " + e);
        }
    }

}
