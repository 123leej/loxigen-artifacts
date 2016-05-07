// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
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
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFAsyncConfigPropTableStatusMasterVer15 implements OFAsyncConfigPropTableStatusMaster {
    private static final Logger logger = LoggerFactory.getLogger(OFAsyncConfigPropTableStatusMasterVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 8;

        private final static long DEFAULT_MASK = 0x0L;

    // OF message fields
    private final long mask;
//
    // Immutable default instance
    final static OFAsyncConfigPropTableStatusMasterVer15 DEFAULT = new OFAsyncConfigPropTableStatusMasterVer15(
        DEFAULT_MASK
    );

    // package private constructor - used by readers, builders, and factory
    OFAsyncConfigPropTableStatusMasterVer15(long mask) {
        this.mask = mask;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x9;
    }

    @Override
    public long getMask() {
        return mask;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFAsyncConfigPropTableStatusMaster.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFAsyncConfigPropTableStatusMaster.Builder {
        final OFAsyncConfigPropTableStatusMasterVer15 parentMessage;

        // OF message fields
        private boolean maskSet;
        private long mask;

        BuilderWithParent(OFAsyncConfigPropTableStatusMasterVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x9;
    }

    @Override
    public long getMask() {
        return mask;
    }

    @Override
    public OFAsyncConfigPropTableStatusMaster.Builder setMask(long mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFAsyncConfigPropTableStatusMaster build() {
                long mask = this.maskSet ? this.mask : parentMessage.mask;

                //
                return new OFAsyncConfigPropTableStatusMasterVer15(
                    mask
                );
        }

    }

    static class Builder implements OFAsyncConfigPropTableStatusMaster.Builder {
        // OF message fields
        private boolean maskSet;
        private long mask;

    @Override
    public int getType() {
        return 0x9;
    }

    @Override
    public long getMask() {
        return mask;
    }

    @Override
    public OFAsyncConfigPropTableStatusMaster.Builder setMask(long mask) {
        this.mask = mask;
        this.maskSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFAsyncConfigPropTableStatusMaster build() {
            long mask = this.maskSet ? this.mask : DEFAULT_MASK;


            return new OFAsyncConfigPropTableStatusMasterVer15(
                    mask
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFAsyncConfigPropTableStatusMaster> {
        @Override
        public OFAsyncConfigPropTableStatusMaster readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x9
            short type = bb.readShort();
            if(type != (short) 0x9)
                throw new OFParseError("Wrong type: Expected=0x9(0x9), got="+type);
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
            long mask = U32.f(bb.readInt());

            OFAsyncConfigPropTableStatusMasterVer15 asyncConfigPropTableStatusMasterVer15 = new OFAsyncConfigPropTableStatusMasterVer15(
                    mask
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", asyncConfigPropTableStatusMasterVer15);
            return asyncConfigPropTableStatusMasterVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFAsyncConfigPropTableStatusMasterVer15Funnel FUNNEL = new OFAsyncConfigPropTableStatusMasterVer15Funnel();
    static class OFAsyncConfigPropTableStatusMasterVer15Funnel implements Funnel<OFAsyncConfigPropTableStatusMasterVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFAsyncConfigPropTableStatusMasterVer15 message, PrimitiveSink sink) {
            // fixed value property type = 0x9
            sink.putShort((short) 0x9);
            // fixed value property length = 8
            sink.putShort((short) 0x8);
            sink.putLong(message.mask);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFAsyncConfigPropTableStatusMasterVer15> {
        @Override
        public void write(ByteBuf bb, OFAsyncConfigPropTableStatusMasterVer15 message) {
            // fixed value property type = 0x9
            bb.writeShort((short) 0x9);
            // fixed value property length = 8
            bb.writeShort((short) 0x8);
            bb.writeInt(U32.t(message.mask));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFAsyncConfigPropTableStatusMasterVer15(");
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
        OFAsyncConfigPropTableStatusMasterVer15 other = (OFAsyncConfigPropTableStatusMasterVer15) obj;

        if( mask != other.mask)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (mask ^ (mask >>> 32));
        return result;
    }

}