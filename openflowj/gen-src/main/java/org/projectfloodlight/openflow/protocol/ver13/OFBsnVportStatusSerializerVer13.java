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
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.projectfloodlight.openflow.protocol.OFBsnVportStatus;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFBsnVportStatusSerializerVer13 {

    public final static short BSN_VPORT_STATUS_OK_VAL = (short) 0x0;
    public final static short BSN_VPORT_STATUS_FAILED_VAL = (short) 0x1;

    public static OFBsnVportStatus readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(U8.f(bb.readByte()));
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFBsnVportStatus e) {
        bb.writeByte(U8.t(toWireValue(e)));
    }

    public static void putTo(OFBsnVportStatus e, PrimitiveSink sink) {
        sink.putShort(toWireValue(e));
    }

    public static OFBsnVportStatus ofWireValue(short val) {
        switch(val) {
            case BSN_VPORT_STATUS_OK_VAL:
                return OFBsnVportStatus.BSN_VPORT_STATUS_OK;
            case BSN_VPORT_STATUS_FAILED_VAL:
                return OFBsnVportStatus.BSN_VPORT_STATUS_FAILED;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFBsnVportStatus in version 1.3: " + val);
        }
    }


    public static short toWireValue(OFBsnVportStatus e) {
        switch(e) {
            case BSN_VPORT_STATUS_OK:
                return BSN_VPORT_STATUS_OK_VAL;
            case BSN_VPORT_STATUS_FAILED:
                return BSN_VPORT_STATUS_FAILED_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFBsnVportStatus in version 1.3: " + e);
        }
    }

}
