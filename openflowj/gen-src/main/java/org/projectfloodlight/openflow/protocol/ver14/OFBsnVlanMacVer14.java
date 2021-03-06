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

class OFBsnVlanMacVer14 implements OFBsnVlanMac {
    private static final Logger logger = LoggerFactory.getLogger(OFBsnVlanMacVer14.class);
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int LENGTH = 8;

        private final static int DEFAULT_VLAN_VID = 0x0;
        private final static MacAddress DEFAULT_MAC = MacAddress.NONE;

    // OF message fields
    private final int vlanVid;
    private final MacAddress mac;
//
    // Immutable default instance
    final static OFBsnVlanMacVer14 DEFAULT = new OFBsnVlanMacVer14(
        DEFAULT_VLAN_VID, DEFAULT_MAC
    );

    // package private constructor - used by readers, builders, and factory
    OFBsnVlanMacVer14(int vlanVid, MacAddress mac) {
        if(mac == null) {
            throw new NullPointerException("OFBsnVlanMacVer14: property mac cannot be null");
        }
        this.vlanVid = vlanVid;
        this.mac = mac;
    }

    // Accessors for OF message fields
    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public MacAddress getMac() {
        return mac;
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



    public OFBsnVlanMac.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFBsnVlanMac.Builder {
        final OFBsnVlanMacVer14 parentMessage;

        // OF message fields
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean macSet;
        private MacAddress mac;

        BuilderWithParent(OFBsnVlanMacVer14 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnVlanMac.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public MacAddress getMac() {
        return mac;
    }

    @Override
    public OFBsnVlanMac.Builder setMac(MacAddress mac) {
        this.mac = mac;
        this.macSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }



        @Override
        public OFBsnVlanMac build() {
                int vlanVid = this.vlanVidSet ? this.vlanVid : parentMessage.vlanVid;
                MacAddress mac = this.macSet ? this.mac : parentMessage.mac;
                if(mac == null)
                    throw new NullPointerException("Property mac must not be null");

                //
                return new OFBsnVlanMacVer14(
                    vlanVid,
                    mac
                );
        }

    }

    static class Builder implements OFBsnVlanMac.Builder {
        // OF message fields
        private boolean vlanVidSet;
        private int vlanVid;
        private boolean macSet;
        private MacAddress mac;

    @Override
    public int getVlanVid() {
        return vlanVid;
    }

    @Override
    public OFBsnVlanMac.Builder setVlanVid(int vlanVid) {
        this.vlanVid = vlanVid;
        this.vlanVidSet = true;
        return this;
    }
    @Override
    public MacAddress getMac() {
        return mac;
    }

    @Override
    public OFBsnVlanMac.Builder setMac(MacAddress mac) {
        this.mac = mac;
        this.macSet = true;
        return this;
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_14;
    }

//
        @Override
        public OFBsnVlanMac build() {
            int vlanVid = this.vlanVidSet ? this.vlanVid : DEFAULT_VLAN_VID;
            MacAddress mac = this.macSet ? this.mac : DEFAULT_MAC;
            if(mac == null)
                throw new NullPointerException("Property mac must not be null");


            return new OFBsnVlanMacVer14(
                    vlanVid,
                    mac
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFBsnVlanMac> {
        @Override
        public OFBsnVlanMac readFrom(ByteBuf bb) throws OFParseError {
            int vlanVid = U16.f(bb.readShort());
            MacAddress mac = MacAddress.read6Bytes(bb);

            OFBsnVlanMacVer14 bsnVlanMacVer14 = new OFBsnVlanMacVer14(
                    vlanVid,
                      mac
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", bsnVlanMacVer14);
            return bsnVlanMacVer14;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFBsnVlanMacVer14Funnel FUNNEL = new OFBsnVlanMacVer14Funnel();
    static class OFBsnVlanMacVer14Funnel implements Funnel<OFBsnVlanMacVer14> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFBsnVlanMacVer14 message, PrimitiveSink sink) {
            sink.putInt(message.vlanVid);
            message.mac.putTo(sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFBsnVlanMacVer14> {
        @Override
        public void write(ByteBuf bb, OFBsnVlanMacVer14 message) {
            bb.writeShort(U16.t(message.vlanVid));
            message.mac.write6Bytes(bb);


        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFBsnVlanMacVer14(");
        b.append("vlanVid=").append(vlanVid);
        b.append(", ");
        b.append("mac=").append(mac);
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
        OFBsnVlanMacVer14 other = (OFBsnVlanMacVer14) obj;

        if( vlanVid != other.vlanVid)
            return false;
        if (mac == null) {
            if (other.mac != null)
                return false;
        } else if (!mac.equals(other.mac))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + vlanVid;
        result = prime * result + ((mac == null) ? 0 : mac.hashCode());
        return result;
    }

}
