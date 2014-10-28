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

class OFTableFeaturePropTableSyncFromVer14 implements OFTableFeaturePropTableSyncFrom {
    private static final Logger logger = LoggerFactory.getLogger(OFTableFeaturePropTableSyncFromVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 4;

        private final static List<U8> DEFAULT_TABLE_IDS = ImmutableList.<U8>of();

    // OF message fields
    private final List<U8> tableIds;
//
    // Immutable default instance
    final static OFTableFeaturePropTableSyncFromVer14 DEFAULT = new OFTableFeaturePropTableSyncFromVer14(
        DEFAULT_TABLE_IDS
    );

    // package private constructor - used by readers, builders, and factory
    OFTableFeaturePropTableSyncFromVer14(List<U8> tableIds) {
        this.tableIds = tableIds;
    }

    // Accessors for OF message fields
    @Override
    public int getType() {
        return 0x10;
    }

    @Override
    public List<U8> getTableIds() {
        return tableIds;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFTableFeaturePropTableSyncFrom.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFTableFeaturePropTableSyncFrom.Builder {
        final OFTableFeaturePropTableSyncFromVer14 parentMessage;

        // OF message fields
        private boolean tableIdsSet;
        private List<U8> tableIds;

        BuilderWithParent(OFTableFeaturePropTableSyncFromVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getType() {
        return 0x10;
    }

    @Override
    public List<U8> getTableIds() {
        return tableIds;
    }

    @Override
    public OFTableFeaturePropTableSyncFrom.Builder setTableIds(List<U8> tableIds) {
        this.tableIds = tableIds;
        this.tableIdsSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFTableFeaturePropTableSyncFrom build() {
                List<U8> tableIds = this.tableIdsSet ? this.tableIds : parentMessage.tableIds;
                if(tableIds == null)
                    throw new NullPointerException("Property tableIds must not be null");

                //
                return new OFTableFeaturePropTableSyncFromVer14(
                    tableIds
                );
        }

    }

    static class Builder implements OFTableFeaturePropTableSyncFrom.Builder {
        // OF message fields
        private boolean tableIdsSet;
        private List<U8> tableIds;

    @Override
    public int getType() {
        return 0x10;
    }

    @Override
    public List<U8> getTableIds() {
        return tableIds;
    }

    @Override
    public OFTableFeaturePropTableSyncFrom.Builder setTableIds(List<U8> tableIds) {
        this.tableIds = tableIds;
        this.tableIdsSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFTableFeaturePropTableSyncFrom build() {
            List<U8> tableIds = this.tableIdsSet ? this.tableIds : DEFAULT_TABLE_IDS;
            if(tableIds == null)
                throw new NullPointerException("Property tableIds must not be null");


            return new OFTableFeaturePropTableSyncFromVer14(
                    tableIds
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFTableFeaturePropTableSyncFrom> {
        @Override
        public OFTableFeaturePropTableSyncFrom readFrom(ChannelBuffer bb) throws OFParseError {
            int start = bb.readerIndex();
            // fixed value property type == 0x10
            short type = bb.readShort();
            if(type != (short) 0x10)
                throw new OFParseError("Wrong type: Expected=0x10(0x10), got="+type);
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
            List<U8> tableIds = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), U8.READER);

            OFTableFeaturePropTableSyncFromVer14 tableFeaturePropTableSyncFromVer14 = new OFTableFeaturePropTableSyncFromVer14(
                    tableIds
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", tableFeaturePropTableSyncFromVer14);
            return tableFeaturePropTableSyncFromVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFTableFeaturePropTableSyncFromVer14Funnel FUNNEL = new OFTableFeaturePropTableSyncFromVer14Funnel();
    static class OFTableFeaturePropTableSyncFromVer14Funnel implements Funnel<OFTableFeaturePropTableSyncFromVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFTableFeaturePropTableSyncFromVer14 message, PrimitiveSink sink) {
            // fixed value property type = 0x10
            sink.putShort((short) 0x10);
            // FIXME: skip funnel of length
            FunnelUtils.putList(message.tableIds, sink);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFTableFeaturePropTableSyncFromVer14> {
        @Override
        public void write(ChannelBuffer bb, OFTableFeaturePropTableSyncFromVer14 message) {
            int startIndex = bb.writerIndex();
            // fixed value property type = 0x10
            bb.writeShort((short) 0x10);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            ChannelUtils.writeList(bb, message.tableIds);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFTableFeaturePropTableSyncFromVer14(");
        b.append("tableIds=").append(tableIds);
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
        OFTableFeaturePropTableSyncFromVer14 other = (OFTableFeaturePropTableSyncFromVer14) obj;

        if (tableIds == null) {
            if (other.tableIds != null)
                return false;
        } else if (!tableIds.equals(other.tableIds))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((tableIds == null) ? 0 : tableIds.hashCode());
        return result;
    }

}
