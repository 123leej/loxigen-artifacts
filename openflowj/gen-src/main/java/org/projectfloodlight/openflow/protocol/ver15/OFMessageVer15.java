// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
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
import io.netty.buffer.ByteBuf;
import java.util.Set;

abstract class OFMessageVer15 {
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 8;


    public final static OFMessageVer15.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFMessage> {
        @Override
        public OFMessage readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 6
            byte version = bb.readByte();
            if(version != (byte) 0x6)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_15(6), got="+version);
            byte type = bb.readByte();
            bb.readerIndex(start);
            switch(type) {
               case (byte) 0x13:
                   // discriminator value OFType.STATS_REPLY=19 for class OFStatsReplyVer15
                   return OFStatsReplyVer15.READER.readFrom(bb);
               case (byte) 0x12:
                   // discriminator value OFType.STATS_REQUEST=18 for class OFStatsRequestVer15
                   return OFStatsRequestVer15.READER.readFrom(bb);
               case (byte) 0x1:
                   // discriminator value OFType.ERROR=1 for class OFErrorMsgVer15
                   return OFErrorMsgVer15.READER.readFrom(bb);
               case (byte) 0x15:
                   // discriminator value OFType.BARRIER_REPLY=21 for class OFBarrierReplyVer15
                   return OFBarrierReplyVer15.READER.readFrom(bb);
               case (byte) 0x14:
                   // discriminator value OFType.BARRIER_REQUEST=20 for class OFBarrierRequestVer15
                   return OFBarrierRequestVer15.READER.readFrom(bb);
               case (byte) 0x4:
                   // discriminator value OFType.EXPERIMENTER=4 for class OFExperimenterVer15
                   return OFExperimenterVer15.READER.readFrom(bb);
               case (byte) 0x3:
                   // discriminator value OFType.ECHO_REPLY=3 for class OFEchoReplyVer15
                   return OFEchoReplyVer15.READER.readFrom(bb);
               case (byte) 0x2:
                   // discriminator value OFType.ECHO_REQUEST=2 for class OFEchoRequestVer15
                   return OFEchoRequestVer15.READER.readFrom(bb);
               case (byte) 0x6:
                   // discriminator value OFType.FEATURES_REPLY=6 for class OFFeaturesReplyVer15
                   return OFFeaturesReplyVer15.READER.readFrom(bb);
               case (byte) 0x5:
                   // discriminator value OFType.FEATURES_REQUEST=5 for class OFFeaturesRequestVer15
                   return OFFeaturesRequestVer15.READER.readFrom(bb);
               case (byte) 0xe:
                   // discriminator value OFType.FLOW_MOD=14 for class OFFlowModVer15
                   return OFFlowModVer15.READER.readFrom(bb);
               case (byte) 0xb:
                   // discriminator value OFType.FLOW_REMOVED=11 for class OFFlowRemovedVer15
                   return OFFlowRemovedVer15.READER.readFrom(bb);
               case (byte) 0x8:
                   // discriminator value OFType.GET_CONFIG_REPLY=8 for class OFGetConfigReplyVer15
                   return OFGetConfigReplyVer15.READER.readFrom(bb);
               case (byte) 0x7:
                   // discriminator value OFType.GET_CONFIG_REQUEST=7 for class OFGetConfigRequestVer15
                   return OFGetConfigRequestVer15.READER.readFrom(bb);
               case (byte) 0x0:
                   // discriminator value OFType.HELLO=0 for class OFHelloVer15
                   return OFHelloVer15.READER.readFrom(bb);
               case (byte) 0xa:
                   // discriminator value OFType.PACKET_IN=10 for class OFPacketInVer15
                   return OFPacketInVer15.READER.readFrom(bb);
               case (byte) 0xd:
                   // discriminator value OFType.PACKET_OUT=13 for class OFPacketOutVer15
                   return OFPacketOutVer15.READER.readFrom(bb);
               case (byte) 0x10:
                   // discriminator value OFType.PORT_MOD=16 for class OFPortModVer15
                   return OFPortModVer15.READER.readFrom(bb);
               case (byte) 0xc:
                   // discriminator value OFType.PORT_STATUS=12 for class OFPortStatusVer15
                   return OFPortStatusVer15.READER.readFrom(bb);
               case (byte) 0x9:
                   // discriminator value OFType.SET_CONFIG=9 for class OFSetConfigVer15
                   return OFSetConfigVer15.READER.readFrom(bb);
               case (byte) 0x11:
                   // discriminator value OFType.TABLE_MOD=17 for class OFTableModVer15
                   return OFTableModVer15.READER.readFrom(bb);
               case (byte) 0xf:
                   // discriminator value OFType.GROUP_MOD=15 for class OFGroupModVer15
                   return OFGroupModVer15.READER.readFrom(bb);
               case (byte) 0x19:
                   // discriminator value OFType.ROLE_REPLY=25 for class OFRoleReplyVer15
                   return OFRoleReplyVer15.READER.readFrom(bb);
               case (byte) 0x18:
                   // discriminator value OFType.ROLE_REQUEST=24 for class OFRoleRequestVer15
                   return OFRoleRequestVer15.READER.readFrom(bb);
               case (byte) 0x1b:
                   // discriminator value OFType.GET_ASYNC_REPLY=27 for class OFAsyncGetReplyVer15
                   return OFAsyncGetReplyVer15.READER.readFrom(bb);
               case (byte) 0x1a:
                   // discriminator value OFType.GET_ASYNC_REQUEST=26 for class OFAsyncGetRequestVer15
                   return OFAsyncGetRequestVer15.READER.readFrom(bb);
               case (byte) 0x1c:
                   // discriminator value OFType.SET_ASYNC=28 for class OFAsyncSetVer15
                   return OFAsyncSetVer15.READER.readFrom(bb);
               case (byte) 0x1d:
                   // discriminator value OFType.METER_MOD=29 for class OFMeterModVer15
                   return OFMeterModVer15.READER.readFrom(bb);
               case (byte) 0x22:
                   // discriminator value OFType.BUNDLE_ADD_MESSAGE=34 for class OFBundleAddMsgVer15
                   return OFBundleAddMsgVer15.READER.readFrom(bb);
               case (byte) 0x21:
                   // discriminator value OFType.BUNDLE_CONTROL=33 for class OFBundleCtrlMsgVer15
                   return OFBundleCtrlMsgVer15.READER.readFrom(bb);
               case (byte) 0x20:
                   // discriminator value OFType.REQUESTFORWARD=32 for class OFRequestforwardVer15
                   return OFRequestforwardVer15.READER.readFrom(bb);
               case (byte) 0x1e:
                   // discriminator value OFType.ROLE_STATUS=30 for class OFRoleStatusVer15
                   return OFRoleStatusVer15.READER.readFrom(bb);
               case (byte) 0x1f:
                   // discriminator value OFType.TABLE_STATUS=31 for class OFTableStatusVer15
                   return OFTableStatusVer15.READER.readFrom(bb);
               case (byte) 0x23:
                   // discriminator value OFType.CONTROLLER_STATUS=35 for class OFControllerStatusVer15
                   return OFControllerStatusVer15.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator type of class OFMessageVer15: " + type);
            }
        }
    }
}
