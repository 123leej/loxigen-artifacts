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
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFActionBsnGentableVer14 implements OFActionBsnGentable {
    private static final Logger logger = LoggerFactory.getLogger(OFActionBsnGentableVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 16;

        private final static long DEFAULT_TABLE_ID = 0x0L;
        private final static List<OFBsnTlv> DEFAULT_KEY = ImmutableList.<OFBsnTlv>of();

    // OF message fields
    private final long tableId;
    private final List<OFBsnTlv> key;
//
    // Immutable default instance
    final static OFActionBsnGentableVer14 DEFAULT = new OFActionBsnGentableVer14(
        DEFAULT_TABLE_ID, DEFAULT_KEY
    );

    // package private constructor - used by readers, builders, and factory
    OFActionBsnGentableVer14(long tableId, List<OFBsnTlv> key) {
        if(key == null) {
            throw new NullPointerException("OFActionBsnGentableVer14: property key cannot be null");
        }
        this.tableId = tableId;
        this.key = key;
    }

    // Accessors for OF message fields
    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x5L;
    }

    @Override
    public long getTableId() {
        return tableId;
    }

    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFActionBsnGentable.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFActionBsnGentable.Builder {
        final OFActionBsnGentableVer14 parentMessage;

        // OF message fields
        private boolean tableIdSet;
        private long tableId;
        private boolean keySet;
        private List<OFBsnTlv> key;

        BuilderWithParent(OFActionBsnGentableVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x5L;
    }

    @Override
    public long getTableId() {
        return tableId;
    }

    @Override
    public OFActionBsnGentable.Builder setTableId(long tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFActionBsnGentable.Builder setKey(List<OFBsnTlv> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFActionBsnGentable build() {
                long tableId = this.tableIdSet ? this.tableId : parentMessage.tableId;
                List<OFBsnTlv> key = this.keySet ? this.key : parentMessage.key;
                if(key == null)
                    throw new NullPointerException("Property key must not be null");

                //
                return new OFActionBsnGentableVer14(
                    tableId,
                    key
                );
        }

    }

    static class Builder implements OFActionBsnGentable.Builder {
        // OF message fields
        private boolean tableIdSet;
        private long tableId;
        private boolean keySet;
        private List<OFBsnTlv> key;

    @Override
    public OFActionType getType() {
        return OFActionType.EXPERIMENTER;
    }

    @Override
    public long getExperimenter() {
        return 0x5c16c7L;
    }

    @Override
    public long getSubtype() {
        return 0x5L;
    }

    @Override
    public long getTableId() {
        return tableId;
    }

    @Override
    public OFActionBsnGentable.Builder setTableId(long tableId) {
        this.tableId = tableId;
        this.tableIdSet = true;
        return this;
    }
    @Override
    public List<OFBsnTlv> getKey() {
        return key;
    }

    @Override
    public OFActionBsnGentable.Builder setKey(List<OFBsnTlv> key) {
        this.key = key;
        this.keySet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFActionBsnGentable build() {
            long tableId = this.tableIdSet ? this.tableId : DEFAULT_TABLE_ID;
            List<OFBsnTlv> key = this.keySet ? this.key : DEFAULT_KEY;
            if(key == null)
                throw new NullPointerException("Property key must not be null");


            return new OFActionBsnGentableVer14(
                    tableId,
                    key
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFActionBsnGentable> {
        @Override
        public OFActionBsnGentable readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 65535
            short type = bb.readShort();
            if(type != (short) 0xffff)
                throw new OFParseError("Wrong type: Expected=OFActionType.EXPERIMENTER(65535), got="+type);
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
            // fixed value property experimenter == 0x5c16c7L
            int experimenter = bb.readInt();
            if(experimenter != 0x5c16c7)
                throw new OFParseError("Wrong experimenter: Expected=0x5c16c7L(0x5c16c7L), got="+experimenter);
            // fixed value property subtype == 0x5L
            int subtype = bb.readInt();
            if(subtype != 0x5)
                throw new OFParseError("Wrong subtype: Expected=0x5L(0x5L), got="+subtype);
            long tableId = U32.f(bb.readInt());
            List<OFBsnTlv> key = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFBsnTlvVer14.READER);

            OFActionBsnGentableVer14 actionBsnGentableVer14 = new OFActionBsnGentableVer14(
                    tableId,
                      key
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", actionBsnGentableVer14);
            return actionBsnGentableVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFActionBsnGentableVer14Funnel FUNNEL = new OFActionBsnGentableVer14Funnel();
    static class OFActionBsnGentableVer14Funnel implements Funnel<OFActionBsnGentableVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFActionBsnGentableVer14 message, PrimitiveSink sink) {
            // fixed value property type = 65535
            sink.putShort((short) 0xffff);
            // FIXME: skip funnel of length
            // fixed value property experimenter = 0x5c16c7L
            sink.putInt(0x5c16c7);
            // fixed value property subtype = 0x5L
            sink.putInt(0x5);
            sink.putLong(message.tableId);
            FunnelUtils.putList(message.key, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFActionBsnGentableVer14> {
        @Override
        public void write(ByteBuf bb, OFActionBsnGentableVer14 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 65535
            bb.writeShort((short) 0xffff);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            // fixed value property experimenter = 0x5c16c7L
            bb.writeInt(0x5c16c7);
            // fixed value property subtype = 0x5L
            bb.writeInt(0x5);
            bb.writeInt(U32.t(message.tableId));
            ChannelUtils.writeList(bb, message.key);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFActionBsnGentableVer14(");
        b.append("tableId=").append(tableId);
        b.append(", ");
        b.append("key=").append(key);
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
        OFActionBsnGentableVer14 other = (OFActionBsnGentableVer14) obj;

        if( tableId != other.tableId)
            return false;
        if (key == null) {
            if (other.key != null)
                return false;
        } else if (!key.equals(other.key))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (tableId ^ (tableId >>> 32));
        result = prime * result + ((key == null) ? 0 : key.hashCode());
        return result;
    }

}
