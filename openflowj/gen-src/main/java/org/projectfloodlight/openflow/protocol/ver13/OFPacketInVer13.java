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
import java.util.Arrays;

class OFPacketInVer13 implements OFPacketIn {
    private static final Logger logger = LoggerFactory.getLogger(OFPacketInVer13.class);
    // version: 1.3
    final static byte WIRE_VERSION = 4;
    final static int MINIMUM_LENGTH = 34;

        private final static long DEFAULT_XID = 0x0L;
        private final static OFBufferId DEFAULT_BUFFER_ID = OFBufferId.NO_BUFFER;
        private final static int DEFAULT_TOTAL_LEN = 0x0;
        private final static TableId DEFAULT_TABLE_ID = TableId.ALL;
        private final static U64 DEFAULT_COOKIE = U64.ZERO;
        private final static Match DEFAULT_MATCH = OFFactoryVer13.MATCH_WILDCARD_ALL;
        private final static byte[] DEFAULT_DATA = new byte[0];

    // OF message fields
    private final long xid;
    private final OFBufferId bufferId;
    private final int totalLen;
    private final OFPacketInReason reason;
    private final TableId tableId;
    private final U64 cookie;
    private final Match match;
    private final byte[] data;
//

    // package private constructor - used by readers, builders, and factory
    OFPacketInVer13(long xid, OFBufferId bufferId, int totalLen, OFPacketInReason reason, TableId tableId, U64 cookie, Match match, byte[] data) {
        if(bufferId == null) {
            throw new NullPointerException("OFPacketInVer13: property bufferId cannot be null");
        }
        if(reason == null) {
            throw new NullPointerException("OFPacketInVer13: property reason cannot be null");
        }
        if(tableId == null) {
            throw new NullPointerException("OFPacketInVer13: property tableId cannot be null");
        }
        if(cookie == null) {
            throw new NullPointerException("OFPacketInVer13: property cookie cannot be null");
        }
        if(match == null) {
            throw new NullPointerException("OFPacketInVer13: property match cannot be null");
        }
        if(data == null) {
            throw new NullPointerException("OFPacketInVer13: property data cannot be null");
        }
        this.xid = xid;
        this.bufferId = bufferId;
        this.totalLen = totalLen;
        this.reason = reason;
        this.tableId = tableId;
        this.cookie = cookie;
        this.match = match;
        this.data = data;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_IN;
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
    public int getTotalLen() {
        return totalLen;
    }

    @Override
    public OFPacketInReason getReason() {
        return reason;
    }

    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFPort getInPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPort not supported in version 1.3");
    }

