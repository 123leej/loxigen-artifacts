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

class OFBsnPduRxTimeoutVer14 implements OFBsnPduRxTimeout {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnPduRxTimeoutVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 21;

        private final static long DEFAULT_XID = 0x0L;
        private final static OFPort DEFAULT_PORT_NO = OFPort.ANY;
        private final static short DEFAULT_SLOT_NUM = (short) 0x0;

    // OF message fields
    private final long xid;
    private final OFPort portNo;
    private final short slotNum;
//
    // Immutable default instance
    final static OFBsnPduRxTimeoutVer14 DEFAULT = new OFBsnPduRxTimeoutVer14(
        DEFAULT_XID, DEFAULT_PORT_NO, DEFAULT_SLOT_NUM
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnPduRxTimeoutVer14(long xid, OFPort portNo, short slotNum) {
        this.xid = xid;
        this.portNo = portNo;
        this.slotNum = slotNum;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
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
        return 0x23L;
    }

    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public short getSlotNum() {
        return slotNum;
    }



    public OFBsnPduRxTimeout.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnPduRxTimeout.Builder {
        final OFBsnPduRxTimeoutVer14 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean portNoSet;
        private OFPort portNo;
        private boolean slotNumSet;
        private short slotNum;

        BuilderWithParent(OFBsnPduRxTimeoutVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
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
    public OFBsnPduRxTimeout.Builder setXid(long xid) {
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
        return 0x23L;
    }

    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public OFBsnPduRxTimeout.Builder setPortNo(OFPort portNo) {
        this.portNo = portNo;
        this.portNoSet = true;
        return this;
    }
    @Override
    public short getSlotNum() {
        return slotNum;
    }

    @Override
    public OFBsnPduRxTimeout.Builder setSlotNum(short slotNum) {
        this.slotNum = slotNum;
        this.slotNumSet = true;
        return this;
    }


        @Override
        public OFBsnPduRxTimeout build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                OFPort portNo = this.portNoSet ? this.portNo : parentMessage.portNo;
                if(portNo == null)
                    throw new NullPointerException("Property portNo must not be null");
                short slotNum = this.slotNumSet ? this.slotNum : parentMessage.slotNum;

                //
                return new OFBsnPduRxTimeoutVer14(
                    xid,
                    portNo,
                    slotNum
                );
        }

    }

    static class Builder implements OFBsnPduRxTimeout.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean portNoSet;
        private OFPort portNo;
        private boolean slotNumSet;
        private short slotNum;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
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
    public OFBsnPduRxTimeout.Builder setXid(long xid) {
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
        return 0x23L;
    }

    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public OFBsnPduRxTimeout.Builder setPortNo(OFPort portNo) {
        this.portNo = portNo;
        this.portNoSet = true;
        return this;
    }
    @Override
    public short getSlotNum() {
        return slotNum;
    }

    @Override
    public OFBsnPduRxTimeout.Builder setSlotNum(short slotNum) {
        this.slotNum = slotNum;
        this.slotNumSet = true;
        return this;
    }
//
        @Override
        public OFBsnPduRxTimeout build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            OFPort portNo = this.portNoSet ? this.portNo : DEFAULT_PORT_NO;
            if(portNo == null)
                throw new NullPointerException("Property portNo must not be null");
            short slotNum = this.slotNumSet ? this.slotNum : DEFAULT_SLOT_NUM;


            return new OFBsnPduRxTimeoutVer14(
                    xid,
                    portNo,
                    slotNum
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnPduRxTimeout> {
        @Override
        public OFBsnPduRxTimeout readFrom(ChannelBuffer bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 5
            byte version = bb.readByte();
            if(version != (byte) 0x5)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_14(5), got="+version);
            // fixed value property type == 4
            byte type = bb.readByte();
            if(type != (byte) 0x4)
                throw new OFParseError("Wrong type: Expected=OFType.EXPERIMENTER(4), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 21)
                throw new OFParseError("Wrong length: Expected=21(21), got="+length);
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
            // fixed value property subtype == 0x23L
            int subtype = bb.readInt();
            if(subtype != 0x23)
                throw new OFParseError("Wrong subtype: Expected=0x23L(0x23L), got="+subtype);
            OFPort portNo = OFPort.read4Bytes(bb);
            short slotNum = U8.f(bb.readByte());

            OFBsnPduRxTimeoutVer14 bsnPduRxTimeoutVer14 = new OFBsnPduRxTimeoutVer14(
                    xid,
                      portNo,
                      slotNum
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnPduRxTimeoutVer14);
            return bsnPduRxTimeoutVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnPduRxTimeoutVer14Funnel FUNNEL = new OFBsnPduRxTimeoutVer14Funnel();
    static class OFBsnPduRxTimeoutVer14Funnel implements Funnel<OFBsnPduRxTimeoutVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnPduRxTimeoutVer14 message, PrimitiveSink sink) {
            // fixed value property version = 5
            sink.putByte((byte) 0x5);
            // fixed value property type = 4
            sink.putByte((byte) 0x4);
            // fixed value property length = 21
            sink.putShort((short) 0x15);
            sink.putLong(message.xid);
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x23L
            sink.putInt(0x23);
            message.portNo.putTo(sink);
            sink.putShort(message.slotNum);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnPduRxTimeoutVer14> {
        @Override
        public void write(ChannelBuffer bb, OFBsnPduRxTimeoutVer14 message) {
            // fixed value property version = 5
            bb.writeByte((byte) 0x5);
            // fixed value property type = 4
            bb.writeByte((byte) 0x4);
            // fixed value property length = 21
            bb.writeShort((short) 0x15);
            bb.writeInt(U32.t(message.xid));
            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x23L
            bb.writeInt(0x23);
            message.portNo.write4Bytes(bb);
            bb.writeByte(U8.t(message.slotNum));


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnPduRxTimeoutVer14(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("portNo=").append(portNo);
        b.append(", ");
        b.append("slotNum=").append(slotNum);
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
        OFBsnPduRxTimeoutVer14 other = (OFBsnPduRxTimeoutVer14) obj;

        if( xid != other.xid)
            return false;
        if (portNo == null) {
            if (other.portNo != null)
                return false;
        } else if (!portNo.equals(other.portNo))
            return false;
        if( slotNum != other.slotNum)
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((portNo == null) ? 0 : portNo.hashCode());
        result = prime * result + slotNum;
        return result;
    }

}
