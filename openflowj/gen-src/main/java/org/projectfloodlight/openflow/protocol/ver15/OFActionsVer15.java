// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_class.java
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
import java.util.Set;
import java.util.List;


public class OFActionsVer15 implements OFActions {
    public final static OFActionsVer15 INSTANCE = new OFActionsVer15();




    public OFActionBsnChecksum.Builder buildBsnChecksum() {
        return new OFActionBsnChecksumVer15.Builder();
    }
    public OFActionBsnChecksum bsnChecksum(U128 checksum) {
        return new OFActionBsnChecksumVer15(
                checksum
                    );
    }

    public OFActionBsnMirror.Builder buildBsnMirror() {
        return new OFActionBsnMirrorVer15.Builder();
    }

    public OFActionBsnSetTunnelDst.Builder buildBsnSetTunnelDst() {
        return new OFActionBsnSetTunnelDstVer15.Builder();
    }
    public OFActionBsnSetTunnelDst bsnSetTunnelDst(long dst) {
        return new OFActionBsnSetTunnelDstVer15(
                dst
                    );
    }

    public OFActionEnqueue.Builder buildEnqueue() {
        throw new UnsupportedOperationException("OFActionEnqueue not supported in version 1.5");
    }
    public OFActionEnqueue enqueue(OFPort port, long queueId) {
        throw new UnsupportedOperationException("OFActionEnqueue not supported in version 1.5");
    }

    public OFActionNiciraDecTtl niciraDecTtl() {
        return OFActionNiciraDecTtlVer15.INSTANCE;
    }

    public OFActionNiciraExit niciraExit() {
        return OFActionNiciraExitVer15.INSTANCE;
    }

    public OFActionNiciraResubmit.Builder buildNiciraResubmit() {
        return new OFActionNiciraResubmitVer15.Builder();
    }
    public OFActionNiciraResubmit niciraResubmit(OFPort port) {
        return new OFActionNiciraResubmitVer15(
                port
                    );
    }

    public OFActionNiciraResubmitTable.Builder buildNiciraResubmitTable() {
        return new OFActionNiciraResubmitTableVer15.Builder();
    }
    public OFActionNiciraResubmitTable niciraResubmitTable(OFPort port, TableId tableId) {
        return new OFActionNiciraResubmitTableVer15(
                port,
                      tableId
                    );
    }

    public OFActionOutput.Builder buildOutput() {
        return new OFActionOutputVer15.Builder();
    }
    public OFActionOutput output(OFPort port, int maxLen) {
        return new OFActionOutputVer15(
                port,
                      maxLen
                    );
    }

    public OFActionSetDlDst.Builder buildSetDlDst() {
        throw new UnsupportedOperationException("OFActionSetDlDst not supported in version 1.5");
    }
    public OFActionSetDlDst setDlDst(MacAddress dlAddr) {
        throw new UnsupportedOperationException("OFActionSetDlDst not supported in version 1.5");
    }

    public OFActionSetDlSrc.Builder buildSetDlSrc() {
        throw new UnsupportedOperationException("OFActionSetDlSrc not supported in version 1.5");
    }
    public OFActionSetDlSrc setDlSrc(MacAddress dlAddr) {
        throw new UnsupportedOperationException("OFActionSetDlSrc not supported in version 1.5");
    }

    public OFActionSetNwDst.Builder buildSetNwDst() {
        throw new UnsupportedOperationException("OFActionSetNwDst not supported in version 1.5");
    }
    public OFActionSetNwDst setNwDst(IPv4Address nwAddr) {
        throw new UnsupportedOperationException("OFActionSetNwDst not supported in version 1.5");
    }

    public OFActionSetNwSrc.Builder buildSetNwSrc() {
        throw new UnsupportedOperationException("OFActionSetNwSrc not supported in version 1.5");
    }
    public OFActionSetNwSrc setNwSrc(IPv4Address nwAddr) {
        throw new UnsupportedOperationException("OFActionSetNwSrc not supported in version 1.5");
    }

    public OFActionSetNwTos.Builder buildSetNwTos() {
        throw new UnsupportedOperationException("OFActionSetNwTos not supported in version 1.5");
    }
    public OFActionSetNwTos setNwTos(short nwTos) {
        throw new UnsupportedOperationException("OFActionSetNwTos not supported in version 1.5");
    }

    public OFActionSetTpDst.Builder buildSetTpDst() {
        throw new UnsupportedOperationException("OFActionSetTpDst not supported in version 1.5");
    }
    public OFActionSetTpDst setTpDst(TransportPort tpPort) {
        throw new UnsupportedOperationException("OFActionSetTpDst not supported in version 1.5");
    }

    public OFActionSetTpSrc.Builder buildSetTpSrc() {
        throw new UnsupportedOperationException("OFActionSetTpSrc not supported in version 1.5");
    }
    public OFActionSetTpSrc setTpSrc(TransportPort tpPort) {
        throw new UnsupportedOperationException("OFActionSetTpSrc not supported in version 1.5");
    }

    public OFActionSetVlanPcp.Builder buildSetVlanPcp() {
        throw new UnsupportedOperationException("OFActionSetVlanPcp not supported in version 1.5");
    }
    public OFActionSetVlanPcp setVlanPcp(VlanPcp vlanPcp) {
        throw new UnsupportedOperationException("OFActionSetVlanPcp not supported in version 1.5");
    }

