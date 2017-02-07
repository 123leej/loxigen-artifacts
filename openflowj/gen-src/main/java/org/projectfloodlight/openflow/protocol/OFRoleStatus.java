// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_interface.java
// Do not modify

package org.projectfloodlight.openflow.protocol;

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
import java.util.List;
import io.netty.buffer.ByteBuf;

public interface OFRoleStatus extends OFObject, OFMessage {
    OFVersion getVersion();
    OFType getType();
    long getXid();
    OFControllerRole getRole();
    OFControllerRoleReason getReason();
    U64 getGenerationId();
    List<OFRoleProp> getProperties();

    void writeTo(ByteBuf channelBuffer);

    Builder createBuilder();
    public interface Builder extends OFMessage.Builder {
        OFRoleStatus build();
        OFVersion getVersion();
        OFType getType();
        long getXid();
        Builder setXid(long xid);
        OFControllerRole getRole();
        Builder setRole(OFControllerRole role);
        OFControllerRoleReason getReason();
        Builder setReason(OFControllerRoleReason reason);
        U64 getGenerationId();
        Builder setGenerationId(U64 generationId);
        List<OFRoleProp> getProperties();
        Builder setProperties(List<OFRoleProp> properties);
    }
}
