// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvRxPacketsVer13 implements OFBsnTlvRxPackets {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvRxPacketsVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 12;

        private final static U64 DEFAULT_VALUE = U64.ZERO;

    // OF message fields
    private final U64 value;
//
    // Immutable default instance
    final static OFBsnTlvRxPacketsVer13 DEFAULT = new OFBsnTlvRxPacketsVer13(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvRxPacketsVer13(U64 value) {
        if(value == null) {
            throw new NullPointerException("OFBsnTlvRxPacketsVer13: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x2;
    }

    @Override
    public U64 getValue() {
        return value;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



    public OFBsnTlvRxPackets.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvRxPackets.Builder {
        final OFBsnTlvRxPacketsVer13 parentMessage;

        // OF message fields
        private boolean valueSet;
        private U64 value;

        BuilderWithParent(OFBsnTlvRxPacketsVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x2;
    }

    @Override
    public U64 getValue() {
        return value;
    }

    @Override
    public OFBsnTlvRxPackets.Builder setValue(U64 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }



        @Override
        public OFBsnTlvRxPackets build() {
                U64 value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFBsnTlvRxPacketsVer13(
                    value
                );
        }

    }

    static class Builder implements OFBsnTlvRxPackets.Builder {
        // OF message fields
        private boolean valueSet;
        private U64 value;

    @Override
    public int getType() {
        return 0x2;
    }

    @Override
    public U64 getValue() {
        return value;
    }

    @Override
    public OFBsnTlvRxPackets.Builder setValue(U64 value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

//
        @Override
        public OFBsnTlvRxPackets build() {
            U64 value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFBsnTlvRxPacketsVer13(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvRxPackets> {
        @Override
        public OFBsnTlvRxPackets readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x2
            short type = bb.readShort();
            if(type != (short) 0x2)
                throw new OFParseError("Wrong type: Expected=0x2(0x2), got="+type);
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
            U64 value = U64.ofRaw(bb.readLong());

            OFBsnTlvRxPacketsVer13 bsnTlvRxPacketsVer13 = new OFBsnTlvRxPacketsVer13(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvRxPacketsVer13);
            return bsnTlvRxPacketsVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvRxPacketsVer13Funnel FUNNEL = new OFBsnTlvRxPacketsVer13Funnel();
    static class OFBsnTlvRxPacketsVer13Funnel implements Funnel<OFBsnTlvRxPacketsVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvRxPacketsVer13 message, PrimitiveSink sink) {
            // fixed value property type = 0x2
            sink.putShort((short) 0x2);
            // fixed value property length = 12
            sink.putShort((short) 0xc);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvRxPacketsVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvRxPacketsVer13 message) {
            // fixed value property type = 0x2
            bb.writeShort((short) 0x2);
            // fixed value property length = 12
            bb.writeShort((short) 0xc);
            bb.writeLong(message.value.getValue());


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvRxPacketsVer13(");
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
        OFBsnTlvRxPacketsVer13 other = (OFBsnTlvRxPacketsVer13) obj;

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
