// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver13;

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


public class OFActionsVer13 implements OFActions {
    public final static OFActionsVer13 INSTANCE = new OFActionsVer13();




    public OFActionBsnChecksum.Builder buildBsnChecksum() {
        return new OFActionBsnChecksumVer13.Builder();
    }
    public OFActionBsnChecksum bsnChecksum(U128 checksum) {
        return new OFActionBsnChecksumVer13(
                checksum
                    );
    }

    public OFActionBsnMirror.Builder buildBsnMirror() {
        return new OFActionBsnMirrorVer13.Builder();
    }

    public OFActionBsnSetTunnelDst.Builder buildBsnSetTunnelDst() {
        return new OFActionBsnSetTunnelDstVer13.Builder();
    }
    public OFActionBsnSetTunnelDst bsnSetTunnelDst(long dst) {
        return new OFActionBsnSetTunnelDstVer13(
                dst
                    );
    }

    public OFActionEnqueue.Builder buildEnqueue() {
        throw new UnsupportedOperationException("OFActionEnqueue not supported in version 1.3");
    }
    public OFActionEnqueue enqueue(OFPort port, long queueId) {
        throw new UnsupportedOperationException("OFActionEnqueue not supported in version 1.3");
    }

    public OFActionNiciraDecTtl niciraDecTtl() {
        return OFActionNiciraDecTtlVer13.INSTANCE;
    }

    public OFActionNiciraExit niciraExit() {
        return OFActionNiciraExitVer13.INSTANCE;
    }

    public OFActionNiciraResubmit.Builder buildNiciraResubmit() {
        return new OFActionNiciraResubmitVer13.Builder();
    }
    public OFActionNiciraResubmit niciraResubmit(OFPort port) {
        return new OFActionNiciraResubmitVer13(
                port
                    );
    }

    public OFActionNiciraResubmitTable.Builder buildNiciraResubmitTable() {
        return new OFActionNiciraResubmitTableVer13.Builder();
    }
    public OFActionNiciraResubmitTable niciraResubmitTable(OFPort port, TableId tableId) {
        return new OFActionNiciraResubmitTableVer13(
                port,
                      tableId
                    );
    }

    public OFActionOutput.Builder buildOutput() {
        return new OFActionOutputVer13.Builder();
    }
    public OFActionOutput output(OFPort port, int maxLen) {
        return new OFActionOutputVer13(
                port,
                      maxLen
                    );
    }

    public OFActionSetDlDst.Builder buildSetDlDst() {
        throw new UnsupportedOperationException("OFActionSetDlDst not supported in version 1.3");
    }
    public OFActionSetDlDst setDlDst(MacAddress dlAddr) {
        throw new UnsupportedOperationException("OFActionSetDlDst not supported in version 1.3");
    }

    public OFActionSetDlSrc.Builder buildSetDlSrc() {
        throw new UnsupportedOperationException("OFActionSetDlSrc not supported in version 1.3");
    }
    public OFActionSetDlSrc setDlSrc(MacAddress dlAddr) {
        throw new UnsupportedOperationException("OFActionSetDlSrc not supported in version 1.3");
    }

    public OFActionSetNwDst.Builder buildSetNwDst() {
        throw new UnsupportedOperationException("OFActionSetNwDst not supported in version 1.3");
    }
    public OFActionSetNwDst setNwDst(IPv4Address nwAddr) {
        throw new UnsupportedOperationException("OFActionSetNwDst not supported in version 1.3");
    }

    public OFActionSetNwSrc.Builder buildSetNwSrc() {
        throw new UnsupportedOperationException("OFActionSetNwSrc not supported in version 1.3");
    }
    public OFActionSetNwSrc setNwSrc(IPv4Address nwAddr) {
        throw new UnsupportedOperationException("OFActionSetNwSrc not supported in version 1.3");
    }

    public OFActionSetNwTos.Builder buildSetNwTos() {
        throw new UnsupportedOperationException("OFActionSetNwTos not supported in version 1.3");
    }
    public OFActionSetNwTos setNwTos(short nwTos) {
        throw new UnsupportedOperationException("OFActionSetNwTos not supported in version 1.3");
    }

    public OFActionSetTpDst.Builder buildSetTpDst() {
        throw new UnsupportedOperationException("OFActionSetTpDst not supported in version 1.3");
    }
    public OFActionSetTpDst setTpDst(TransportPort tpPort) {
        throw new UnsupportedOperationException("OFActionSetTpDst not supported in version 1.3");
    }

    public OFActionSetTpSrc.Builder buildSetTpSrc() {
        throw new UnsupportedOperationException("OFActionSetTpSrc not supported in version 1.3");
    }
    public OFActionSetTpSrc setTpSrc(TransportPort tpPort) {
        throw new UnsupportedOperationException("OFActionSetTpSrc not supported in version 1.3");
    }

    public OFActionSetVlanPcp.Builder buildSetVlanPcp() {
        throw new UnsupportedOperationException("OFActionSetVlanPcp not supported in version 1.3");
    }
    public OFActionSetVlanPcp setVlanPcp(VlanPcp vlanPcp) {
        throw new UnsupportedOperationException("OFActionSetVlanPcp not supported in version 1.3");
    }

