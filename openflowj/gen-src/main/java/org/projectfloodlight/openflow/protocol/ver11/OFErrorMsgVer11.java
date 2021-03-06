// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
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
import io.netty.buffer.ByteBuf;

abstract class OFErrorMsgVer11 {
    // version: 1.1
    final static byte WIRE_VERSION = 2;
    final static int MINIMUM_LENGTH = 10;


    public final static OFErrorMsgVer11.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFErrorMsg> {
        @Override
        public OFErrorMsg readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            // fixed value property version == 2
            byte version = bb.readByte();
            if(version != (byte) 0x2)
                throw new OFParseError("Wrong version: Expected=OFVersion.OF_11(2), got="+version);
            // fixed value property type == 1
            byte type = bb.readByte();
            if(type != (byte) 0x1)
                throw new OFParseError("Wrong type: Expected=OFType.ERROR(1), got="+type);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            U32.f(bb.readInt());
            short errType = bb.readShort();
            bb.readerIndex(start);
            switch(errType) {
               case (short) 0x2:
                   // discriminator value OFErrorType.BAD_ACTION=2 for class OFBadActionErrorMsgVer11
                   return OFBadActionErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x1:
                   // discriminator value OFErrorType.BAD_REQUEST=1 for class OFBadRequestErrorMsgVer11
                   return OFBadRequestErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x5:
                   // discriminator value OFErrorType.FLOW_MOD_FAILED=5 for class OFFlowModFailedErrorMsgVer11
                   return OFFlowModFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x0:
                   // discriminator value OFErrorType.HELLO_FAILED=0 for class OFHelloFailedErrorMsgVer11
                   return OFHelloFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x7:
                   // discriminator value OFErrorType.PORT_MOD_FAILED=7 for class OFPortModFailedErrorMsgVer11
                   return OFPortModFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x9:
                   // discriminator value OFErrorType.QUEUE_OP_FAILED=9 for class OFQueueOpFailedErrorMsgVer11
                   return OFQueueOpFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x3:
                   // discriminator value OFErrorType.BAD_INSTRUCTION=3 for class OFBadInstructionErrorMsgVer11
                   return OFBadInstructionErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x4:
                   // discriminator value OFErrorType.BAD_MATCH=4 for class OFBadMatchErrorMsgVer11
                   return OFBadMatchErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x6:
                   // discriminator value OFErrorType.GROUP_MOD_FAILED=6 for class OFGroupModFailedErrorMsgVer11
                   return OFGroupModFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0xa:
                   // discriminator value OFErrorType.SWITCH_CONFIG_FAILED=10 for class OFSwitchConfigFailedErrorMsgVer11
                   return OFSwitchConfigFailedErrorMsgVer11.READER.readFrom(bb);
               case (short) 0x8:
                   // discriminator value OFErrorType.TABLE_MOD_FAILED=8 for class OFTableModFailedErrorMsgVer11
                   return OFTableModFailedErrorMsgVer11.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator errType of class OFErrorMsgVer11: " + errType);
            }
        }
    }
}
