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

class OFFlowMonitorReplyEntryVer15 implements OFFlowMonitorReplyEntry {
    private static final Logger logger = LoggerFactory.getLogger(OFFlowMonitorReplyEntryVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int LENGTH = 4;


    // OF message fields
    private final OFFlowUpdateEvent event;
//

    // package private constructor - used by readers, builders, and factory
    OFFlowMonitorReplyEntryVer15(OFFlowUpdateEvent event) {
        if(event == null) {
            throw new NullPointerException("OFFlowMonitorReplyEntryVer15: property event cannot be null");
        }
        this.event = event;
    }

    // Accessors for OF message fields
    @Override
    public OFFlowUpdateEvent getEvent() {
        return event;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    public OFFlowMonitorReplyEntry.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFFlowMonitorReplyEntry.Builder {
        final OFFlowMonitorReplyEntryVer15 parentMessage;

        // OF message fields
        private boolean eventSet;
        private OFFlowUpdateEvent event;

        BuilderWithParent(OFFlowMonitorReplyEntryVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public OFFlowUpdateEvent getEvent() {
        return event;
    }

    @Override
    public OFFlowMonitorReplyEntry.Builder setEvent(OFFlowUpdateEvent event) {
        this.event = event;
        this.eventSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFFlowMonitorReplyEntry build() {
                OFFlowUpdateEvent event = this.eventSet ? this.event : parentMessage.event;
                if(event == null)
                    throw new NullPointerException("Property event must not be null");

                //
                return new OFFlowMonitorReplyEntryVer15(
                    event
                );
        }

    }

    static class Builder implements OFFlowMonitorReplyEntry.Builder {
        // OF message fields
        private boolean eventSet;
        private OFFlowUpdateEvent event;

    @Override
    public OFFlowUpdateEvent getEvent() {
        return event;
    }

    @Override
    public OFFlowMonitorReplyEntry.Builder setEvent(OFFlowUpdateEvent event) {
        this.event = event;
        this.eventSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFFlowMonitorReplyEntry build() {
            if(!this.eventSet)
                throw new IllegalStateException("Property event doesn't have default value -- must be set");
            if(event == null)
                throw new NullPointerException("Property event must not be null");


            return new OFFlowMonitorReplyEntryVer15(
                    event
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFFlowMonitorReplyEntry> {
        @Override
        public OFFlowMonitorReplyEntry readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            int length = U16.f(bb.readShort());
            if(length != 4)
                throw new OFParseError("Wrong length: Expected=4(4), got="+length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            OFFlowUpdateEvent event = OFFlowUpdateEventSerializerVer15.readFrom(bb);

            OFFlowMonitorReplyEntryVer15 flowMonitorReplyEntryVer15 = new OFFlowMonitorReplyEntryVer15(
                    event
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", flowMonitorReplyEntryVer15);
            return flowMonitorReplyEntryVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFFlowMonitorReplyEntryVer15Funnel FUNNEL = new OFFlowMonitorReplyEntryVer15Funnel();
    static class OFFlowMonitorReplyEntryVer15Funnel implements Funnel<OFFlowMonitorReplyEntryVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFFlowMonitorReplyEntryVer15 message, PrimitiveSink sink) {
            // fixed value property length = 4
            sink.putShort((short) 0x4);
            OFFlowUpdateEventSerializerVer15.putTo(message.event, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFFlowMonitorReplyEntryVer15> {
        @Override
        public void write(ByteBuf bb, OFFlowMonitorReplyEntryVer15 message) {
            // fixed value property length = 4
            bb.writeShort((short) 0x4);
            OFFlowUpdateEventSerializerVer15.writeTo(bb, message.event);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFFlowMonitorReplyEntryVer15(");
        b.append("event=").append(event);
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
        OFFlowMonitorReplyEntryVer15 other = (OFFlowMonitorReplyEntryVer15) obj;

        if (event == null) {
            if (other.event != null)
                return false;
        } else if (!event.equals(other.event))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((event == null) ? 0 : event.hashCode());
        return result;
    }

}
