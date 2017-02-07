// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver10;

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


public class OFQueuePropsVer10 implements OFQueueProps {
    public final static OFQueuePropsVer10 INSTANCE = new OFQueuePropsVer10();




    public OFQueuePropMinRate.Builder buildMinRate() {
        return new OFQueuePropMinRateVer10.Builder();
    }
    public OFQueuePropMinRate minRate(int rate) {
        return new OFQueuePropMinRateVer10(
                rate
                    );
    }

    public OFQueuePropMaxRate.Builder buildMaxRate() {
        throw new UnsupportedOperationException("OFQueuePropMaxRate not supported in version 1.0");
    }
    public OFQueuePropMaxRate maxRate(int rate) {
        throw new UnsupportedOperationException("OFQueuePropMaxRate not supported in version 1.0");
    }

    public OFMessageReader<OFQueueProp> getReader() {
        return OFQueuePropVer10.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_10;
    }
}
