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
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFBsnTlvLoopbackPortVer14 implements OFBsnTlvLoopbackPort {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnTlvLoopbackPortVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 8;

        private final static OFPort DEFAULT_VALUE = OFPort.ANY;

    // OF message fields
    private final OFPort value;
//
    // Immutable default instance
    final static OFBsnTlvLoopbackPortVer14 DEFAULT = new OFBsnTlvLoopbackPortVer14(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnTlvLoopbackPortVer14(OFPort value) {
        if(value == null) {
            throw new NullPointerException("OFBsnTlvLoopbackPortVer14: property value cannot be null");
        }
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x6e;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFBsnTlvLoopbackPort.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnTlvLoopbackPort.Builder {
        final OFBsnTlvLoopbackPortVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFPort value;

        BuilderWithParent(OFBsnTlvLoopbackPortVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x6e;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFBsnTlvLoopbackPort.Builder setValue(OFPort value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFBsnTlvLoopbackPort build() {
                OFPort value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFBsnTlvLoopbackPortVer14(
                    value
                );
        }

    }

    static class Builder implements OFBsnTlvLoopbackPort.Builder {
        // OF message fields
        private boolean valueSet;
        private OFPort value;

    @Override
    public int getType() {
        return 0x6e;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFBsnTlvLoopbackPort.Builder setValue(OFPort value) {
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
        public OFBsnTlvLoopbackPort build() {
            OFPort value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFBsnTlvLoopbackPortVer14(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnTlvLoopbackPort> {
        @Override
        public OFBsnTlvLoopbackPort readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x6e
            short type = bb.readShort();
            if(type != (short) 0x6e)
                throw new OFParseError("Wrong type: Expected=0x6e(0x6e), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 8)
                throw new OFParseError("Wrong length: Expected=8(8), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            OFPort value = OFPort.read4Bytes(bb);

            OFBsnTlvLoopbackPortVer14 bsnTlvLoopbackPortVer14 = new OFBsnTlvLoopbackPortVer14(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnTlvLoopbackPortVer14);
            return bsnTlvLoopbackPortVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnTlvLoopbackPortVer14Funnel FUNNEL = new OFBsnTlvLoopbackPortVer14Funnel();
    static class OFBsnTlvLoopbackPortVer14Funnel implements Funnel<OFBsnTlvLoopbackPortVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnTlvLoopbackPortVer14 message, PrimitiveSink sink) {
            // fixed value property type = 0x6e
            sink.putShort((short) 0x6e);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnTlvLoopbackPortVer14> {
        @Override
        public void write(ByteBuf bb, OFBsnTlvLoopbackPortVer14 message) {
            // fixed value property type = 0x6e
            bb.writeShort((short) 0x6e);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnTlvLoopbackPortVer14(");
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
        OFBsnTlvLoopbackPortVer14 other = (OFBsnTlvLoopbackPortVer14) obj;

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
