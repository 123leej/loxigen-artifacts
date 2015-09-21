// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template const_set_serializer.java
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
import org.projectfloodlight.openflow.protocol.OFTableModPropEvictionFlag;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import java.util.EnumSet;
import java.util.Collections;


public class OFTableModPropEvictionFlagSerializerVer14 {

    public final static int OTHER_VAL = 0x1;
    public final static int IMPORTANCE_VAL = 0x2;
    public final static int LIFETIME_VAL = 0x4;

    public static Set<OFTableModPropEvictionFlag> readFrom(ByteBuf bb) throws OFParseError {
        try {
            return ofWireValue(bb.readInt());
        } catch (IllegalArgumentException e) {
            throw new OFParseError(e);
        }
    }

    public static void writeTo(ByteBuf bb, Set<OFTableModPropEvictionFlag> set) {
        bb.writeInt(toWireValue(set));
    }

    public static void putTo(Set<OFTableModPropEvictionFlag> set, PrimitiveSink sink) {
        sink.putInt(toWireValue(set));
    }


    public static Set<OFTableModPropEvictionFlag> ofWireValue(int val) {
        EnumSet<OFTableModPropEvictionFlag> set = EnumSet.noneOf(OFTableModPropEvictionFlag.class);

        if((val & OTHER_VAL) != 0)
            set.add(OFTableModPropEvictionFlag.OTHER);
        if((val & IMPORTANCE_VAL) != 0)
            set.add(OFTableModPropEvictionFlag.IMPORTANCE);
        if((val & LIFETIME_VAL) != 0)
            set.add(OFTableModPropEvictionFlag.LIFETIME);
        return Collections.unmodifiableSet(set);
    }

    public static int toWireValue(Set<OFTableModPropEvictionFlag> set) {
        int wireValue = 0;

        for(OFTableModPropEvictionFlag e: set) {
            switch(e) {
                case OTHER:
                    wireValue |= OTHER_VAL;
                    break;
                case IMPORTANCE:
                    wireValue |= IMPORTANCE_VAL;
                    break;
                case LIFETIME:
                    wireValue |= LIFETIME_VAL;
                    break;
                default:
                    throw new IllegalArgumentException("Illegal enum value for type OFTableModPropEvictionFlag in version 1.4: " + e);
            }
        }
        return wireValue;
    }

}