    @Override
    public OFPort getInPhyPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPhyPort not supported in version 1.3");
    }

    @Override
    public U64 getCookie() {
        return cookie;
    }



    public OFPacketIn.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPacketIn.Builder {
        final OFPacketInVer13 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bufferIdSet;
        private OFBufferId bufferId;
        private boolean totalLenSet;
        private int totalLen;
        private boolean reasonSet;
        private OFPacketInReason reason;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean cookieSet;
        private U64 cookie;
        private boolean matchSet;
        private Match match;
        private boolean dataSet;
        private byte[] data;

        BuilderWithParent(OFPacketInVer13 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_IN;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFPacketIn.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFBufferId getBufferId() {
        return bufferId;
    }

    @Override
    public OFPacketIn.Builder setBufferId(OFBufferId bufferId) {
        this.bufferId = bufferId;
        this.bufferIdSet = true;
        return this;
    }
    @Override
    public int getTotalLen() {
        return totalLen;
    }

    @Override
    public OFPacketIn.Builder setTotalLen(int totalLen) {
        this.totalLen = totalLen;
        this.totalLenSet = true;
        return this;
    }
    @Override
    public OFPacketInReason getReason() {
        return reason;
    }

    @Override
    public OFPacketIn.Builder setReason(OFPacketInReason reason) {
        this.reason = reason;
        this.reasonSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFPacketIn.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFPacketIn.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFPacketIn.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }
    @Override
    public OFPort getInPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPort not supported in version 1.3");
    }

    @Override
    public OFPacketIn.Builder setInPort(OFPort inPort) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property inPort not supported in version 1.3");
    }
    @Override
    public OFPort getInPhyPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPhyPort not supported in version 1.3");
    }

    @Override
    public OFPacketIn.Builder setInPhyPort(OFPort inPhyPort) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property inPhyPort not supported in version 1.3");
    }
    @Override
    public U64 getCookie() {
        return cookie;
    }

    @Override
    public OFPacketIn.Builder setCookie(U64 cookie) {
        this.cookie = cookie;
        this.cookieSet = true;
        return this;
    }


        @Override
        public OFPacketIn build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                OFBufferId bufferId = this.bufferIdSet ? this.bufferId : parentMessage.bufferId;
                if(bufferId == null)
                    throw new NullPointerException("Property bufferId must not be null");
                int totalLen = this.totalLenSet ? this.totalLen : parentMessage.totalLen;
                OFPacketInReason reason = this.reasonSet ? this.reason : parentMessage.reason;
                if(reason == null)
                    throw new NullPointerException("Property reason must not be null");
                TableId tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                if(tableId == null)
                    throw new NullPointerException("Property tableId must not be null");
                U64 cookie = this.cookieSet ? this.cookie : parentMessage.cookie;
                if(cookie == null)
                    throw new NullPointerException("Property cookie must not be null");
                Match match = this.matchSet ? this.match : parentMessage.match;
                if(match == null)
                    throw new NullPointerException("Property match must not be null");
                byte[] data = this.dataSet ? this.data : parentMessage.data;
                if(data == null)
                    throw new NullPointerException("Property data must not be null");

                //
                return new OFPacketInVer13(
                    xid,
                    bufferId,
                    totalLen,
                    reason,
                    tableId,
                    cookie,
                    match,
                    data
                );
        }

    }

    static class Builder implements OFPacketIn.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean bufferIdSet;
        private OFBufferId bufferId;
        private boolean totalLenSet;
        private int totalLen;
        private boolean reasonSet;
        private OFPacketInReason reason;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean cookieSet;
        private U64 cookie;
        private boolean matchSet;
        private Match match;
        private boolean dataSet;
        private byte[] data;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_13;
    }

    @Override
    public OFType getType() {
        return OFType.PACKET_IN;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFPacketIn.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public OFBufferId getBufferId() {
        return bufferId;
    }

    @Override
    public OFPacketIn.Builder setBufferId(OFBufferId bufferId) {
        this.bufferId = bufferId;
        this.bufferIdSet = true;
        return this;
    }
    @Override
    public int getTotalLen() {
        return totalLen;
    }

    @Override
    public OFPacketIn.Builder setTotalLen(int totalLen) {
        this.totalLen = totalLen;
        this.totalLenSet = true;
        return this;
    }
    @Override
    public OFPacketInReason getReason() {
        return reason;
    }

    @Override
    public OFPacketIn.Builder setReason(OFPacketInReason reason) {
        this.reason = reason;
        this.reasonSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFPacketIn.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFPacketIn.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public byte[] getData() {
        return data;
    }

    @Override
    public OFPacketIn.Builder setData(byte[] data) {
        this.data = data;
        this.dataSet = true;
        return this;
    }
    @Override
    public OFPort getInPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPort not supported in version 1.3");
    }

    @Override
    public OFPacketIn.Builder setInPort(OFPort inPort) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property inPort not supported in version 1.3");
    }
    @Override
    public OFPort getInPhyPort()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property inPhyPort not supported in version 1.3");
    }

    @Override
    public OFPacketIn.Builder setInPhyPort(OFPort inPhyPort) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property inPhyPort not supported in version 1.3");
    }
    @Override
    public U64 getCookie() {
        return cookie;
    }

    @Override
    public OFPacketIn.Builder setCookie(U64 cookie) {
        this.cookie = cookie;
        this.cookieSet = true;
        return this;
    }
