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
import java.util.List;
import com.google.common.collect.ImmutableList;
import java.util.Set;
import org.jboss.netty.buffer.ChannelBuffer;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;
import java.util.Arrays;

class OFPacketOutVer14 implements OFPacketOut {
    private static final Logger logger = LoggerFactory.getLogger(OFPacketOutVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 24;

        private final static long DEFAULT_XID = 0x0L;
        private final static OFBufferId DEFAULT_BUFFER_ID = OFBufferId.NO_BUFFER;
        private final static OFPort DEFAULT_IN_PORT = OFPort.ANY;
        private final static List<OFAction> DEFAULT_ACTIONS = ImmutableList.<OFAction>of();
        private final static byte[] DEFAULT_DATA = new byte[0];

    // OF message fields
    private final long xid;
    private final OFBufferId bufferId;
    private final OFPort inPort;
    private final List<OFAction> actions;
    private final byte[] data;
//
    // Immutable default instance
    final static OFPacketOutVer14 DEFAULT = new OFPacketOutVer14(
        DEFAULT_XID, DEFAULT_BUFFER_ID, DEFAULT_IN_PORT, DEFAULT_ACTIONS, DEFAULT_DATA
    );

    // package private constructor - used by readers, builders, and factory
    OFPacketOutVer14(long xid, OFBufferId bufferId, OFPort inPort, List<OFAction> actions, byte[] data) {
        this.xid = xid;
        this.bufferId = bufferId;
        this.inPort = inPort;
        this.actions = actions;
        this.data = data;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_OUT;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFBufferId getBufferId() {
        return bufferId;
    }

    @Override
    public OFPort getInPort() {
        return inPort;
    }

    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public byte[] getData() {
        return data;
    }



    public OFPacketOut.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPacketOut.Builder {
        final OFPacketOutVer14 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bufferIdSet;
        private OFBufferId bufferId;
        private boolean inPortSet;
        private OFPort inPort;
        private boolean actionsSet;
        private List<OFAction> actions;
        private boolean dataSet;
        private byte[] data;

        BuilderWithParent(OFPacketOutVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_OUT;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFPacketOut.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFBufferId getBufferId() {
        return bufferId;
    }

    @Override
    public OFPacketOut.Builder setBufferId(OFBufferId bufferId) {
        this.bufferId = bufferId;
        this.bufferIdSet = true;
        return this;
    }
    @Override
    public OFPort getInPort() {
        return inPort;
    }

    @Override
    public OFPacketOut.Builder setInPort(OFPort inPort) {
        this.inPort = inPort;
        this.inPortSet = true;
        return this;
    }
    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public OFPacketOut.Builder setActions(List<OFAction> actions) {
        this.actions = actions;
        this.actionsSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFPacketOut.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }


        @Override
        public OFPacketOut build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                OFBufferId bufferId = this.bufferIdSet ? this.bufferId : parentMessage.bufferId;
                if(bufferId == null)
                    throw new NullPointerException("Property bufferId must not be null");
                OFPort inPort = this.inPortSet ? this.inPort : parentMessage.inPort;
                if(inPort == null)
                    throw new NullPointerException("Property inPort must not be null");
                List<OFAction> actions = this.actionsSet ? this.actions : parentMessage.actions;
                if(actions == null)
                    throw new NullPointerException("Property actions must not be null");
                byte[] data = this.dataSet ? this.data : parentMessage.data;
                if(data == null)
                    throw new NullPointerException("Property data must not be null");

                //
                return new OFPacketOutVer14(
                    xid,
                    bufferId,
                    inPort,
                    actions,
                    data
                );
        }

    }

    static class Builder implements OFPacketOut.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bufferIdSet;
        private OFBufferId bufferId;
        private boolean inPortSet;
        private OFPort inPort;
        private boolean actionsSet;
        private List<OFAction> actions;
        private boolean dataSet;
        private byte[] data;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_OUT;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFPacketOut.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFBufferId getBufferId() {
        return bufferId;
    }

    @Override
    public OFPacketOut.Builder setBufferId(OFBufferId bufferId) {
        this.bufferId = bufferId;
        this.bufferIdSet = true;
        return this;
    }
    @Override
    public OFPort getInPort() {
        return inPort;
    }

    @Override
    public OFPacketOut.Builder setInPort(OFPort inPort) {
        this.inPort = inPort;
        this.inPortSet = true;
        return this;
    }
    @Override
    public List<OFAction> getActions() {
        return actions;
    }

    @Override
    public OFPacketOut.Builder setActions(List<OFAction> actions) {
        this.actions = actions;
        this.actionsSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFPacketOut.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }
//
        @Override
        public OFPacketOut build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            OFBufferId bufferId = this.bufferIdSet ? this.bufferId : DEFAULT_BUFFER_ID;
            if(bufferId == null)
                throw new NullPointerException("Property bufferId must not be null");
            OFPort inPort = this.inPortSet ? this.inPort : DEFAULT_IN_PORT;
            if(inPort == null)
                throw new NullPointerException("Property inPort must not be null");
            List<OFAction> actions = this.actionsSet ? this.actions : DEFAULT_ACTIONS;
            if(actions == null)
                throw new NullPointerException("Property actions must not be null");
            byte[] data = this.dataSet ? this.data : DEFAULT_DATA;
            if(data == null)
                throw new NullPointerException("Property data must not be null");


            return new OFPacketOutVer14(
                    xid,
                    bufferId,
                    inPort,
                    actions,
                    data
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPacketOut> {
        @Override
        public OFPacketOut readFrom(ChannelBuffer bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 5
            byte version = bb.readByte();
            if(version != (byte) 0x5)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_14(5), got="+version);
            // fixed value property type == 13
            byte type = bb.readByte();
            if(type != (byte) 0xd)
                throw new OFParseError("Wrong type: Expected=OFType.PACKET_OUT(13), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            OFBufferId bufferId = OFBufferId.of(bb.readInt());
            OFPort inPort = OFPort.read4Bytes(bb);
            int actionsLen = U16.f(bb.readShort());
            // pad: 6 bytes
            bb.skipBytes(6);
            List<OFAction> actions = ChannelUtils.readList(bb, actionsLen, OFActionVer14.READER);
            byte[] data = ChannelUtils.readBytes(bb, length - (bb.readerIndex() - start));

            OFPacketOutVer14 packetOutVer14 = new OFPacketOutVer14(
                    xid,
                      bufferId,
                      inPort,
                      actions,
                      data
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", packetOutVer14);
            return packetOutVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPacketOutVer14Funnel FUNNEL = new OFPacketOutVer14Funnel();
    static class OFPacketOutVer14Funnel implements Funnel<OFPacketOutVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPacketOutVer14 message, PrimitiveSink sink) {
            // fixed value property version = 5
            sink.putByte((byte) 0x5);
            // fixed value property type = 13
            sink.putByte((byte) 0xd);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.bufferId.putTo(sink);
            message.inPort.putTo(sink);
            // FIXME: skip funnel of actionsLen
            // skip pad (6 bytes)
            FunnelUtils.putList(message.actions, sink);
            sink.putBytes(message.data);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPacketOutVer14> {
        @Override
        public void write(ChannelBuffer bb, OFPacketOutVer14 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 5
            bb.writeByte((byte) 0x5);
            // fixed value property type = 13
            bb.writeByte((byte) 0xd);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            bb.writeInt(message.bufferId.getInt());
            message.inPort.write4Bytes(bb);
            // actionsLen is length indicator for actions, will be
            // udpated when actions has been written
            int actionsLenIndex = bb.writerIndex();
            bb.writeShort(0);
            // pad: 6 bytes
            bb.writeZero(6);
            int actionsStartIndex = bb.writerIndex();
            ChannelUtils.writeList(bb, message.actions);
            // update field length member actionsLen
            int actionsLength = bb.writerIndex() - actionsStartIndex;
            bb.setShort(actionsLenIndex, actionsLength);
            bb.writeBytes(message.data);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPacketOutVer14(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("bufferId=").append(bufferId);
        b.append(", ");
        b.append("inPort=").append(inPort);
        b.append(", ");
        b.append("actions=").append(actions);
        b.append(", ");
        b.append("data=").append(Arrays.toString(data));
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
        OFPacketOutVer14 other = (OFPacketOutVer14) obj;

        if( xid != other.xid)
            return false;
        if (bufferId == null) {
            if (other.bufferId != null)
                return false;
        } else if (!bufferId.equals(other.bufferId))
            return false;
        if (inPort == null) {
            if (other.inPort != null)
                return false;
        } else if (!inPort.equals(other.inPort))
            return false;
        if (actions == null) {
            if (other.actions != null)
                return false;
        } else if (!actions.equals(other.actions))
            return false;
        if (!Arrays.equals(data, other.data))
                return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((bufferId == null) ? 0 : bufferId.hashCode());
        result = prime * result + ((inPort == null) ? 0 : inPort.hashCode());
        result = prime * result + ((actions == null) ? 0 : actions.hashCode());
        result = prime * result + Arrays.hashCode(data);
        return result;
    }

}
