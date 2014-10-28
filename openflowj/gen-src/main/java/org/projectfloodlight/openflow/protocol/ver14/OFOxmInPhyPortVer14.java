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
import org.jboss.netty.buffer.ChannelBuffer;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFOxmInPhyPortVer14 implements OFOxmInPhyPort {
    private static final Logger logger = LoggerFactory.getLogger(OFOxmInPhyPortVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 8;

        private final static OFPort DEFAULT_VALUE = OFPort.ANY;

    // OF message fields
    private final OFPort value;
//
    // Immutable default instance
    final static OFOxmInPhyPortVer14 DEFAULT = new OFOxmInPhyPortVer14(
        DEFAULT_VALUE
    );

    // package private constructor - used by readers, builders, and factory
    OFOxmInPhyPortVer14(OFPort value) {
        this.value = value;
    }

    // Accessors for OF message fields
    @Override
    public long getTypeLen() {
        return 0x80000204L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.IN_PHY_PORT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    public OFOxm<OFPort> getCanonical() {
        // exact match OXM is always canonical
        return this;
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFOxmInPhyPort.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFOxmInPhyPort.Builder {
        final OFOxmInPhyPortVer14 parentMessage;

        // OF message fields
        private boolean valueSet;
        private OFPort value;

        BuilderWithParent(OFOxmInPhyPortVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getTypeLen() {
        return 0x80000204L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFOxmInPhyPort.Builder setValue(OFPort value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.IN_PHY_PORT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFPort> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFOxmInPhyPort build() {
                OFPort value = this.valueSet ? this.value : parentMessage.value;
                if(value == null)
                    throw new NullPointerException("Property value must not be null");

                //
                return new OFOxmInPhyPortVer14(
                    value
                );
        }

    }

    static class Builder implements OFOxmInPhyPort.Builder {
        // OF message fields
        private boolean valueSet;
        private OFPort value;

    @Override
    public long getTypeLen() {
        return 0x80000204L;
    }

    @Override
    public OFPort getValue() {
        return value;
    }

    @Override
    public OFOxmInPhyPort.Builder setValue(OFPort value) {
        this.value = value;
        this.valueSet = true;
        return this;
    }
    @Override
    public MatchField<OFPort> getMatchField() {
        return MatchField.IN_PHY_PORT;
    }

    @Override
    public boolean isMasked() {
        return false;
    }

    @Override
    public OFOxm<OFPort> getCanonical()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property canonical not supported in version 1.4");
    }

    @Override
    public OFPort getMask()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property mask not supported in version 1.4");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFOxmInPhyPort build() {
            OFPort value = this.valueSet ? this.value : DEFAULT_VALUE;
            if(value == null)
                throw new NullPointerException("Property value must not be null");


            return new OFOxmInPhyPortVer14(
                    value
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFOxmInPhyPort> {
        @Override
        public OFOxmInPhyPort readFrom(ChannelBuffer bb) throws OFParseError {
            // fixed value property typeLen == 0x80000204L
            int typeLen = bb.readInt();
            if(typeLen != (int) 0x80000204)
                throw new OFParseError("Wrong typeLen: Expected=0x80000204L(0x80000204L), got="+typeLen);
            OFPort value = OFPort.read4Bytes(bb);

            OFOxmInPhyPortVer14 oxmInPhyPortVer14 = new OFOxmInPhyPortVer14(
                    value
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", oxmInPhyPortVer14);
            return oxmInPhyPortVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFOxmInPhyPortVer14Funnel FUNNEL = new OFOxmInPhyPortVer14Funnel();
    static class OFOxmInPhyPortVer14Funnel implements Funnel<OFOxmInPhyPortVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFOxmInPhyPortVer14 message, PrimitiveSink sink) {
            // fixed value property typeLen = 0x80000204L
            sink.putInt((int) 0x80000204);
            message.value.putTo(sink);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFOxmInPhyPortVer14> {
        @Override
        public void write(ChannelBuffer bb, OFOxmInPhyPortVer14 message) {
            // fixed value property typeLen = 0x80000204L
            bb.writeInt((int) 0x80000204);
            message.value.write4Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFOxmInPhyPortVer14(");
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
        OFOxmInPhyPortVer14 other = (OFOxmInPhyPortVer14) obj;

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