//
        @Override
        public OFPacketIn build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            OFBufferId bufferId = this.bufferIdSet ? this.bufferId : DEFAULT_BUFFER_ID;
            if(bufferId == null)
                throw new NullPointerException("Property bufferId must not be null");
            int totalLen = this.totalLenSet ? this.totalLen : DEFAULT_TOTAL_LEN;
            if(!this.reasonSet)
                throw new IllegalStateException("Property reason doesn't have default value -- must be set");
            if(reason == null)
                throw new NullPointerException("Property reason must not be null");
            TableId tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            if(tableId == null)
                throw new NullPointerException("Property tableId must not be null");
            U64 cookie = this.cookieSet ? this.cookie : DEFAULT_COOKIE;
            if(cookie == null)
                throw new NullPointerException("Property cookie must not be null");
            Match match = this.matchSet ? this.match : DEFAULT_MATCH;
            if(match == null)
                throw new NullPointerException("Property match must not be null");
            byte[] data = this.dataSet ? this.data : DEFAULT_DATA;
            if(data == null)
                throw new NullPointerException("Property data must not be null");


            return new OFPacketInVer13(
                    xid,
                    bufferId,
                    totalLen,
                    reason,
                    tableId,
                    cookie,
                    match,
                    data
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPacketIn> {
        @Override
        public OFPacketIn readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 4
            byte version = bb.readByte();
            if(version != (byte) 0x4)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_13(4), got="+version);
            // fixed value property type == 10
            byte type = bb.readByte();
            if(type != (byte) 0xa)
                throw new OFParseError("Wrong type: Expected=OFType.PACKET_IN(10), got="+type);
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
            int totalLen = U16.f(bb.readShort());
            OFPacketInReason reason = OFPacketInReasonSerializerVer13.readFrom(bb);
            TableId tableId = TableId.readByte(bb);
            U64 cookie = U64.ofRaw(bb.readLong());
            Match match = ChannelUtilsVer13.readOFMatch(bb);
            // pad: 2 bytes
            bb.skipBytes(2);
            byte[] data = ChannelUtils.readBytes(bb, length - (bb.readerIndex() - start));

            OFPacketInVer13 packetInVer13 = new OFPacketInVer13(
                    xid,
                      bufferId,
                      totalLen,
                      reason,
                      tableId,
                      cookie,
                      match,
                      data
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", packetInVer13);
            return packetInVer13;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPacketInVer13Funnel FUNNEL = new OFPacketInVer13Funnel();
    static class OFPacketInVer13Funnel implements Funnel<OFPacketInVer13> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPacketInVer13 message, PrimitiveSink sink) {
            // fixed value property version = 4
            sink.putByte((byte) 0x4);
            // fixed value property type = 10
            sink.putByte((byte) 0xa);
            // FIXME: skip funnel of length
            sink.putLong(message.xid);
            message.bufferId.putTo(sink);
            sink.putInt(message.totalLen);
            OFPacketInReasonSerializerVer13.putTo(message.reason, sink);
            message.tableId.putTo(sink);
            message.cookie.putTo(sink);
            message.match.putTo(sink);
            // skip pad (2 bytes)
            sink.putBytes(message.data);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPacketInVer13> {
        @Override
        public void write(ByteBuf bb, OFPacketInVer13 message) {
            int startIndex = bb.writerIndex();
            // fixed value property version = 4
            bb.writeByte((byte) 0x4);
            // fixed value property type = 10
            bb.writeByte((byte) 0xa);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            bb.writeInt(U32.t(message.xid));
            bb.writeInt(message.bufferId.getInt());
            bb.writeShort(U16.t(message.totalLen));
            OFPacketInReasonSerializerVer13.writeTo(bb, message.reason);
            message.tableId.writeByte(bb);
            bb.writeLong(message.cookie.getValue());
            message.match.writeTo(bb);
            // pad: 2 bytes
            bb.writeZero(2);
            bb.writeBytes(message.data);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPacketInVer13(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("bufferId=").append(bufferId);
        b.append(", ");
        b.append("totalLen=").append(totalLen);
        b.append(", ");
        b.append("reason=").append(reason);
        b.append(", ");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("cookie=").append(cookie);
        b.append(", ");
        b.append("match=").append(match);
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
        OFPacketInVer13 other = (OFPacketInVer13) obj;

        if( xid != other.xid)
            return false;
        if (bufferId == null) {
            if (other.bufferId != null)
                return false;
        } else if (!bufferId.equals(other.bufferId))
            return false;
        if( totalLen != other.totalLen)
            return false;
        if (reason == null) {
            if (other.reason != null)
                return false;
        } else if (!reason.equals(other.reason))
            return false;
        if (tableId == null) {
            if (other.tableId != null)
                return false;
        } else if (!tableId.equals(other.tableId))
            return false;
        if (cookie == null) {
            if (other.cookie != null)
                return false;
        } else if (!cookie.equals(other.cookie))
            return false;
        if (match == null) {
            if (other.match != null)
                return false;
        } else if (!match.equals(other.match))
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
        result = prime * result + totalLen;
        result = prime * result + ((reason == null) ? 0 : reason.hashCode());
        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        result = prime * result + ((cookie == null) ? 0 : cookie.hashCode());
        result = prime * result + ((match == null) ? 0 : match.hashCode());
        result = prime * result + Arrays.hashCode(data);
        return result;
    }

}