    public OFActionSetVlanVid.Builder buildSetVlanVid() {
        throw new UnsupportedOperationException("OFActionSetVlanVid not supported in version 1.5");
    }
    public OFActionSetVlanVid setVlanVid(VlanVid vlanVid) {
        throw new UnsupportedOperationException("OFActionSetVlanVid not supported in version 1.5");
    }

    public OFActionStripVlan stripVlan() {
        throw new UnsupportedOperationException("OFActionStripVlan not supported in version 1.5");
    }

    public OFActionCopyTtlIn copyTtlIn() {
        return OFActionCopyTtlInVer15.INSTANCE;
    }

    public OFActionCopyTtlOut copyTtlOut() {
        return OFActionCopyTtlOutVer15.INSTANCE;
    }

    public OFActionDecMplsTtl decMplsTtl() {
        return OFActionDecMplsTtlVer15.INSTANCE;
    }

    public OFActionDecNwTtl decNwTtl() {
        return OFActionDecNwTtlVer15.INSTANCE;
    }

    public OFActionGroup.Builder buildGroup() {
        return new OFActionGroupVer15.Builder();
    }
    public OFActionGroup group(OFGroup group) {
        return new OFActionGroupVer15(
                group
                    );
    }

    public OFActionPopMpls.Builder buildPopMpls() {
        return new OFActionPopMplsVer15.Builder();
    }
    public OFActionPopMpls popMpls(EthType ethertype) {
        return new OFActionPopMplsVer15(
                ethertype
                    );
    }

    public OFActionPopVlan popVlan() {
        return OFActionPopVlanVer15.INSTANCE;
    }

    public OFActionPushMpls.Builder buildPushMpls() {
        return new OFActionPushMplsVer15.Builder();
    }
    public OFActionPushMpls pushMpls(EthType ethertype) {
        return new OFActionPushMplsVer15(
                ethertype
                    );
    }

    public OFActionPushVlan.Builder buildPushVlan() {
        return new OFActionPushVlanVer15.Builder();
    }
    public OFActionPushVlan pushVlan(EthType ethertype) {
        return new OFActionPushVlanVer15(
                ethertype
                    );
    }

    public OFActionSetMplsLabel.Builder buildSetMplsLabel() {
        throw new UnsupportedOperationException("OFActionSetMplsLabel not supported in version 1.5");
    }
    public OFActionSetMplsLabel setMplsLabel(long mplsLabel) {
        throw new UnsupportedOperationException("OFActionSetMplsLabel not supported in version 1.5");
    }

    public OFActionSetMplsTc.Builder buildSetMplsTc() {
        throw new UnsupportedOperationException("OFActionSetMplsTc not supported in version 1.5");
    }
    public OFActionSetMplsTc setMplsTc(short mplsTc) {
        throw new UnsupportedOperationException("OFActionSetMplsTc not supported in version 1.5");
    }

    public OFActionSetMplsTtl.Builder buildSetMplsTtl() {
        return new OFActionSetMplsTtlVer15.Builder();
    }
    public OFActionSetMplsTtl setMplsTtl(short mplsTtl) {
        return new OFActionSetMplsTtlVer15(
                mplsTtl
                    );
    }

    public OFActionSetNwEcn.Builder buildSetNwEcn() {
        throw new UnsupportedOperationException("OFActionSetNwEcn not supported in version 1.5");
    }
    public OFActionSetNwEcn setNwEcn(IpEcn nwEcn) {
        throw new UnsupportedOperationException("OFActionSetNwEcn not supported in version 1.5");
    }

    public OFActionSetNwTtl.Builder buildSetNwTtl() {
        return new OFActionSetNwTtlVer15.Builder();
    }
    public OFActionSetNwTtl setNwTtl(short nwTtl) {
        return new OFActionSetNwTtlVer15(
                nwTtl
                    );
    }

    public OFActionSetQueue.Builder buildSetQueue() {
        return new OFActionSetQueueVer15.Builder();
    }
    public OFActionSetQueue setQueue(long queueId) {
        return new OFActionSetQueueVer15(
                queueId
                    );
    }

    public OFActionSetField.Builder buildSetField() {
        return new OFActionSetFieldVer15.Builder();
    }
    public OFActionSetField setField(OFOxm<?> field) {
        return new OFActionSetFieldVer15(
                field
                    );
    }

    public OFActionBsnGentable.Builder buildBsnGentable() {
        return new OFActionBsnGentableVer15.Builder();
    }
    public OFActionBsnGentable bsnGentable(long tableId, List<OFBsnTlv> key) {
        return new OFActionBsnGentableVer15(
                tableId,
                      key
                    );
    }

    public OFActionPopPbb popPbb() {
        return OFActionPopPbbVer15.INSTANCE;
    }

    public OFActionPushPbb.Builder buildPushPbb() {
        return new OFActionPushPbbVer15.Builder();
    }
    public OFActionPushPbb pushPbb(EthType ethertype) {
        return new OFActionPushPbbVer15(
                ethertype
                    );
    }

    public OFActionMeter.Builder buildMeter() {
        return new OFActionMeterVer15.Builder();
    }
    public OFActionMeter meter(long meterId) {
        return new OFActionMeterVer15(
                meterId
                    );
    }

    public OFMessageReader<OFAction> getReader() {
        return OFActionVer15.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_15;
    }
}
