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
import org.projectfloodlight.openflow.protocol.OFBsnLoglevel;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFBsnLoglevelSerializerVer14 {

    public final static byte BSN_LOGLEVEL_MSG_VAL = (byte) 0x0;
    public final static byte BSN_LOGLEVEL_ERROR_VAL = (byte) 0x1;
    public final static byte BSN_LOGLEVEL_WARN_VAL = (byte) 0x2;
    public final static byte BSN_LOGLEVEL_INFO_VAL = (byte) 0x3;
    public final static byte BSN_LOGLEVEL_VERBOSE_VAL = (byte) 0x4;
    public final static byte BSN_LOGLEVEL_TRACE_VAL = (byte) 0x5;

    public static OFBsnLoglevel readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readByte());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFBsnLoglevel e) {
        bb.writeByte(toWireValue(e));
    }

    public static void putTo(OFBsnLoglevel e, PrimitiveSink sink) {
        sink.putByte(toWireValue(e));
    }

    public static OFBsnLoglevel ofWireValue(byte val) {
        switch(val) {
            case BSN_LOGLEVEL_MSG_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_MSG;
            case BSN_LOGLEVEL_ERROR_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_ERROR;
            case BSN_LOGLEVEL_WARN_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_WARN;
            case BSN_LOGLEVEL_INFO_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_INFO;
            case BSN_LOGLEVEL_VERBOSE_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_VERBOSE;
            case BSN_LOGLEVEL_TRACE_VAL:
                return OFBsnLoglevel.BSN_LOGLEVEL_TRACE;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFBsnLoglevel in version 1.4: " + val);
        }
    }


    public static byte toWireValue(OFBsnLoglevel e) {
        switch(e) {
            case BSN_LOGLEVEL_MSG:
                return BSN_LOGLEVEL_MSG_VAL;
            case BSN_LOGLEVEL_ERROR:
                return BSN_LOGLEVEL_ERROR_VAL;
            case BSN_LOGLEVEL_WARN:
                return BSN_LOGLEVEL_WARN_VAL;
            case BSN_LOGLEVEL_INFO:
                return BSN_LOGLEVEL_INFO_VAL;
            case BSN_LOGLEVEL_VERBOSE:
                return BSN_LOGLEVEL_VERBOSE_VAL;
            case BSN_LOGLEVEL_TRACE:
                return BSN_LOGLEVEL_TRACE_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFBsnLoglevel in version 1.4: " + e);
        }
    }

}
