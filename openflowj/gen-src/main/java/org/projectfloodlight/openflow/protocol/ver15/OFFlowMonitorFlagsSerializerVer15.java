// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_set_serializer.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

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
import org.projectfloodlight.openflow.protocol.OFFlowMonitorFlags;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import java.util.EnumSet;
import java.util.Collections;


public class OFFlowMonitorFlagsSerializerVer15 {

    public final static short INITIAL_VAL = (short) 0x1;
    public final static short ADD_VAL = (short) 0x2;
    public final static short REMOVED_VAL = (short) 0x4;
    public final static short MODIFY_VAL = (short) 0x8;
    public final static short INSTRUCTIONS_VAL = (short) 0x10;
    public final static short NO_ABBREV_VAL = (short) 0x20;
    public final static short ONLY_OWN_VAL = (short) 0x40;

    public static Set<OFFlowMonitorFlags> readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readShort());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, Set<OFFlowMonitorFlags> set) {
        bb.writeShort(toWireValue(set));
    }

    public static void putTo(Set<OFFlowMonitorFlags> set, PrimitiveSink sink) {
        sink.putShort(toWireValue(set));
    }


    public static Set<OFFlowMonitorFlags> ofWireValue(short val) {
        EnumSet<OFFlowMonitorFlags> set = EnumSet.noneOf(OFFlowMonitorFlags.class);

        if((val & INITIAL_VAL) != 0)
            set.add(OFFlowMonitorFlags.INITIAL);
        if((val & ADD_VAL) != 0)
            set.add(OFFlowMonitorFlags.ADD);
        if((val & REMOVED_VAL) != 0)
            set.add(OFFlowMonitorFlags.REMOVED);
        if((val & MODIFY_VAL) != 0)
            set.add(OFFlowMonitorFlags.MODIFY);
        if((val & INSTRUCTIONS_VAL) != 0)
            set.add(OFFlowMonitorFlags.INSTRUCTIONS);
        if((val & NO_ABBREV_VAL) != 0)
            set.add(OFFlowMonitorFlags.NO_ABBREV);
        if((val & ONLY_OWN_VAL) != 0)
            set.add(OFFlowMonitorFlags.ONLY_OWN);
        return Collections.unmodifiableSet(set);
    }

    public static short toWireValue(Set<OFFlowMonitorFlags> set) {
        short wireValue = 0;

        for(OFFlowMonitorFlags e: set) {
            switch(e) {
                case INITIAL:
                    wireValue |= INITIAL_VAL;
                    break;
                case ADD:
                    wireValue |= ADD_VAL;
                    break;
                case REMOVED:
                    wireValue |= REMOVED_VAL;
                    break;
                case MODIFY:
                    wireValue |= MODIFY_VAL;
                    break;
                case INSTRUCTIONS:
                    wireValue |= INSTRUCTIONS_VAL;
                    break;
                case NO_ABBREV:
                    wireValue |= NO_ABBREV_VAL;
                    break;
                case ONLY_OWN:
                    wireValue |= ONLY_OWN_VAL;
                    break;
                default:
                    throw new IllegalArgumentException("Illegal enum value for type OFFlowMonitorFlags in version 1.5: " + e);
            }
        }
        return wireValue;
    }

}
