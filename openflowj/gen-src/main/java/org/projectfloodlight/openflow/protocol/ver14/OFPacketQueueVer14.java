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

class OFPacketQueueVer14 implements OFPacketQueue {
    private static final Logger logger = LoggerFactory.getLogger(OFPacketQueueVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 16;

        private final static long DEFAULT_QUEUE_ID = 0x0L;
        private final static OFPort DEFAULT_PORT = OFPort.ANY;
        private final static List<OFQueueProp> DEFAULT_PROPERTIES = ImmutableList.<OFQueueProp>of();

    // OF message fields
    private final long queueId;
    private final OFPort port;
    private final List<OFQueueProp> properties;
//
    // Immutable default instance
    final static OFPacketQueueVer14 DEFAULT = new OFPacketQueueVer14(
        DEFAULT_QUEUE_ID, DEFAULT_PORT, DEFAULT_PROPERTIES
    );

    // package private constructor - used by readers, builders, and factory
    OFPacketQueueVer14(long queueId, OFPort port, List<OFQueueProp> properties) {
        this.queueId = queueId;
        this.port = port;
        this.properties = properties;
    }

    // Accessors for OF message fields
    @Override
    public long getQueueId() {
        return queueId;
    }

    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public List<OFQueueProp> getProperties() {
        return properties;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFPacketQueue.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPacketQueue.Builder {
        final OFPacketQueueVer14 parentMessage;

        // OF message fields
        private boolean queueIdSet;
        private long queueId;
        private boolean portSet;
        private OFPort port;
        private boolean propertiesSet;
        private List<OFQueueProp> properties;

        BuilderWithParent(OFPacketQueueVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public long getQueueId() {
        return queueId;
    }

    @Override
    public OFPacketQueue.Builder setQueueId(long queueId) {
        this.queueId = queueId;
        this.queueIdSet = true;
        return this;
    }
    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public OFPacketQueue.Builder setPort(OFPort port) {
        this.port = port;
        this.portSet = true;
        return this;
    }
    @Override
    public List<OFQueueProp> getProperties() {
        return properties;
    }

    @Override
    public OFPacketQueue.Builder setProperties(List<OFQueueProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFPacketQueue build() {
                long queueId = this.queueIdSet ? this.queueId : parentMessage.queueId;
                OFPort port = this.portSet ? this.port : parentMessage.port;
                if(port == null)
                    throw new NullPointerException("Property port must not be null");
                List<OFQueueProp> properties = this.propertiesSet ? this.properties : parentMessage.properties;
                if(properties == null)
                    throw new NullPointerException("Property properties must not be null");

                //
                return new OFPacketQueueVer14(
                    queueId,
                    port,
                    properties
                );
        }

    }

    static class Builder implements OFPacketQueue.Builder {
        // OF message fields
        private boolean queueIdSet;
        private long queueId;
        private boolean portSet;
        private OFPort port;
        private boolean propertiesSet;
        private List<OFQueueProp> properties;

    @Override
    public long getQueueId() {
        return queueId;
    }

    @Override
    public OFPacketQueue.Builder setQueueId(long queueId) {
        this.queueId = queueId;
        this.queueIdSet = true;
        return this;
    }
    @Override
    public OFPort getPort() {
        return port;
    }

    @Override
    public OFPacketQueue.Builder setPort(OFPort port) {
        this.port = port;
        this.portSet = true;
        return this;
    }
    @Override
    public List<OFQueueProp> getProperties() {
        return properties;
    }

    @Override
    public OFPacketQueue.Builder setProperties(List<OFQueueProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFPacketQueue build() {
            long queueId = this.queueIdSet ? this.queueId : DEFAULT_QUEUE_ID;
            OFPort port = this.portSet ? this.port : DEFAULT_PORT;
            if(port == null)
                throw new NullPointerException("Property port must not be null");
            List<OFQueueProp> properties = this.propertiesSet ? this.properties : DEFAULT_PROPERTIES;
            if(properties == null)
                throw new NullPointerException("Property properties must not be null");


            return new OFPacketQueueVer14(
                    queueId,
                    port,
                    properties
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPacketQueue> {
        @Override
        public OFPacketQueue readFrom(ChannelBuffer bb) throws OFParseError {
            int start = bb.readerIndex();
            long queueId = U32.f(bb.readInt());
            OFPort port = OFPort.read4Bytes(bb);
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
            // pad: 6 bytes
            bb.skipBytes(6);
            List<OFQueueProp> properties = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFQueuePropVer14.READER);

            OFPacketQueueVer14 packetQueueVer14 = new OFPacketQueueVer14(
                    queueId,
                      port,
                      properties
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", packetQueueVer14);
            return packetQueueVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPacketQueueVer14Funnel FUNNEL = new OFPacketQueueVer14Funnel();
    static class OFPacketQueueVer14Funnel implements Funnel<OFPacketQueueVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPacketQueueVer14 message, PrimitiveSink sink) {
            sink.putLong(message.queueId);
            message.port.putTo(sink);
            // FIXME: skip funnel of length
            // skip pad (6 bytes)
            FunnelUtils.putList(message.properties, sink);
        }
    }


    public void writeTo(ChannelBuffer bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPacketQueueVer14> {
        @Override
        public void write(ChannelBuffer bb, OFPacketQueueVer14 message) {
            int startIndex = bb.writerIndex();
            bb.writeInt(U32.t(message.queueId));
            message.port.write4Bytes(bb);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            // pad: 6 bytes
            bb.writeZero(6);
            ChannelUtils.writeList(bb, message.properties);

            // update length field
            int length = bb.writerIndex() - startIndex;
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPacketQueueVer14(");
        b.append("queueId=").append(queueId);
        b.append(", ");
        b.append("port=").append(port);
        b.append(", ");
        b.append("properties=").append(properties);
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
        OFPacketQueueVer14 other = (OFPacketQueueVer14) obj;

        if( queueId != other.queueId)
            return false;
        if (port == null) {
            if (other.port != null)
                return false;
        } else if (!port.equals(other.port))
            return false;
        if (properties == null) {
            if (other.properties != null)
                return false;
        } else if (!properties.equals(other.properties))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime *  (int) (queueId ^ (queueId >>> 32));
        result = prime * result + ((port == null) ? 0 : port.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

}
