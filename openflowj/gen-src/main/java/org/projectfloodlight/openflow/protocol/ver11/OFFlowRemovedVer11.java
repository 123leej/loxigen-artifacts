// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver11;

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

class OFFlowRemovedVer11 implements OFFlowRemoved {
    private static final Logger logger = LoggerFactory.getLogger(OFFlowRemovedVer11.class);
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int LENGTH = 136;

        private final static long DEFAULT_XID = 0x0L;
        private final static U64 DEFAULT_COOKIE = U64.ZERO;
        private final static int DEFAULT_PRIORITY = 0x0;
        private final static TableId DEFAULT_TABLE_ID = TableId.ALL;
        private final static long DEFAULT_DURATION_SEC = 0x0L;
        private final static long DEFAULT_DURATION_NSEC = 0x0L;
        private final static int DEFAULT_IDLE_TIMEOUT = 0x0;
        private final static U64 DEFAULT_PACKET_COUNT = U64.ZERO;
        private final static U64 DEFAULT_BYTE_COUNT = U64.ZERO;
        private final static Match DEFAULT_MATCH = OFFactoryVer11.MATCH_WILDCARD_ALL;

    // OF message fields
    private final long xid;
    private final U64 cookie;
    private final int priority;
    private final OFFlowRemovedReason reason;
    private final TableId tableId;
    private final long durationSec;
    private final long durationNsec;
    private final int idleTimeout;
    private final U64 packetCount;
    private final U64 byteCount;
    private final Match match;
//

    // package private constructor - used by readers, builders, and factory
    OFFlowRemovedVer11(long xid, U64 cookie, int priority, OFFlowRemovedReason reason, TableId tableId, long durationSec, long durationNsec, int idleTimeout, U64 packetCount, U64 byteCount, Match match) {
        if(cookie == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property cookie cannot be null");
        }
        if(reason == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property reason cannot be null");
        }
        if(tableId == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property tableId cannot be null");
        }
        if(packetCount == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property packetCount cannot be null");
        }
        if(byteCount == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property byteCount cannot be null");
        }
        if(match == null) {
            throw new NullPointerException("OFFlowRemovedVer11: property match cannot be null");
        }
        this.xid = xid;
        this.cookie = cookie;
        this.priority = priority;
        this.reason = reason;
        this.tableId = tableId;
        this.durationSec = durationSec;
        this.durationNsec = durationNsec;
        this.idleTimeout = idleTimeout;
        this.packetCount = packetCount;
        this.byteCount = byteCount;
        this.match = match;
    }

    // Accessors for OF message fields
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.FLOW_REMOVED;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public U64 getCookie() {
        return cookie;
    }

    @Override
    public int getPriority() {
        return priority;
    }

    @Override
    public OFFlowRemovedReason getReason() {
        return reason;
    }

    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public long getDurationSec() {
        return durationSec;
    }

    @Override
    public long getDurationNsec() {
        return durationNsec;
    }

    @Override
    public int getIdleTimeout() {
        return idleTimeout;
    }

