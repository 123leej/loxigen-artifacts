// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver10;

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

class OFBsnShellStatusVer10 implements OFBsnShellStatus {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnShellStatusVer10.class);
    // version: 1.0
    final static byte WIRE_VERSION = 1;
    final static int LENGTH = 20;

        private final static long DEFAULT_XID = 0x0L;
        private final static long DEFAULT_STATUS = 0x0L;

    // OF message fields
    private final long xid;
    private final long status;
//
    // Immutable default instance
    final static OFBsnShellStatusVer10 DEFAULT = new OFBsnShellStatusVer10(
        DEFAULT_XID, DEFAULT_STATUS
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnShellStatusVer10(long xid, long status) {
        this.xid = xid;
        this.status = status;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
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
        return 0x8L;
    }

    @Override
    public long getStatus() {
        return status;
    }



    public OFBsnShellStatus.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnShellStatus.Builder {
        final OFBsnShellStatusVer10 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean statusSet;
        private long status;

        BuilderWithParent(OFBsnShellStatusVer10 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
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
    public OFBsnShellStatus.Builder setXid(long xid) {
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
        return 0x8L;
    }

    @Override
    public long getStatus() {
        return status;
    }

    @Override
    public OFBsnShellStatus.Builder setStatus(long status) {
        this.status = status;
        this.statusSet = true;
        return this;
    }


        @Override
        public OFBsnShellStatus build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                long status = this.statusSet ? this.status : parentMessage.status;

                //
                return new OFBsnShellStatusVer10(
                    xid,
                    status
                );
        }

    }

    static class Builder implements OFBsnShellStatus.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean statusSet;
        private long status;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_10;
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
    public OFBsnShellStatus.Builder setXid(long xid) {
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
        return 0x8L;
    }

    @Override
    public long getStatus() {
        return status;
    }

    @Override
    public OFBsnShellStatus.Builder setStatus(long status) {
        this.status = status;
        this.statusSet = true;
        return this;
    }
//
        @Override
        public OFBsnShellStatus build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            long status = this.statusSet ? this.status : DEFAULT_STATUS;


            return new OFBsnShellStatusVer10(
                    xid,
                    status
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnShellStatus> {
        @Override
        public OFBsnShellStatus readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 1
            byte version = bb.readByte();
            if(version != (byte) 0x1)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_10(1), got="+version);
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
            // fixed value property subtype == 0x8L
            int subtype = bb.readInt();
            if(subtype != 0x8)
                throw new OFParseError("Wrong subtype: Expected=0x8L(0x8L), got="+subtype);
            long status = U32.f(bb.readInt());

            OFBsnShellStatusVer10 bsnShellStatusVer10 = new OFBsnShellStatusVer10(
                    xid,
                      status
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnShellStatusVer10);
            return bsnShellStatusVer10;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnShellStatusVer10Funnel FUNNEL = new OFBsnShellStatusVer10Funnel();
    static class OFBsnShellStatusVer10Funnel implements Funnel<OFBsnShellStatusVer10> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnShellStatusVer10 message, PrimitiveSink sink) {
            // fixed value property version = 1
            sink.putByte((byte) 0x1);
            // fixed value property type = 4
            sink.putByte((byte) 0x4);
            // fixed value property length = 20
            sink.putShort((short) 0x14);
            sink.putLong(message.xid);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x8L
            sink.putInt(0x8);
            sink.putLong(message.status);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnShellStatusVer10> {
        @Override
        public void write(ByteBuf bb, OFBsnShellStatusVer10 message) {
            // fixed value property version = 1
            bb.writeByte((byte) 0x1);
            // fixed value property type = 4
            bb.writeByte((byte) 0x4);
            // fixed value property length = 20
            bb.writeShort((short) 0x14);
            bb.writeInt(U32.t(message.xid));
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x8L
            bb.writeInt(0x8);
            bb.writeInt(U32.t(message.status));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnShellStatusVer10(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("status=").append(status);
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
        OFBsnShellStatusVer10 other = (OFBsnShellStatusVer10) obj;

        if( xid != other.xid)
            return false;
        if( status != other.status)
            return false;
        return true;
    }

    @Override
    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFBsnShellStatusVer10 other = (OFBsnShellStatusVer10) obj;

        // ignore XID
        if( status != other.status)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime *  (int) (status ^ (status >>> 32));
        return result;
    }

    @Override
    public int hashCodeIgnoreXid() {
        final int prime = 31;
        int result = 1;

        // ignore XID
        result = prime *  (int) (status ^ (status >>> 32));
        return result;
    }

}
