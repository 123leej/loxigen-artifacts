// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import com.google.common.collect.ImmutableSet;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvHashPacketFieldVer14 implements OFBsnTlvHashPacketField {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvHashPacketFieldVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 12;

        private final static Set<OFBsnHashPacketField> DEFAULT_VALUE = ImmutableSet.<OFBsnHashPacketField>of();

    // OF message fields
    private final Set<OFBsnHashPacketField> value;
//
    // Immutable default instance
    final static OFBsnTlvHashPacketFieldVer14 DEFAULT = new OFBsnTlvHashPacketFieldVer14(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvHashPacketFieldVer14(Set<OFBsnHashPacketField> value) {
        if(value == null) {
            throw new NullPointerException("OFBsnTlvHashPacketFieldVer14: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x67;
    }

    @Override
    public Set<OFBsnHashPacketField> getValue() {
        return value;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFBsnTlvHashPacketField.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvHashPacketField.Builder {
        final OFBsnTlvHashPacketFieldVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private Set<OFBsnHashPacketField> value;

        BuilderWithParent(OFBsnTlvHashPacketFieldVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x67;
    }

    @Override
    public Set<OFBsnHashPacketField> getValue() {
        return value;
    }

    @Override
    public OFBsnTlvHashPacketField.Builder setValue(Set<OFBsnHashPacketField> value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFBsnTlvHashPacketField build() {
                Set<OFBsnHashPacketField> value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFBsnTlvHashPacketFieldVer14(
                    value
                );
        }

    }

    static class Builder implements OFBsnTlvHashPacketField.Builder {
        // OF message fields
        private boolean valueSet;
        private Set<OFBsnHashPacketField> value;

    @Override
    public int getType() {
        return 0x67;
    }

    @Override
    public Set<OFBsnHashPacketField> getValue() {
        return value;
    }

    @Override
    public OFBsnTlvHashPacketField.Builder setValue(Set<OFBsnHashPacketField> value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFBsnTlvHashPacketField build() {
            Set<OFBsnHashPacketField> value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFBsnTlvHashPacketFieldVer14(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvHashPacketField> {
        @Override
        public OFBsnTlvHashPacketField readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x67
            short type = bb.readShort();
            if(type != (short) 0x67)
                throw new OFParseError("Wrong type: Expected=0x67(0x67), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 12)
                throw new OFParseError("Wrong length: Expected=12(12), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            Set<OFBsnHashPacketField> value = OFBsnHashPacketFieldSerializerVer14.readFrom(bb);

            OFBsnTlvHashPacketFieldVer14 bsnTlvHashPacketFieldVer14 = new OFBsnTlvHashPacketFieldVer14(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvHashPacketFieldVer14);
            return bsnTlvHashPacketFieldVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvHashPacketFieldVer14Funnel FUNNEL = new OFBsnTlvHashPacketFieldVer14Funnel();
    static class OFBsnTlvHashPacketFieldVer14Funnel implements Funnel<OFBsnTlvHashPacketFieldVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvHashPacketFieldVer14 message, PrimitiveSink sink) {
            // fixed value property type = 0x67
            sink.putShort((short) 0x67);
            // fixed value property length = 12
            sink.putShort((short) 0xc);
            OFBsnHashPacketFieldSerializerVer14.putTo(message.value, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvHashPacketFieldVer14> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvHashPacketFieldVer14 message) {
            // fixed value property type = 0x67
            bb.writeShort((short) 0x67);
            // fixed value property length = 12
            bb.writeShort((short) 0xc);
            OFBsnHashPacketFieldSerializerVer14.writeTo(bb, message.value);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvHashPacketFieldVer14(");
        b.append("value=").append(value);
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
        OFBsnTlvHashPacketFieldVer14 other = (OFBsnTlvHashPacketFieldVer14) obj;

        if (value == null) {
            if (other.value != null)
                return false;
        } else if (!value.equals(other.value))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((value == null) ? 0 : value.hashCode());
        return result;
    }

}