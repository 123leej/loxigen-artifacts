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

class OFBsnBwEnableGetReplyVer13 implements OFBsnBwEnableGetReply {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnBwEnableGetReplyVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int LENGTH = 20;

        private final static long DEFAULT_XID = 0x0L;
        private final static long DEFAULT_ENABLED = 0x0L;

    // OF message fields
    private final long xid;
    private final long enabled;
//
    // Immutable default instance
    final static OFBsnBwEnableGetReplyVer13 DEFAULT = new OFBsnBwEnableGetReplyVer13(
        DEFAULT_XID, DEFAULT_ENABLED
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnBwEnableGetReplyVer13(long xid, long enabled) {
        this.xid = xid;
        this.enabled = enabled;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x14L;
    }

    @Override
    public long getEnabled() {
        return enabled;
    }



    public OFBsnBwEnableGetReply.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnBwEnableGetReply.Builder {
        final OFBsnBwEnableGetReplyVer13 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean enabledSet;
        private long enabled;

        BuilderWithParent(OFBsnBwEnableGetReplyVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnBwEnableGetReply.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x14L;
    }

    @Override
    public long getEnabled() {
        return enabled;
    }

    @Override
    public OFBsnBwEnableGetReply.Builder setEnabled(long enabled) {
        this.enabled = enabled;
        this.enabledSet = true;
        return this;
    }


        @Override
        public OFBsnBwEnableGetReply build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                long enabled = this.enabledSet ? this.enabled : parentMessage.enabled;

                //
                return new OFBsnBwEnableGetReplyVer13(
                    xid,
                    enabled
                );
        }

    }

    static class Builder implements OFBsnBwEnableGetReply.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean enabledSet;
        private long enabled;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.EXPERIMENTER;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBsnBwEnableGetReply.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x14L;
    }

    @Override
    public long getEnabled() {
        return enabled;
    }

    @Override
    public OFBsnBwEnableGetReply.Builder setEnabled(long enabled) {
        this.enabled = enabled;
        this.enabledSet = true;
        return this;
    }
//
        @Override
        public OFBsnBwEnableGetReply build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            long enabled = this.enabledSet ? this.enabled : DEFAULT_ENABLED;


            return new OFBsnBwEnableGetReplyVer13(
                    xid,
                    enabled
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnBwEnableGetReply> {
        @Override
        public OFBsnBwEnableGetReply readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 4
            byte version = bb.readByte();
            if(version != (byte) 0x4)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_13(4), got="+version);
            // fixed value property type == 4
            byte type = bb.readByte();
            if(type != (byte) 0x4)
                throw new OFParseError("Wrong type: Expected=OFType.EXPERIMENTER(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 20)
                throw new OFParseError("Wrong length: Expected=20(20), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property subtype == 0x14L
            int subtype = bb.readInt();
            if(subtype != 0x14)
                throw new OFParseError("Wrong subtype: Expected=0x14L(0x14L), got="+subtype);
            long enabled = U32.f(bb.readInt());

            OFBsnBwEnableGetReplyVer13 bsnBwEnableGetReplyVer13 = new OFBsnBwEnableGetReplyVer13(
                    xid,
                      enabled
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnBwEnableGetReplyVer13);
            return bsnBwEnableGetReplyVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnBwEnableGetReplyVer13Funnel FUNNEL = new OFBsnBwEnableGetReplyVer13Funnel();
    static class OFBsnBwEnableGetReplyVer13Funnel implements Funnel<OFBsnBwEnableGetReplyVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnBwEnableGetReplyVer13 message, PrimitiveSink sink) {
            // fixed value property version = 4
            sink.putByte((byte) 0x4);
            // fixed value property type = 4
            sink.putByte((byte) 0x4);
            // fixed value property length = 20
            sink.putShort((short) 0x14);
            sink.putLong(message.xid);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x14L
            sink.putInt(0x14);
            sink.putLong(message.enabled);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnBwEnableGetReplyVer13> {
        @Override
        public void write(ByteBuf bb, OFBsnBwEnableGetReplyVer13 message) {
            // fixed value property version = 4
            bb.writeByte((byte) 0x4);
            // fixed value property type = 4
            bb.writeByte((byte) 0x4);
            // fixed value property length = 20
            bb.writeShort((short) 0x14);
            bb.writeInt(U32.t(message.xid));
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x14L
            bb.writeInt(0x14);
            bb.writeInt(U32.t(message.enabled));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnBwEnableGetReplyVer13(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("enabled=").append(enabled);
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
        OFBsnBwEnableGetReplyVer13 other = (OFBsnBwEnableGetReplyVer13) obj;

        if( xid != other.xid)
            return false;
        if( enabled != other.enabled)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime *  (int) (enabled ^ (enabled >>> 32));
        return result;
    }

}
