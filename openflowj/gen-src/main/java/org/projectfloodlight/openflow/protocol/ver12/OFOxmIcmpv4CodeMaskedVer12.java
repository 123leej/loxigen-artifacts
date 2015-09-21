// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver12;

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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmIcmpv4CodeMaskedVer12 implements OFOxmIcmpv4CodeMasked {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmIcmpv4CodeMaskedVer12.class);
    // version: 1.2
    final static byte WIRE_VERSION = 3;
    final static int LENGTH = 6;

        private final static ICMPv4Code DEFAULT_VALUE = ICMPv4Code.NONE;
        private final static ICMPv4Code DEFAULT_VALUE_MASK = ICMPv4Code.NONE;

    // OF message fields
    private final ICMPv4Code value;
    private final ICMPv4Code mask;
//
    // Immutable default instance
    final static OFOxmIcmpv4CodeMaskedVer12 DEFAULT = new OFOxmIcmpv4CodeMaskedVer12(
        DEFAULT_VALUE, DEFAULT_VALUE_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmIcmpv4CodeMaskedVer12(ICMPv4Code value, ICMPv4Code mask) {
        if(value == null) {
            throw new NullPointerException("OFOxmIcmpv4CodeMaskedVer12: property value cannot be null");
        }
        if(mask == null) {
            throw new NullPointerException("OFOxmIcmpv4CodeMaskedVer12: property mask cannot be null");
        }
        this.value = value;
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80002902L;
    }

    @Override
    public ICMPv4Code getValue() {
        return value;
    }

    @Override
    public ICMPv4Code getMask() {
        return mask;
    }

    @Override
    public MatchField<ICMPv4Code> getMatchField() {
        return MatchField.ICMPV4_CODE;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    public OFOxm<ICMPv4Code> getCanonical() {
        if (ICMPv4Code.NO_MASK.equals(mask)) {
            return new OFOxmIcmpv4CodeVer12(value);
        } else if(ICMPv4Code.FULL_MASK.equals(mask)) {
            return null;
        } else {
            return this;
        }
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



    public OFOxmIcmpv4CodeMasked.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmIcmpv4CodeMasked.Builder {
        final OFOxmIcmpv4CodeMaskedVer12 parentMessage;

        // OF message fields
        private boolean valueSet;
        private ICMPv4Code value;
        private boolean maskSet;
        private ICMPv4Code mask;

        BuilderWithParent(OFOxmIcmpv4CodeMaskedVer12 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80002902L;
    }

    @Override
    public ICMPv4Code getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4CodeMasked.Builder setValue(ICMPv4Code value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public ICMPv4Code getMask() {
        return mask;
    }

    @Override
    public OFOxmIcmpv4CodeMasked.Builder setMask(ICMPv4Code mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<ICMPv4Code> getMatchField() {
        return MatchField.ICMPV4_CODE;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<ICMPv4Code> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }



        @Override
        public OFOxmIcmpv4CodeMasked build() {
                ICMPv4Code value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");
                ICMPv4Code mask = this.maskSet ? this.mask : parentMessage.mask;
                if(mask == null)
                    throw new NullPointerException("Property mask must not be null");

                //
                return new OFOxmIcmpv4CodeMaskedVer12(
                    value,
                    mask
                );
        }

    }

    static class Builder implements OFOxmIcmpv4CodeMasked.Builder {
        // OF message fields
        private boolean valueSet;
        private ICMPv4Code value;
        private boolean maskSet;
        private ICMPv4Code mask;

    @Override
    public long getTypeLen() {
        return 0x80002902L;
    }

    @Override
    public ICMPv4Code getValue() {
        return value;
    }

    @Override
    public OFOxmIcmpv4CodeMasked.Builder setValue(ICMPv4Code value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public ICMPv4Code getMask() {
        return mask;
    }

    @Override
    public OFOxmIcmpv4CodeMasked.Builder setMask(ICMPv4Code mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public MatchField<ICMPv4Code> getMatchField() {
        return MatchField.ICMPV4_CODE;
    }

    @Override
    public boolean isMasked() {
        return true;
    }

    @Override
    public OFOxm<ICMPv4Code> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.2");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_12;
    }

//
        @Override
        public OFOxmIcmpv4CodeMasked build() {
            ICMPv4Code value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");
            ICMPv4Code mask = this.maskSet ? this.mask : DEFAULT_VALUE_MASK;
            if(mask == null)
                throw new NullPointerException("Property mask must not be null");


            return new OFOxmIcmpv4CodeMaskedVer12(
                    value,
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmIcmpv4CodeMasked> {
        @Override
        public OFOxmIcmpv4CodeMasked readFrom(ByteBuf bb) throws OFParseError {
            // fixed value property typeLen == 0x80002902L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80002902)
                throw new OFParseError("Wrong typeLen: Expected=0x80002902L(0x80002902L), got="+typeLen);
            ICMPv4Code value = ICMPv4Code.readByte(bb);
            ICMPv4Code mask = ICMPv4Code.readByte(bb);

            OFOxmIcmpv4CodeMaskedVer12 oxmIcmpv4CodeMaskedVer12 = new OFOxmIcmpv4CodeMaskedVer12(
                    value,
                      mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmIcmpv4CodeMaskedVer12);
            return oxmIcmpv4CodeMaskedVer12;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmIcmpv4CodeMaskedVer12Funnel FUNNEL = new OFOxmIcmpv4CodeMaskedVer12Funnel();
    static class OFOxmIcmpv4CodeMaskedVer12Funnel implements Funnel<OFOxmIcmpv4CodeMaskedVer12> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmIcmpv4CodeMaskedVer12 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80002902L
            sink.putInt((int) 0x80002902);
            message.value.putTo(sink);
            message.mask.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmIcmpv4CodeMaskedVer12> {
        @Override
        public void write(ByteBuf bb, OFOxmIcmpv4CodeMaskedVer12 message) {
            // fixed value property typeLen = 0x80002902L
            bb.writeInt((int) 0x80002902);
            message.value.writeByte(bb);
            message.mask.writeByte(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmIcmpv4CodeMaskedVer12(");
        b.append("value=").append(value);
        b.append(", ");
        b.append("mask=").append(mask);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFOxmIcmpv4CodeMaskedVer12 other = (OFOxmIcmpv4CodeMaskedVer12) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        if (mask == null) {
            if (other.mask != null)
                return false;
        } else if (!mask.equals(other.mask))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        result = prime * result + ((mask == null) ? 0 : mask.hashCode());
        return result;
    }

}
