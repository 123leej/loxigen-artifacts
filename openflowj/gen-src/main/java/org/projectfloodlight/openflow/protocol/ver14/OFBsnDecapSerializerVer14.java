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
import org.projectfloodlight.openflow.protocol.OFBsnDecap;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;

public class OFBsnDecapSerializerVer14 {

    public final static short BSN_DECAP_VXLAN_VAL = (short) 0x0;
    public final static short BSN_DECAP_ERSPAN_VAL = (short) 0x1;
    public final static short BSN_DECAP_L2_GRE_VAL = (short) 0x2;
    public final static short BSN_DECAP_NVGRE_VAL = (short) 0x3;
    public final static short BSN_DECAP_CAPWAP_VAL = (short) 0x4;
    public final static short BSN_DECAP_L2_MPLS_VAL = (short) 0x5;
    public final static short BSN_DECAP_L3_GRE_VAL = (short) 0x6;
    public final static short BSN_DECAP_GTP_VAL = (short) 0x7;
    public final static short BSN_DECAP_L3_MPLS_VAL = (short) 0x8;

    public static OFBsnDecap readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readShort());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, OFBsnDecap e) {
        bb.writeShort(toWireValue(e));
    }

    public static void putTo(OFBsnDecap e, PrimitiveSink sink) {
        sink.putShort(toWireValue(e));
    }

    public static OFBsnDecap ofWireValue(short val) {
        switch(val) {
            case BSN_DECAP_VXLAN_VAL:
                return OFBsnDecap.BSN_DECAP_VXLAN;
            case BSN_DECAP_ERSPAN_VAL:
                return OFBsnDecap.BSN_DECAP_ERSPAN;
            case BSN_DECAP_L2_GRE_VAL:
                return OFBsnDecap.BSN_DECAP_L2_GRE;
            case BSN_DECAP_NVGRE_VAL:
                return OFBsnDecap.BSN_DECAP_NVGRE;
            case BSN_DECAP_CAPWAP_VAL:
                return OFBsnDecap.BSN_DECAP_CAPWAP;
            case BSN_DECAP_L2_MPLS_VAL:
                return OFBsnDecap.BSN_DECAP_L2_MPLS;
            case BSN_DECAP_L3_GRE_VAL:
                return OFBsnDecap.BSN_DECAP_L3_GRE;
            case BSN_DECAP_GTP_VAL:
                return OFBsnDecap.BSN_DECAP_GTP;
            case BSN_DECAP_L3_MPLS_VAL:
                return OFBsnDecap.BSN_DECAP_L3_MPLS;
            default:
                throw new IllegalArgumentException("Illegal wire value for type OFBsnDecap in version 1.4: " + val);
        }
    }


    public static short toWireValue(OFBsnDecap e) {
        switch(e) {
            case BSN_DECAP_VXLAN:
                return BSN_DECAP_VXLAN_VAL;
            case BSN_DECAP_ERSPAN:
                return BSN_DECAP_ERSPAN_VAL;
            case BSN_DECAP_L2_GRE:
                return BSN_DECAP_L2_GRE_VAL;
            case BSN_DECAP_NVGRE:
                return BSN_DECAP_NVGRE_VAL;
            case BSN_DECAP_CAPWAP:
                return BSN_DECAP_CAPWAP_VAL;
            case BSN_DECAP_L2_MPLS:
                return BSN_DECAP_L2_MPLS_VAL;
            case BSN_DECAP_L3_GRE:
                return BSN_DECAP_L3_GRE_VAL;
            case BSN_DECAP_GTP:
                return BSN_DECAP_GTP_VAL;
            case BSN_DECAP_L3_MPLS:
                return BSN_DECAP_L3_MPLS_VAL;
            default:
                throw new IllegalArgumentException("Illegal enum value for type OFBsnDecap in version 1.4: " + e);
        }
    }

}