    @Override
    public int getHardTimeout()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property hardTimeout not supported in version 1.1");
    }

    @Override
    public U64 getPacketCount() {
        return packetCount;
    }

    @Override
    public U64 getByteCount() {
        return byteCount;
    }

    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public Stat getStats()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property stats not supported in version 1.1");
    }



    public OFFlowRemoved.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFFlowRemoved.Builder {
        final OFFlowRemovedVer11 parentMessage;

        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean cookieSet;
        private U64 cookie;
        private boolean prioritySet;
        private int priority;
        private boolean reasonSet;
        private OFFlowRemovedReason reason;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean durationSecSet;
        private long durationSec;
        private boolean durationNsecSet;
        private long durationNsec;
        private boolean idleTimeoutSet;
        private int idleTimeout;
        private boolean packetCountSet;
        private U64 packetCount;
        private boolean byteCountSet;
        private U64 byteCount;
        private boolean matchSet;
        private Match match;

        BuilderWithParent(OFFlowRemovedVer11 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.FLOW_REMOVED;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowRemoved.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public U64 getCookie() {
        return cookie;
    }

    @Override
    public OFFlowRemoved.Builder setCookie(U64 cookie) {
        this.cookie = cookie;
        this.cookieSet = true;
        return this;
    }
    @Override
    public int getPriority() {
        return priority;
    }

    @Override
    public OFFlowRemoved.Builder setPriority(int priority) {
        this.priority = priority;
        this.prioritySet = true;
        return this;
    }
    @Override
    public OFFlowRemovedReason getReason() {
        return reason;
    }

    @Override
    public OFFlowRemoved.Builder setReason(OFFlowRemovedReason reason) {
        this.reason = reason;
        this.reasonSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFFlowRemoved.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public long getDurationSec() {
        return durationSec;
    }

    @Override
    public OFFlowRemoved.Builder setDurationSec(long durationSec) {
        this.durationSec = durationSec;
        this.durationSecSet = true;
        return this;
    }
    @Override
    public long getDurationNsec() {
        return durationNsec;
    }

    @Override
    public OFFlowRemoved.Builder setDurationNsec(long durationNsec) {
        this.durationNsec = durationNsec;
        this.durationNsecSet = true;
        return this;
    }
    @Override
    public int getIdleTimeout() {
        return idleTimeout;
    }

    @Override
    public OFFlowRemoved.Builder setIdleTimeout(int idleTimeout) {
        this.idleTimeout = idleTimeout;
        this.idleTimeoutSet = true;
        return this;
    }
    @Override
    public int getHardTimeout()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property hardTimeout not supported in version 1.1");
    }

    @Override
    public OFFlowRemoved.Builder setHardTimeout(int hardTimeout) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property hardTimeout not supported in version 1.1");
    }
    @Override
    public U64 getPacketCount() {
        return packetCount;
    }

    @Override
    public OFFlowRemoved.Builder setPacketCount(U64 packetCount) {
        this.packetCount = packetCount;
        this.packetCountSet = true;
        return this;
    }
    @Override
    public U64 getByteCount() {
        return byteCount;
    }

    @Override
    public OFFlowRemoved.Builder setByteCount(U64 byteCount) {
        this.byteCount = byteCount;
        this.byteCountSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFFlowRemoved.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public Stat getStats()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property stats not supported in version 1.1");
    }

    @Override
    public OFFlowRemoved.Builder setStats(Stat stats) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property stats not supported in version 1.1");
    }


        @Override
        public OFFlowRemoved build() {
                long xid = this.xidSet ? this.xid : parentMessage.xid;
                U64 cookie = this.cookieSet ? this.cookie : parentMessage.cookie;
                if(cookie == null)
                    throw new NullPointerException("Property cookie must not be null");
                int priority = this.prioritySet ? this.priority : parentMessage.priority;
                OFFlowRemovedReason reason = this.reasonSet ? this.reason : parentMessage.reason;
                if(reason == null)
                    throw new NullPointerException("Property reason must not be null");
                TableId tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                if(tableId == null)
                    throw new NullPointerException("Property tableId must not be null");
                long durationSec = this.durationSecSet ? this.durationSec : parentMessage.durationSec;
                long durationNsec = this.durationNsecSet ? this.durationNsec : parentMessage.durationNsec;
                int idleTimeout = this.idleTimeoutSet ? this.idleTimeout : parentMessage.idleTimeout;
                U64 packetCount = this.packetCountSet ? this.packetCount : parentMessage.packetCount;
                if(packetCount == null)
                    throw new NullPointerException("Property packetCount must not be null");
                U64 byteCount = this.byteCountSet ? this.byteCount : parentMessage.byteCount;
                if(byteCount == null)
                    throw new NullPointerException("Property byteCount must not be null");
                Match match = this.matchSet ? this.match : parentMessage.match;
                if(match == null)
                    throw new NullPointerException("Property match must not be null");

                //
                return new OFFlowRemovedVer11(
                    xid,
                    cookie,
                    priority,
                    reason,
                    tableId,
                    durationSec,
                    durationNsec,
                    idleTimeout,
                    packetCount,
                    byteCount,
                    match
                );
        }

    }

    static class Builder implements OFFlowRemoved.Builder {
        // OF message fields
        private boolean xidSet;
        private long xid;
        private boolean cookieSet;
        private U64 cookie;
        private boolean prioritySet;
        private int priority;
        private boolean reasonSet;
        private OFFlowRemovedReason reason;
        private boolean tableIdSet;
        private TableId tableId;
        private boolean durationSecSet;
        private long durationSec;
        private boolean durationNsecSet;
        private long durationNsec;
        private boolean idleTimeoutSet;
        private int idleTimeout;
        private boolean packetCountSet;
        private U64 packetCount;
        private boolean byteCountSet;
        private U64 byteCount;
        private boolean matchSet;
        private Match match;

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_11;
    }

    @Override
    public OFType getType() {
        return OFType.FLOW_REMOVED;
    }

    @Override
    public long getXid() {
        return xid;
    }

    @Override
    public OFFlowRemoved.Builder setXid(long xid) {
        this.xid = xid;
        this.xidSet = true;
        return this;
    }
    @Override
    public U64 getCookie() {
        return cookie;
    }

    @Override
    public OFFlowRemoved.Builder setCookie(U64 cookie) {
        this.cookie = cookie;
        this.cookieSet = true;
        return this;
    }
    @Override
    public int getPriority() {
        return priority;
    }

    @Override
    public OFFlowRemoved.Builder setPriority(int priority) {
        this.priority = priority;
        this.prioritySet = true;
        return this;
    }
    @Override
    public OFFlowRemovedReason getReason() {
        return reason;
    }

    @Override
    public OFFlowRemoved.Builder setReason(OFFlowRemovedReason reason) {
        this.reason = reason;
        this.reasonSet = true;
        return this;
    }
    @Override
    public TableId getTableId() {
        return tableId;
    }

    @Override
    public OFFlowRemoved.Builder setTableId(TableId tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public long getDurationSec() {
        return durationSec;
    }

    @Override
    public OFFlowRemoved.Builder setDurationSec(long durationSec) {
        this.durationSec = durationSec;
        this.durationSecSet = true;
        return this;
    }
    @Override
    public long getDurationNsec() {
        return durationNsec;
    }

    @Override
    public OFFlowRemoved.Builder setDurationNsec(long durationNsec) {
        this.durationNsec = durationNsec;
        this.durationNsecSet = true;
        return this;
    }
    @Override
    public int getIdleTimeout() {
        return idleTimeout;
    }

    @Override
    public OFFlowRemoved.Builder setIdleTimeout(int idleTimeout) {
        this.idleTimeout = idleTimeout;
        this.idleTimeoutSet = true;
        return this;
    }
    @Override
    public int getHardTimeout()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property hardTimeout not supported in version 1.1");
    }

    @Override
    public OFFlowRemoved.Builder setHardTimeout(int hardTimeout) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property hardTimeout not supported in version 1.1");
    }
    @Override
    public U64 getPacketCount() {
        return packetCount;
    }

    @Override
    public OFFlowRemoved.Builder setPacketCount(U64 packetCount) {
        this.packetCount = packetCount;
        this.packetCountSet = true;
        return this;
    }
    @Override
    public U64 getByteCount() {
        return byteCount;
    }

    @Override
    public OFFlowRemoved.Builder setByteCount(U64 byteCount) {
        this.byteCount = byteCount;
        this.byteCountSet = true;
        return this;
    }
    @Override
    public Match getMatch() {
        return match;
    }

    @Override
    public OFFlowRemoved.Builder setMatch(Match match) {
        this.match = match;
        this.matchSet = true;
        return this;
    }
    @Override
    public Stat getStats()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property stats not supported in version 1.1");
    }

    @Override
    public OFFlowRemoved.Builder setStats(Stat stats) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property stats not supported in version 1.1");
    }