    public OFActionSetVlanVid.Builder buildSetVlanVid() {
        throw new UnsupportedOperationException("OFActionSetVlanVid not supported in version 1.3");
    }
    public OFActionSetVlanVid setVlanVid(VlanVid vlanVid) {
        throw new UnsupportedOperationException("OFActionSetVlanVid not supported in version 1.3");
    }

    public OFActionStripVlan stripVlan() {
        throw new UnsupportedOperationException("OFActionStripVlan not supported in version 1.3");
    }

    public OFActionCopyTtlIn copyTtlIn() {
        return OFActionCopyTtlInVer13.INSTANCE;
    }

    public OFActionCopyTtlOut copyTtlOut() {
        return OFActionCopyTtlOutVer13.INSTANCE;
    }

    public OFActionDecMplsTtl decMplsTtl() {
        return OFActionDecMplsTtlVer13.INSTANCE;
    }

    public OFActionDecNwTtl decNwTtl() {
        return OFActionDecNwTtlVer13.INSTANCE;
    }

    public OFActionGroup.Builder buildGroup() {
        return new OFActionGroupVer13.Builder();
    }
    public OFActionGroup group(OFGroup group) {
        return new OFActionGroupVer13(
                group
                    );
    }

    public OFActionPopMpls.Builder buildPopMpls() {
        return new OFActionPopMplsVer13.Builder();
    }
    public OFActionPopMpls popMpls(EthType ethertype) {
        return new OFActionPopMplsVer13(
                ethertype
                    );
    }

    public OFActionPopVlan popVlan() {
        return OFActionPopVlanVer13.INSTANCE;
    }

    public OFActionPushMpls.Builder buildPushMpls() {
        return new OFActionPushMplsVer13.Builder();
    }
    public OFActionPushMpls pushMpls(EthType ethertype) {
        return new OFActionPushMplsVer13(
                ethertype
                    );
    }

    public OFActionPushVlan.Builder buildPushVlan() {
        return new OFActionPushVlanVer13.Builder();
    }
    public OFActionPushVlan pushVlan(EthType ethertype) {
        return new OFActionPushVlanVer13(
                ethertype
                    );
    }

    public OFActionSetMplsLabel.Builder buildSetMplsLabel() {
        throw new UnsupportedOperationException("OFActionSetMplsLabel not supported in version 1.3");
    }
    public OFActionSetMplsLabel setMplsLabel(long mplsLabel) {
        throw new UnsupportedOperationException("OFActionSetMplsLabel not supported in version 1.3");
    }

    public OFActionSetMplsTc.Builder buildSetMplsTc() {
        throw new UnsupportedOperationException("OFActionSetMplsTc not supported in version 1.3");
    }
    public OFActionSetMplsTc setMplsTc(short mplsTc) {
        throw new UnsupportedOperationException("OFActionSetMplsTc not supported in version 1.3");
    }

    public OFActionSetMplsTtl.Builder buildSetMplsTtl() {
        return new OFActionSetMplsTtlVer13.Builder();
    }
    public OFActionSetMplsTtl setMplsTtl(short mplsTtl) {
        return new OFActionSetMplsTtlVer13(
                mplsTtl
                    );
    }

    public OFActionSetNwEcn.Builder buildSetNwEcn() {
        throw new UnsupportedOperationException("OFActionSetNwEcn not supported in version 1.3");
    }
    public OFActionSetNwEcn setNwEcn(IpEcn nwEcn) {
        throw new UnsupportedOperationException("OFActionSetNwEcn not supported in version 1.3");
    }

    public OFActionSetNwTtl.Builder buildSetNwTtl() {
        return new OFActionSetNwTtlVer13.Builder();
    }
    public OFActionSetNwTtl setNwTtl(short nwTtl) {
        return new OFActionSetNwTtlVer13(
                nwTtl
                    );
    }

    public OFActionSetQueue.Builder buildSetQueue() {
        return new OFActionSetQueueVer13.Builder();
    }
    public OFActionSetQueue setQueue(long queueId) {
        return new OFActionSetQueueVer13(
                queueId
                    );
    }

    public OFActionSetField.Builder buildSetField() {
        return new OFActionSetFieldVer13.Builder();
    }
    public OFActionSetField setField(OFOxm<?> field) {
        return new OFActionSetFieldVer13(
                field
                    );
    }

    public OFActionBsnGentable.Builder buildBsnGentable() {
        return new OFActionBsnGentableVer13.Builder();
    }
    public OFActionBsnGentable bsnGentable(long tableId, List<OFBsnTlv> key) {
        return new OFActionBsnGentableVer13(
                tableId,
                      key
                    );
    }

    public OFActionPopPbb popPbb() {
        return OFActionPopPbbVer13.INSTANCE;
    }

    public OFActionPushPbb.Builder buildPushPbb() {
        return new OFActionPushPbbVer13.Builder();
    }
    public OFActionPushPbb pushPbb(EthType ethertype) {
        return new OFActionPushPbbVer13(
                ethertype
                    );
    }

    public OFActionMeter.Builder buildMeter() {
        throw new UnsupportedOperationException("OFActionMeter not supported in version 1.3");
    }
    public OFActionMeter meter(long meterId) {
        throw new UnsupportedOperationException("OFActionMeter not supported in version 1.3");
    }

    public OFMessageReader<OFAction> getReader() {
        return OFActionVer13.READER;
    }


    public OFVersion getVersion() {
            return OFVersion.OF_13;
    }
}