//
        @Override
        public OFFlowRemoved build() {
            long xid = this.xidSet ? this.xid : DEFAULT_XID;
            U64 cookie = this.cookieSet ? this.cookie : DEFAULT_COOKIE;
            if(cookie == null)
                throw new NullPointerException("Property cookie must not be null");
            int priority = this.prioritySet ? this.priority : DEFAULT_PRIORITY;
            if(!this.reasonSet)
                throw new IllegalStateException("Property reason doesn't have default value -- must be set");
            if(reason == null)
                throw new NullPointerException("Property reason must not be null");
            TableId tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            if(tableId == null)
                throw new NullPointerException("Property tableId must not be null");
            long durationSec = this.durationSecSet ? this.durationSec : DEFAULT_DURATION_SEC;
            long durationNsec = this.durationNsecSet ? this.durationNsec : DEFAULT_DURATION_NSEC;
            int idleTimeout = this.idleTimeoutSet ? this.idleTimeout : DEFAULT_IDLE_TIMEOUT;
            U64 packetCount = this.packetCountSet ? this.packetCount : DEFAULT_PACKET_COUNT;
            if(packetCount == null)
                throw new NullPointerException("Property packetCount must not be null");
            U64 byteCount = this.byteCountSet ? this.byteCount : DEFAULT_BYTE_COUNT;
            if(byteCount == null)
                throw new NullPointerException("Property byteCount must not be null");
            Match match = this.matchSet ? this.match : DEFAULT_MATCH;
            if(match == null)
                throw new NullPointerException("Property match must not be null");


            return new OFFlowRemovedVer11(
                    xid,
                    cookie,
                    priority,
                    reason,
                    tableId,
                    durationSec,
                    durationNsec,
                    idleTimeout,
                    packetCount,
                    byteCount,
                    match
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFFlowRemoved> {
        @Override
        public OFFlowRemoved readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property version == 2
            byte version = bb.readByte();
            if(version != (byte) 0x2)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_11(2), got="+version);
            // fixed value property type == 11
            byte type = bb.readByte();
            if(type != (byte) 0xb)
                throw new OFParseError("Wrong type: Expected=OFType.FLOW_REMOVED(11), got="+type);
            int length = U16.f(bb.readShort());
            if(length != 136)
                throw new OFParseError("Wrong length: Expected=136(136), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            long xid = U32.f(bb.readInt());
            U64 cookie = U64.ofRaw(bb.readLong());
            int priority = U16.f(bb.readShort());
            OFFlowRemovedReason reason = OFFlowRemovedReasonSerializerVer11.readFrom(bb);
            TableId tableId = TableId.readByte(bb);
            long durationSec = U32.f(bb.readInt());
            long durationNsec = U32.f(bb.readInt());
            int idleTimeout = U16.f(bb.readShort());
            // pad: 2 bytes
            bb.skipBytes(2);
            U64 packetCount = U64.ofRaw(bb.readLong());
            U64 byteCount = U64.ofRaw(bb.readLong());
            Match match = ChannelUtilsVer11.readOFMatch(bb);

            OFFlowRemovedVer11 flowRemovedVer11 = new OFFlowRemovedVer11(
                    xid,
                      cookie,
                      priority,
                      reason,
                      tableId,
                      durationSec,
                      durationNsec,
                      idleTimeout,
                      packetCount,
                      byteCount,
                      match
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", flowRemovedVer11);
            return flowRemovedVer11;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFFlowRemovedVer11Funnel FUNNEL = new OFFlowRemovedVer11Funnel();
    static class OFFlowRemovedVer11Funnel implements Funnel<OFFlowRemovedVer11> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFFlowRemovedVer11 message, PrimitiveSink sink) {
            // fixed value property version = 2
            sink.putByte((byte) 0x2);
            // fixed value property type = 11
            sink.putByte((byte) 0xb);
            // fixed value property length = 136
            sink.putShort((short) 0x88);
            sink.putLong(message.xid);
            message.cookie.putTo(sink);
            sink.putInt(message.priority);
            OFFlowRemovedReasonSerializerVer11.putTo(message.reason, sink);
            message.tableId.putTo(sink);
            sink.putLong(message.durationSec);
            sink.putLong(message.durationNsec);
            sink.putInt(message.idleTimeout);
            // skip pad (2 bytes)
            message.packetCount.putTo(sink);
            message.byteCount.putTo(sink);
            message.match.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFFlowRemovedVer11> {
        @Override
        public void write(ByteBuf bb, OFFlowRemovedVer11 message) {
            // fixed value property version = 2
            bb.writeByte((byte) 0x2);
            // fixed value property type = 11
            bb.writeByte((byte) 0xb);
            // fixed value property length = 136
            bb.writeShort((short) 0x88);
            bb.writeInt(U32.t(message.xid));
            bb.writeLong(message.cookie.getValue());
            bb.writeShort(U16.t(message.priority));
            OFFlowRemovedReasonSerializerVer11.writeTo(bb, message.reason);
            message.tableId.writeByte(bb);
            bb.writeInt(U32.t(message.durationSec));
            bb.writeInt(U32.t(message.durationNsec));
            bb.writeShort(U16.t(message.idleTimeout));
            // pad: 2 bytes
            bb.writeZero(2);
            bb.writeLong(message.packetCount.getValue());
            bb.writeLong(message.byteCount.getValue());
            message.match.writeTo(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFFlowRemovedVer11(");
        b.append("xid=").append(xid);
        b.append(", ");
        b.append("cookie=").append(cookie);
        b.append(", ");
        b.append("priority=").append(priority);
        b.append(", ");
        b.append("reason=").append(reason);
        b.append(", ");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("durationSec=").append(durationSec);
        b.append(", ");
        b.append("durationNsec=").append(durationNsec);
        b.append(", ");
        b.append("idleTimeout=").append(idleTimeout);
        b.append(", ");
        b.append("packetCount=").append(packetCount);
        b.append(", ");
        b.append("byteCount=").append(byteCount);
        b.append(", ");
        b.append("match=").append(match);
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
        OFFlowRemovedVer11 other = (OFFlowRemovedVer11) obj;

        if( xid != other.xid)
            return false;
        if (cookie == null) {
            if (other.cookie != null)
                return false;
        } else if (!cookie.equals(other.cookie))
            return false;
        if( priority != other.priority)
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
        if( durationSec != other.durationSec)
            return false;
        if( durationNsec != other.durationNsec)
            return false;
        if( idleTimeout != other.idleTimeout)
            return false;
        if (packetCount == null) {
            if (other.packetCount != null)
                return false;
        } else if (!packetCount.equals(other.packetCount))
            return false;
        if (byteCount == null) {
            if (other.byteCount != null)
                return false;
        } else if (!byteCount.equals(other.byteCount))
            return false;
        if (match == null) {
            if (other.match != null)
                return false;
        } else if (!match.equals(other.match))
            return false;
        return true;
    }

    public boolean equalsIgnoreXid(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFFlowRemovedVer11 other = (OFFlowRemovedVer11) obj;

        // ignore XID
        if (cookie == null) {
            if (other.cookie != null)
                return false;
        } else if (!cookie.equals(other.cookie))
            return false;
        if( priority != other.priority)
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
        if( durationSec != other.durationSec)
            return false;
        if( durationNsec != other.durationNsec)
            return false;
        if( idleTimeout != other.idleTimeout)
            return false;
        if (packetCount == null) {
            if (other.packetCount != null)
                return false;
        } else if (!packetCount.equals(other.packetCount))
            return false;
        if (byteCount == null) {
            if (other.byteCount != null)
                return false;
        } else if (!byteCount.equals(other.byteCount))
            return false;
        if (match == null) {
            if (other.match != null)
                return false;
        } else if (!match.equals(other.match))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (xid ^ (xid >>> 32));
        result = prime * result + ((cookie == null) ? 0 : cookie.hashCode());
        result = prime * result + priority;
        result = prime * result + ((reason == null) ? 0 : reason.hashCode());
        result = prime * result + ((tableId == null) ? 0 : tableId.hashCode());
        result = prime *  (int) (durationSec ^ (durationSec >>> 32));
        result = prime *  (int) (durationNsec ^ (durationNsec >>> 32));
        result = prime * result + idleTimeout;
        result = prime * result + ((packetCount == null) ? 0 : packetCount.hashCode());
        result = prime * result + ((byteCount == null) ? 0 : byteCount.hashCode());
        result = prime * result + ((match == null) ? 0 : match.hashCode());
        return result;
    }

}
