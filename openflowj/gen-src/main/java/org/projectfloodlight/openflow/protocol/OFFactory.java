// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_factory_interface.java
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
import java.util.Set;
import java.util.List;

public interface OFFactory extends XidGenerator {
    // Subfactories
    OFActions actions();
    OFInstructions instructions();
    OFMeterBands meterBands();
    OFOxms oxms();
    OFQueueProps queueProps();
    OFErrorMsgs errorMsgs();
    OFActionIds actionIds();
    OFInstructionIds instructionIds();
    OFBsnTlvs bsnTlvs();
    OFOxss oxss();

    OFAggregateStatsReply.Builder buildAggregateStatsReply();
    OFAggregateStatsRequest.Builder buildAggregateStatsRequest();
    OFBarrierReply.Builder buildBarrierReply();
    OFBarrierReply barrierReply();
    OFBarrierRequest.Builder buildBarrierRequest();
    OFBarrierRequest barrierRequest();
    OFBsnBwClearDataReply.Builder buildBsnBwClearDataReply();
    OFBsnBwClearDataReply bsnBwClearDataReply(long status);
    OFBsnBwClearDataRequest.Builder buildBsnBwClearDataRequest();
    OFBsnBwClearDataRequest bsnBwClearDataRequest();
    OFBsnBwEnableGetReply.Builder buildBsnBwEnableGetReply();
    OFBsnBwEnableGetReply bsnBwEnableGetReply(long enabled);
    OFBsnBwEnableGetRequest.Builder buildBsnBwEnableGetRequest();
    OFBsnBwEnableGetRequest bsnBwEnableGetRequest();
    OFBsnBwEnableSetReply.Builder buildBsnBwEnableSetReply();
    OFBsnBwEnableSetRequest.Builder buildBsnBwEnableSetRequest();
    OFBsnBwEnableSetRequest bsnBwEnableSetRequest(long enable);
    OFBsnGetInterfacesReply.Builder buildBsnGetInterfacesReply();
    OFBsnGetInterfacesReply bsnGetInterfacesReply(List<OFBsnInterface> interfaces);
    OFBsnGetInterfacesRequest.Builder buildBsnGetInterfacesRequest();
    OFBsnGetInterfacesRequest bsnGetInterfacesRequest();
    OFBsnGetIpMaskReply.Builder buildBsnGetIpMaskReply() throws UnsupportedOperationException;
    OFBsnGetIpMaskRequest.Builder buildBsnGetIpMaskRequest() throws UnsupportedOperationException;
    OFBsnGetIpMaskRequest bsnGetIpMaskRequest(short index);
    OFBsnGetL2TableReply.Builder buildBsnGetL2TableReply() throws UnsupportedOperationException;
    OFBsnGetL2TableRequest.Builder buildBsnGetL2TableRequest() throws UnsupportedOperationException;
    OFBsnGetL2TableRequest bsnGetL2TableRequest();
    OFBsnGetMirroringReply.Builder buildBsnGetMirroringReply();
    OFBsnGetMirroringReply bsnGetMirroringReply(short reportMirrorPorts);
    OFBsnGetMirroringRequest.Builder buildBsnGetMirroringRequest();
    OFBsnGetMirroringRequest bsnGetMirroringRequest(short reportMirrorPorts);
    OFBsnHybridGetReply.Builder buildBsnHybridGetReply() throws UnsupportedOperationException;
    OFBsnHybridGetRequest.Builder buildBsnHybridGetRequest() throws UnsupportedOperationException;
    OFBsnHybridGetRequest bsnHybridGetRequest();
    OFBsnInterface.Builder buildBsnInterface();
    OFBsnPduRxReply.Builder buildBsnPduRxReply();
    OFBsnPduRxRequest.Builder buildBsnPduRxRequest();
    OFBsnPduRxTimeout.Builder buildBsnPduRxTimeout();
    OFBsnPduTxReply.Builder buildBsnPduTxReply();
    OFBsnPduTxRequest.Builder buildBsnPduTxRequest();
    OFBsnSetIpMask.Builder buildBsnSetIpMask() throws UnsupportedOperationException;
    OFBsnSetL2TableReply.Builder buildBsnSetL2TableReply() throws UnsupportedOperationException;
    OFBsnSetL2TableRequest.Builder buildBsnSetL2TableRequest() throws UnsupportedOperationException;
    OFBsnSetMirroring.Builder buildBsnSetMirroring();
    OFBsnSetMirroring bsnSetMirroring(short reportMirrorPorts);
    OFBsnSetPktinSuppressionReply.Builder buildBsnSetPktinSuppressionReply();
    OFBsnSetPktinSuppressionReply bsnSetPktinSuppressionReply(long status);
    OFBsnSetPktinSuppressionRequest.Builder buildBsnSetPktinSuppressionRequest();
    OFBsnShellCommand.Builder buildBsnShellCommand() throws UnsupportedOperationException;
    OFBsnShellOutput.Builder buildBsnShellOutput() throws UnsupportedOperationException;
    OFBsnShellOutput bsnShellOutput(byte[] data);
    OFBsnShellStatus.Builder buildBsnShellStatus() throws UnsupportedOperationException;
    OFBsnShellStatus bsnShellStatus(long status);
    OFBsnVirtualPortCreateReply.Builder buildBsnVirtualPortCreateReply();
    OFBsnVirtualPortCreateRequest.Builder buildBsnVirtualPortCreateRequest();
    OFBsnVirtualPortCreateRequest bsnVirtualPortCreateRequest(OFBsnVport vport);
    OFBsnVirtualPortRemoveReply.Builder buildBsnVirtualPortRemoveReply();
    OFBsnVirtualPortRemoveReply bsnVirtualPortRemoveReply(long status);
    OFBsnVirtualPortRemoveRequest.Builder buildBsnVirtualPortRemoveRequest();
    OFBsnVirtualPortRemoveRequest bsnVirtualPortRemoveRequest(long vportNo);
    OFBsnVportL2Gre.Builder buildBsnVportL2Gre();
    OFBsnVportQInQ.Builder buildBsnVportQInQ();
    OFDescStatsReply.Builder buildDescStatsReply();
    OFDescStatsRequest.Builder buildDescStatsRequest();
    OFDescStatsRequest descStatsRequest(Set<OFStatsRequestFlags> flags);
    OFEchoReply.Builder buildEchoReply();
    OFEchoReply echoReply(byte[] data);
    OFEchoRequest.Builder buildEchoRequest();
    OFEchoRequest echoRequest(byte[] data);
    OFFeaturesReply.Builder buildFeaturesReply();
    OFFeaturesRequest.Builder buildFeaturesRequest();
    OFFeaturesRequest featuresRequest();
    OFFlowAdd.Builder buildFlowAdd();
    OFFlowDelete.Builder buildFlowDelete();
    OFFlowDeleteStrict.Builder buildFlowDeleteStrict();
    OFFlowModify.Builder buildFlowModify();
    OFFlowModifyStrict.Builder buildFlowModifyStrict();
    OFFlowRemoved.Builder buildFlowRemoved();
    OFFlowStatsEntry.Builder buildFlowStatsEntry();
    OFFlowStatsReply.Builder buildFlowStatsReply();
    OFFlowStatsRequest.Builder buildFlowStatsRequest();
    OFGetConfigReply.Builder buildGetConfigReply();
    OFGetConfigRequest.Builder buildGetConfigRequest();
    OFGetConfigRequest getConfigRequest();
    OFHello.Builder buildHello();
    OFHello hello(List<OFHelloElem> elements);
    OFMatchV1.Builder buildMatchV1() throws UnsupportedOperationException;
    OFNiciraControllerRoleReply.Builder buildNiciraControllerRoleReply() throws UnsupportedOperationException;
    OFNiciraControllerRoleReply niciraControllerRoleReply(OFNiciraControllerRole role);
    OFNiciraControllerRoleRequest.Builder buildNiciraControllerRoleRequest() throws UnsupportedOperationException;
    OFNiciraControllerRoleRequest niciraControllerRoleRequest(OFNiciraControllerRole role);
    OFPacketIn.Builder buildPacketIn();
    OFPacketOut.Builder buildPacketOut();
    OFPacketQueue.Builder buildPacketQueue();
    OFPortDesc.Builder buildPortDesc();
    OFPortMod.Builder buildPortMod();
    OFPortStatsEntry.Builder buildPortStatsEntry();
    OFPortStatsReply.Builder buildPortStatsReply();
    OFPortStatsRequest.Builder buildPortStatsRequest();
    OFPortStatus.Builder buildPortStatus();
    OFQueueGetConfigReply.Builder buildQueueGetConfigReply() throws UnsupportedOperationException;
    OFQueueGetConfigRequest.Builder buildQueueGetConfigRequest() throws UnsupportedOperationException;
    OFQueueGetConfigRequest queueGetConfigRequest(OFPort port);
    OFQueueStatsEntry.Builder buildQueueStatsEntry();
    OFQueueStatsReply.Builder buildQueueStatsReply();
    OFQueueStatsRequest.Builder buildQueueStatsRequest();
    OFSetConfig.Builder buildSetConfig();
    OFTableMod.Builder buildTableMod();
    OFTableStatsEntry.Builder buildTableStatsEntry();
    OFTableStatsReply.Builder buildTableStatsReply();
    OFTableStatsRequest.Builder buildTableStatsRequest();
    OFTableStatsRequest tableStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBucket.Builder buildBucket() throws UnsupportedOperationException;
    OFBucketCounter.Builder buildBucketCounter() throws UnsupportedOperationException;
    OFBucketCounter bucketCounter(U64 packetCount, U64 byteCount);
    OFGroupAdd.Builder buildGroupAdd() throws UnsupportedOperationException;
    OFGroupDelete.Builder buildGroupDelete() throws UnsupportedOperationException;
    OFGroupDescStatsEntry.Builder buildGroupDescStatsEntry() throws UnsupportedOperationException;
    OFGroupDescStatsReply.Builder buildGroupDescStatsReply() throws UnsupportedOperationException;
    OFGroupDescStatsRequest.Builder buildGroupDescStatsRequest() throws UnsupportedOperationException;
    OFGroupModify.Builder buildGroupModify() throws UnsupportedOperationException;
    OFGroupStatsEntry.Builder buildGroupStatsEntry() throws UnsupportedOperationException;
    OFGroupStatsReply.Builder buildGroupStatsReply() throws UnsupportedOperationException;
    OFGroupStatsRequest.Builder buildGroupStatsRequest() throws UnsupportedOperationException;
    OFMatchV2.Builder buildMatchV2() throws UnsupportedOperationException;
    OFGroupFeaturesStatsReply.Builder buildGroupFeaturesStatsReply() throws UnsupportedOperationException;
    OFGroupFeaturesStatsRequest.Builder buildGroupFeaturesStatsRequest() throws UnsupportedOperationException;
    OFGroupFeaturesStatsRequest groupFeaturesStatsRequest(Set<OFStatsRequestFlags> flags);
    OFMatchV3.Builder buildMatchV3() throws UnsupportedOperationException;
    OFMatchV3 matchV3(OFOxmList oxmList);
    OFRoleReply.Builder buildRoleReply() throws UnsupportedOperationException;
    OFRoleRequest.Builder buildRoleRequest() throws UnsupportedOperationException;
    OFAsyncGetReply.Builder buildAsyncGetReply() throws UnsupportedOperationException;
    OFAsyncGetRequest.Builder buildAsyncGetRequest() throws UnsupportedOperationException;
    OFAsyncSet.Builder buildAsyncSet() throws UnsupportedOperationException;
    OFBsnArpIdle.Builder buildBsnArpIdle() throws UnsupportedOperationException;
    OFBsnControllerConnection.Builder buildBsnControllerConnection() throws UnsupportedOperationException;
    OFBsnControllerConnectionsReply.Builder buildBsnControllerConnectionsReply() throws UnsupportedOperationException;
    OFBsnControllerConnectionsReply bsnControllerConnectionsReply(List<OFBsnControllerConnection> connections);
    OFBsnControllerConnectionsRequest.Builder buildBsnControllerConnectionsRequest() throws UnsupportedOperationException;
    OFBsnControllerConnectionsRequest bsnControllerConnectionsRequest();
    OFBsnDebugCounterDescStatsEntry.Builder buildBsnDebugCounterDescStatsEntry() throws UnsupportedOperationException;
    OFBsnDebugCounterDescStatsReply.Builder buildBsnDebugCounterDescStatsReply() throws UnsupportedOperationException;
    OFBsnDebugCounterDescStatsRequest.Builder buildBsnDebugCounterDescStatsRequest() throws UnsupportedOperationException;
    OFBsnDebugCounterDescStatsRequest bsnDebugCounterDescStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnDebugCounterStatsEntry.Builder buildBsnDebugCounterStatsEntry() throws UnsupportedOperationException;
    OFBsnDebugCounterStatsEntry bsnDebugCounterStatsEntry(U64 counterId, U64 value);
    OFBsnDebugCounterStatsReply.Builder buildBsnDebugCounterStatsReply() throws UnsupportedOperationException;
    OFBsnDebugCounterStatsRequest.Builder buildBsnDebugCounterStatsRequest() throws UnsupportedOperationException;
    OFBsnDebugCounterStatsRequest bsnDebugCounterStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnFlowChecksumBucketStatsEntry.Builder buildBsnFlowChecksumBucketStatsEntry() throws UnsupportedOperationException;
    OFBsnFlowChecksumBucketStatsEntry bsnFlowChecksumBucketStatsEntry(U64 checksum);
    OFBsnFlowChecksumBucketStatsReply.Builder buildBsnFlowChecksumBucketStatsReply() throws UnsupportedOperationException;
    OFBsnFlowChecksumBucketStatsRequest.Builder buildBsnFlowChecksumBucketStatsRequest() throws UnsupportedOperationException;
    OFBsnFlowIdle.Builder buildBsnFlowIdle() throws UnsupportedOperationException;
    OFBsnFlowIdleEnableGetReply.Builder buildBsnFlowIdleEnableGetReply() throws UnsupportedOperationException;
    OFBsnFlowIdleEnableGetReply bsnFlowIdleEnableGetReply(long enabled);
    OFBsnFlowIdleEnableGetRequest.Builder buildBsnFlowIdleEnableGetRequest() throws UnsupportedOperationException;
    OFBsnFlowIdleEnableGetRequest bsnFlowIdleEnableGetRequest();
    OFBsnFlowIdleEnableSetReply.Builder buildBsnFlowIdleEnableSetReply() throws UnsupportedOperationException;
    OFBsnFlowIdleEnableSetRequest.Builder buildBsnFlowIdleEnableSetRequest() throws UnsupportedOperationException;
    OFBsnFlowIdleEnableSetRequest bsnFlowIdleEnableSetRequest(long enable);
    OFBsnGenericStatsEntry.Builder buildBsnGenericStatsEntry() throws UnsupportedOperationException;
    OFBsnGenericStatsEntry bsnGenericStatsEntry(List<OFBsnTlv> tlvs);
    OFBsnGenericStatsReply.Builder buildBsnGenericStatsReply() throws UnsupportedOperationException;
    OFBsnGenericStatsRequest.Builder buildBsnGenericStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableBucketStatsEntry.Builder buildBsnGentableBucketStatsEntry() throws UnsupportedOperationException;
    OFBsnGentableBucketStatsEntry bsnGentableBucketStatsEntry(U128 checksum);
    OFBsnGentableBucketStatsReply.Builder buildBsnGentableBucketStatsReply() throws UnsupportedOperationException;
    OFBsnGentableBucketStatsRequest.Builder buildBsnGentableBucketStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableClearReply.Builder buildBsnGentableClearReply() throws UnsupportedOperationException;
    OFBsnGentableClearRequest.Builder buildBsnGentableClearRequest() throws UnsupportedOperationException;
    OFBsnGentableDescStatsEntry.Builder buildBsnGentableDescStatsEntry() throws UnsupportedOperationException;
    OFBsnGentableDescStatsReply.Builder buildBsnGentableDescStatsReply() throws UnsupportedOperationException;
    OFBsnGentableDescStatsRequest.Builder buildBsnGentableDescStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableDescStatsRequest bsnGentableDescStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnGentableEntryAdd.Builder buildBsnGentableEntryAdd() throws UnsupportedOperationException;
    OFBsnGentableEntryDelete.Builder buildBsnGentableEntryDelete() throws UnsupportedOperationException;
    OFBsnGentableEntryDescStatsEntry.Builder buildBsnGentableEntryDescStatsEntry() throws UnsupportedOperationException;
    OFBsnGentableEntryDescStatsReply.Builder buildBsnGentableEntryDescStatsReply() throws UnsupportedOperationException;
    OFBsnGentableEntryDescStatsRequest.Builder buildBsnGentableEntryDescStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableEntryStatsEntry.Builder buildBsnGentableEntryStatsEntry() throws UnsupportedOperationException;
    OFBsnGentableEntryStatsEntry bsnGentableEntryStatsEntry(List<OFBsnTlv> key, List<OFBsnTlv> stats);
    OFBsnGentableEntryStatsReply.Builder buildBsnGentableEntryStatsReply() throws UnsupportedOperationException;
    OFBsnGentableEntryStatsRequest.Builder buildBsnGentableEntryStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableSetBucketsSize.Builder buildBsnGentableSetBucketsSize() throws UnsupportedOperationException;
    OFBsnGentableStatsEntry.Builder buildBsnGentableStatsEntry() throws UnsupportedOperationException;
    OFBsnGentableStatsReply.Builder buildBsnGentableStatsReply() throws UnsupportedOperationException;
    OFBsnGentableStatsRequest.Builder buildBsnGentableStatsRequest() throws UnsupportedOperationException;
    OFBsnGentableStatsRequest bsnGentableStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnGetSwitchPipelineReply.Builder buildBsnGetSwitchPipelineReply() throws UnsupportedOperationException;
    OFBsnGetSwitchPipelineReply bsnGetSwitchPipelineReply(String pipeline);
    OFBsnGetSwitchPipelineRequest.Builder buildBsnGetSwitchPipelineRequest() throws UnsupportedOperationException;
    OFBsnGetSwitchPipelineRequest bsnGetSwitchPipelineRequest();
    OFBsnImageDescStatsReply.Builder buildBsnImageDescStatsReply() throws UnsupportedOperationException;
    OFBsnImageDescStatsRequest.Builder buildBsnImageDescStatsRequest() throws UnsupportedOperationException;
    OFBsnImageDescStatsRequest bsnImageDescStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnLacpConvergenceNotif.Builder buildBsnLacpConvergenceNotif() throws UnsupportedOperationException;
    OFBsnLacpStatsEntry.Builder buildBsnLacpStatsEntry() throws UnsupportedOperationException;
    OFBsnLacpStatsReply.Builder buildBsnLacpStatsReply() throws UnsupportedOperationException;
    OFBsnLacpStatsRequest.Builder buildBsnLacpStatsRequest() throws UnsupportedOperationException;
    OFBsnLacpStatsRequest bsnLacpStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnLog.Builder buildBsnLog() throws UnsupportedOperationException;
    OFBsnLuaCommandReply.Builder buildBsnLuaCommandReply() throws UnsupportedOperationException;
    OFBsnLuaCommandReply bsnLuaCommandReply(byte[] data);
    OFBsnLuaCommandRequest.Builder buildBsnLuaCommandRequest() throws UnsupportedOperationException;
    OFBsnLuaCommandRequest bsnLuaCommandRequest(byte[] data);
    OFBsnLuaNotification.Builder buildBsnLuaNotification() throws UnsupportedOperationException;
    OFBsnLuaNotification bsnLuaNotification(byte[] data);
    OFBsnLuaUpload.Builder buildBsnLuaUpload() throws UnsupportedOperationException;
    OFBsnPortCounterStatsEntry.Builder buildBsnPortCounterStatsEntry() throws UnsupportedOperationException;
    OFBsnPortCounterStatsEntry bsnPortCounterStatsEntry(OFPort portNo, List<U64> values);
    OFBsnPortCounterStatsReply.Builder buildBsnPortCounterStatsReply() throws UnsupportedOperationException;
    OFBsnPortCounterStatsRequest.Builder buildBsnPortCounterStatsRequest() throws UnsupportedOperationException;
    OFBsnRoleStatus.Builder buildBsnRoleStatus() throws UnsupportedOperationException;
    OFBsnSetAuxCxnsReply.Builder buildBsnSetAuxCxnsReply() throws UnsupportedOperationException;
    OFBsnSetAuxCxnsRequest.Builder buildBsnSetAuxCxnsRequest() throws UnsupportedOperationException;
    OFBsnSetAuxCxnsRequest bsnSetAuxCxnsRequest(long numAux);
    OFBsnSetLacpReply.Builder buildBsnSetLacpReply() throws UnsupportedOperationException;
    OFBsnSetLacpRequest.Builder buildBsnSetLacpRequest() throws UnsupportedOperationException;
    OFBsnSetSwitchPipelineReply.Builder buildBsnSetSwitchPipelineReply() throws UnsupportedOperationException;
    OFBsnSetSwitchPipelineReply bsnSetSwitchPipelineReply(long status);
    OFBsnSetSwitchPipelineRequest.Builder buildBsnSetSwitchPipelineRequest() throws UnsupportedOperationException;
    OFBsnSetSwitchPipelineRequest bsnSetSwitchPipelineRequest(String pipeline);
    OFBsnSwitchPipelineStatsEntry.Builder buildBsnSwitchPipelineStatsEntry() throws UnsupportedOperationException;
    OFBsnSwitchPipelineStatsEntry bsnSwitchPipelineStatsEntry(String pipeline);
    OFBsnSwitchPipelineStatsReply.Builder buildBsnSwitchPipelineStatsReply() throws UnsupportedOperationException;
    OFBsnSwitchPipelineStatsRequest.Builder buildBsnSwitchPipelineStatsRequest() throws UnsupportedOperationException;
    OFBsnSwitchPipelineStatsRequest bsnSwitchPipelineStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnTableChecksumStatsEntry.Builder buildBsnTableChecksumStatsEntry() throws UnsupportedOperationException;
    OFBsnTableChecksumStatsEntry bsnTableChecksumStatsEntry(TableId tableId, U64 checksum);
    OFBsnTableChecksumStatsReply.Builder buildBsnTableChecksumStatsReply() throws UnsupportedOperationException;
    OFBsnTableChecksumStatsRequest.Builder buildBsnTableChecksumStatsRequest() throws UnsupportedOperationException;
    OFBsnTableChecksumStatsRequest bsnTableChecksumStatsRequest(Set<OFStatsRequestFlags> flags);
    OFBsnTableSetBucketsSize.Builder buildBsnTableSetBucketsSize() throws UnsupportedOperationException;
    OFBsnTimeReply.Builder buildBsnTimeReply() throws UnsupportedOperationException;
    OFBsnTimeReply bsnTimeReply(U64 timeMs);
    OFBsnTimeRequest.Builder buildBsnTimeRequest() throws UnsupportedOperationException;
    OFBsnTimeRequest bsnTimeRequest();
    OFBsnVlanCounterClear.Builder buildBsnVlanCounterClear() throws UnsupportedOperationException;
    OFBsnVlanCounterClear bsnVlanCounterClear(int vlanVid);
    OFBsnVlanCounterStatsEntry.Builder buildBsnVlanCounterStatsEntry() throws UnsupportedOperationException;
    OFBsnVlanCounterStatsEntry bsnVlanCounterStatsEntry(int vlanVid, List<U64> values);
    OFBsnVlanCounterStatsReply.Builder buildBsnVlanCounterStatsReply() throws UnsupportedOperationException;
    OFBsnVlanCounterStatsRequest.Builder buildBsnVlanCounterStatsRequest() throws UnsupportedOperationException;
    OFBsnVlanMac.Builder buildBsnVlanMac() throws UnsupportedOperationException;
    OFBsnVlanMac bsnVlanMac(int vlanVid, MacAddress mac);
    OFBsnVrfCounterStatsEntry.Builder buildBsnVrfCounterStatsEntry() throws UnsupportedOperationException;
    OFBsnVrfCounterStatsEntry bsnVrfCounterStatsEntry(long vrf, List<U64> values);
    OFBsnVrfCounterStatsReply.Builder buildBsnVrfCounterStatsReply() throws UnsupportedOperationException;
    OFBsnVrfCounterStatsRequest.Builder buildBsnVrfCounterStatsRequest() throws UnsupportedOperationException;
    OFHelloElemVersionbitmap.Builder buildHelloElemVersionbitmap() throws UnsupportedOperationException;
    OFHelloElemVersionbitmap helloElemVersionbitmap(List<U32> bitmaps);
    OFMeterBandStats.Builder buildMeterBandStats() throws UnsupportedOperationException;
    OFMeterBandStats meterBandStats(U64 packetBandCount, U64 byteBandCount);
    OFMeterConfig.Builder buildMeterConfig() throws UnsupportedOperationException;
    OFMeterConfigStatsReply.Builder buildMeterConfigStatsReply() throws UnsupportedOperationException;
    OFMeterConfigStatsRequest.Builder buildMeterConfigStatsRequest() throws UnsupportedOperationException;
    OFMeterFeatures.Builder buildMeterFeatures() throws UnsupportedOperationException;
    OFMeterFeaturesStatsReply.Builder buildMeterFeaturesStatsReply() throws UnsupportedOperationException;
    OFMeterFeaturesStatsRequest.Builder buildMeterFeaturesStatsRequest() throws UnsupportedOperationException;
    OFMeterFeaturesStatsRequest meterFeaturesStatsRequest(Set<OFStatsRequestFlags> flags);
    OFMeterMod.Builder buildMeterMod() throws UnsupportedOperationException;
    OFMeterStats.Builder buildMeterStats() throws UnsupportedOperationException;
    OFMeterStatsReply.Builder buildMeterStatsReply() throws UnsupportedOperationException;
    OFMeterStatsRequest.Builder buildMeterStatsRequest() throws UnsupportedOperationException;
    OFPortDescStatsReply.Builder buildPortDescStatsReply() throws UnsupportedOperationException;
    OFPortDescStatsRequest.Builder buildPortDescStatsRequest() throws UnsupportedOperationException;
    OFTableFeaturePropApplyActions.Builder buildTableFeaturePropApplyActions() throws UnsupportedOperationException;
    OFTableFeaturePropApplyActions tableFeaturePropApplyActions(List<OFActionId> actionIds);
    OFTableFeaturePropApplyActionsMiss.Builder buildTableFeaturePropApplyActionsMiss() throws UnsupportedOperationException;
    OFTableFeaturePropApplyActionsMiss tableFeaturePropApplyActionsMiss(List<OFActionId> actionIds);
    OFTableFeaturePropApplySetfield.Builder buildTableFeaturePropApplySetfield() throws UnsupportedOperationException;
    OFTableFeaturePropApplySetfield tableFeaturePropApplySetfield(List<U32> oxmIds);
    OFTableFeaturePropApplySetfieldMiss.Builder buildTableFeaturePropApplySetfieldMiss() throws UnsupportedOperationException;
    OFTableFeaturePropApplySetfieldMiss tableFeaturePropApplySetfieldMiss(List<U32> oxmIds);
    OFTableFeaturePropInstructions.Builder buildTableFeaturePropInstructions() throws UnsupportedOperationException;
    OFTableFeaturePropInstructions tableFeaturePropInstructions(List<OFInstructionId> instructionIds);
    OFTableFeaturePropInstructionsMiss.Builder buildTableFeaturePropInstructionsMiss() throws UnsupportedOperationException;
    OFTableFeaturePropInstructionsMiss tableFeaturePropInstructionsMiss(List<OFInstructionId> instructionIds);
    OFTableFeaturePropMatch.Builder buildTableFeaturePropMatch() throws UnsupportedOperationException;
    OFTableFeaturePropMatch tableFeaturePropMatch(List<U32> oxmIds);
    OFTableFeaturePropNextTables.Builder buildTableFeaturePropNextTables() throws UnsupportedOperationException;
    OFTableFeaturePropNextTables tableFeaturePropNextTables(List<U8> nextTableIds);
    OFTableFeaturePropNextTablesMiss.Builder buildTableFeaturePropNextTablesMiss() throws UnsupportedOperationException;
    OFTableFeaturePropNextTablesMiss tableFeaturePropNextTablesMiss(List<U8> nextTableIds);
    OFTableFeaturePropWildcards.Builder buildTableFeaturePropWildcards() throws UnsupportedOperationException;
    OFTableFeaturePropWildcards tableFeaturePropWildcards(List<U32> oxmIds);
    OFTableFeaturePropWriteActions.Builder buildTableFeaturePropWriteActions() throws UnsupportedOperationException;
    OFTableFeaturePropWriteActions tableFeaturePropWriteActions(List<OFActionId> actionIds);
    OFTableFeaturePropWriteActionsMiss.Builder buildTableFeaturePropWriteActionsMiss() throws UnsupportedOperationException;
    OFTableFeaturePropWriteActionsMiss tableFeaturePropWriteActionsMiss(List<OFActionId> actionIds);
    OFTableFeaturePropWriteSetfield.Builder buildTableFeaturePropWriteSetfield() throws UnsupportedOperationException;
    OFTableFeaturePropWriteSetfield tableFeaturePropWriteSetfield(List<U32> oxmIds);
    OFTableFeaturePropWriteSetfieldMiss.Builder buildTableFeaturePropWriteSetfieldMiss() throws UnsupportedOperationException;
    OFTableFeaturePropWriteSetfieldMiss tableFeaturePropWriteSetfieldMiss(List<U32> oxmIds);
    OFTableFeatures.Builder buildTableFeatures() throws UnsupportedOperationException;
    OFTableFeaturesStatsReply.Builder buildTableFeaturesStatsReply() throws UnsupportedOperationException;
    OFTableFeaturesStatsRequest.Builder buildTableFeaturesStatsRequest() throws UnsupportedOperationException;
    OFUint64.Builder buildUint64() throws UnsupportedOperationException;
    OFUint64 uint64(U64 value);
    OFAsyncConfigPropExperimenterMaster asyncConfigPropExperimenterMaster();
    OFAsyncConfigPropExperimenterSlave asyncConfigPropExperimenterSlave();
    OFAsyncConfigPropFlowRemovedMaster.Builder buildAsyncConfigPropFlowRemovedMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropFlowRemovedMaster asyncConfigPropFlowRemovedMaster(long mask);
    OFAsyncConfigPropFlowRemovedSlave.Builder buildAsyncConfigPropFlowRemovedSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropFlowRemovedSlave asyncConfigPropFlowRemovedSlave(long mask);
    OFAsyncConfigPropPacketInMaster.Builder buildAsyncConfigPropPacketInMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropPacketInMaster asyncConfigPropPacketInMaster(long mask);
    OFAsyncConfigPropPacketInSlave.Builder buildAsyncConfigPropPacketInSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropPacketInSlave asyncConfigPropPacketInSlave(long mask);
    OFAsyncConfigPropPortStatusMaster.Builder buildAsyncConfigPropPortStatusMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropPortStatusMaster asyncConfigPropPortStatusMaster(long mask);
    OFAsyncConfigPropPortStatusSlave.Builder buildAsyncConfigPropPortStatusSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropPortStatusSlave asyncConfigPropPortStatusSlave(long mask);
    OFAsyncConfigPropRequestforwardMaster.Builder buildAsyncConfigPropRequestforwardMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropRequestforwardMaster asyncConfigPropRequestforwardMaster(long mask);
    OFAsyncConfigPropRequestforwardSlave.Builder buildAsyncConfigPropRequestforwardSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropRequestforwardSlave asyncConfigPropRequestforwardSlave(long mask);
    OFAsyncConfigPropRoleStatusMaster.Builder buildAsyncConfigPropRoleStatusMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropRoleStatusMaster asyncConfigPropRoleStatusMaster(long mask);
    OFAsyncConfigPropRoleStatusSlave.Builder buildAsyncConfigPropRoleStatusSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropRoleStatusSlave asyncConfigPropRoleStatusSlave(long mask);
    OFAsyncConfigPropTableStatusMaster.Builder buildAsyncConfigPropTableStatusMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropTableStatusMaster asyncConfigPropTableStatusMaster(long mask);
    OFAsyncConfigPropTableStatusSlave.Builder buildAsyncConfigPropTableStatusSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropTableStatusSlave asyncConfigPropTableStatusSlave(long mask);
    OFBsnGenericAsync.Builder buildBsnGenericAsync() throws UnsupportedOperationException;
    OFBsnGenericCommand.Builder buildBsnGenericCommand() throws UnsupportedOperationException;
    OFBsnTakeover.Builder buildBsnTakeover() throws UnsupportedOperationException;
    OFBsnTakeover bsnTakeover();
    OFBundleAddMsg.Builder buildBundleAddMsg() throws UnsupportedOperationException;
    OFBundleCtrlMsg.Builder buildBundleCtrlMsg() throws UnsupportedOperationException;
    OFPortDescPropBsnForwardErrorCorrection.Builder buildPortDescPropBsnForwardErrorCorrection() throws UnsupportedOperationException;
    OFPortDescPropBsnForwardErrorCorrection portDescPropBsnForwardErrorCorrection(long configured, long enabled);
    OFPortDescPropBsnGenerationId.Builder buildPortDescPropBsnGenerationId() throws UnsupportedOperationException;
    OFPortDescPropBsnGenerationId portDescPropBsnGenerationId(U64 generationId);
    OFPortDescPropBsnUplink portDescPropBsnUplink();
    OFPortDescPropEthernet.Builder buildPortDescPropEthernet() throws UnsupportedOperationException;
    OFPortDescPropOptical.Builder buildPortDescPropOptical() throws UnsupportedOperationException;
    OFPortModPropEthernet.Builder buildPortModPropEthernet() throws UnsupportedOperationException;
    OFPortModPropEthernet portModPropEthernet(Set<OFPortFeatures> advertise);
    OFPortModPropOptical.Builder buildPortModPropOptical() throws UnsupportedOperationException;
    OFPortStatsPropEthernet.Builder buildPortStatsPropEthernet() throws UnsupportedOperationException;
    OFPortStatsPropExperimenterIntel.Builder buildPortStatsPropExperimenterIntel() throws UnsupportedOperationException;
    OFPortStatsPropOptical.Builder buildPortStatsPropOptical() throws UnsupportedOperationException;
    OFQueueDesc.Builder buildQueueDesc() throws UnsupportedOperationException;
    OFQueueDescPropBsnQueueName.Builder buildQueueDescPropBsnQueueName() throws UnsupportedOperationException;
    OFQueueDescPropBsnQueueName queueDescPropBsnQueueName(byte[] name);
    OFQueueDescPropMaxRate.Builder buildQueueDescPropMaxRate() throws UnsupportedOperationException;
    OFQueueDescPropMaxRate queueDescPropMaxRate(int rate);
    OFQueueDescPropMinRate.Builder buildQueueDescPropMinRate() throws UnsupportedOperationException;
    OFQueueDescPropMinRate queueDescPropMinRate(int rate);
    OFQueueDescStatsReply.Builder buildQueueDescStatsReply() throws UnsupportedOperationException;
    OFQueueDescStatsRequest.Builder buildQueueDescStatsRequest() throws UnsupportedOperationException;
    OFRequestforward.Builder buildRequestforward() throws UnsupportedOperationException;
    OFRoleStatus.Builder buildRoleStatus() throws UnsupportedOperationException;
    OFTableDesc.Builder buildTableDesc() throws UnsupportedOperationException;
    OFTableDescStatsReply.Builder buildTableDescStatsReply() throws UnsupportedOperationException;
    OFTableDescStatsRequest.Builder buildTableDescStatsRequest() throws UnsupportedOperationException;
    OFTableDescStatsRequest tableDescStatsRequest(Set<OFStatsRequestFlags> flags);
    OFTableFeaturePropTableSyncFrom.Builder buildTableFeaturePropTableSyncFrom() throws UnsupportedOperationException;
    OFTableFeaturePropTableSyncFrom tableFeaturePropTableSyncFrom(List<U8> tableIds);
    OFTableModPropEviction.Builder buildTableModPropEviction() throws UnsupportedOperationException;
    OFTableModPropEviction tableModPropEviction(Set<OFTableModPropEvictionFlag> flags);
    OFTableModPropVacancy.Builder buildTableModPropVacancy() throws UnsupportedOperationException;
    OFTableStatus.Builder buildTableStatus() throws UnsupportedOperationException;
    OFAsyncConfigPropContStatusMaster.Builder buildAsyncConfigPropContStatusMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropContStatusMaster asyncConfigPropContStatusMaster(long mask);
    OFAsyncConfigPropContStatusSlave.Builder buildAsyncConfigPropContStatusSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropContStatusSlave asyncConfigPropContStatusSlave(long mask);
    OFAsyncConfigPropFlowStatsMaster.Builder buildAsyncConfigPropFlowStatsMaster() throws UnsupportedOperationException;
    OFAsyncConfigPropFlowStatsMaster asyncConfigPropFlowStatsMaster(long mask);
    OFAsyncConfigPropFlowStatsSlave.Builder buildAsyncConfigPropFlowStatsSlave() throws UnsupportedOperationException;
    OFAsyncConfigPropFlowStatsSlave asyncConfigPropFlowStatsSlave(long mask);
    OFTime.Builder buildTime() throws UnsupportedOperationException;
    OFTime time(U64 seconds, long nanoseconds);
    OFBundleFeaturesPropTime.Builder buildBundleFeaturesPropTime() throws UnsupportedOperationException;
    OFBundleFeaturesStatsReply.Builder buildBundleFeaturesStatsReply() throws UnsupportedOperationException;
    OFBundleFeaturesStatsRequest.Builder buildBundleFeaturesStatsRequest() throws UnsupportedOperationException;
    OFBundlePropTime.Builder buildBundlePropTime() throws UnsupportedOperationException;
    OFBundlePropTime bundlePropTime(List<OFTime> scheduledTime);
    OFControllerStatusEntry.Builder buildControllerStatusEntry() throws UnsupportedOperationException;
    OFControllerStatus.Builder buildControllerStatus() throws UnsupportedOperationException;
    OFControllerStatus controllerStatus(OFControllerStatusEntry entry);
    OFControllerStatusStatsReply.Builder buildControllerStatusStatsReply() throws UnsupportedOperationException;
    OFControllerStatusStatsRequest.Builder buildControllerStatusStatsRequest() throws UnsupportedOperationException;
    OFControllerStatusStatsRequest controllerStatusStatsRequest(Set<OFStatsRequestFlags> flags);
    OFFlowLightweightStatsEntry.Builder buildFlowLightweightStatsEntry() throws UnsupportedOperationException;
    OFFlowLightweightStatsReply.Builder buildFlowLightweightStatsReply() throws UnsupportedOperationException;
    OFFlowLightweightStatsRequest.Builder buildFlowLightweightStatsRequest() throws UnsupportedOperationException;
    OFFlowMonitorEntry.Builder buildFlowMonitorEntry() throws UnsupportedOperationException;
    OFFlowMonitorReply.Builder buildFlowMonitorReply() throws UnsupportedOperationException;
    OFFlowMonitorReplyEntry.Builder buildFlowMonitorReplyEntry() throws UnsupportedOperationException;
    OFFlowMonitorReplyEntry flowMonitorReplyEntry(OFFlowUpdateEvent event);
    OFFlowMonitorRequest.Builder buildFlowMonitorRequest() throws UnsupportedOperationException;
    OFGroupBucketPropWatchGroup.Builder buildGroupBucketPropWatchGroup() throws UnsupportedOperationException;
    OFGroupBucketPropWatchGroup groupBucketPropWatchGroup(long watch);
    OFGroupBucketPropWatchPort.Builder buildGroupBucketPropWatchPort() throws UnsupportedOperationException;
    OFGroupBucketPropWatchPort groupBucketPropWatchPort(long watch);
    OFGroupBucketPropWeight.Builder buildGroupBucketPropWeight() throws UnsupportedOperationException;
    OFGroupBucketPropWeight groupBucketPropWeight(int weight);
    OFGroupInsertBucket.Builder buildGroupInsertBucket() throws UnsupportedOperationException;
    OFGroupRemoveBucket.Builder buildGroupRemoveBucket() throws UnsupportedOperationException;
    OFPortDescPropEgress.Builder buildPortDescPropEgress() throws UnsupportedOperationException;
    OFPortDescPropEgress portDescPropEgress(byte[] oxmIds);
    OFPortDescPropIngress.Builder buildPortDescPropIngress() throws UnsupportedOperationException;
    OFPortDescPropIngress portDescPropIngress(byte[] oxmIds);
    OFQueueStatsPropBsn.Builder buildQueueStatsPropBsn() throws UnsupportedOperationException;
    OFQueueStatsPropBsn queueStatsPropBsn(byte[] experimenterData);
    OFRolePropBsn.Builder buildRolePropBsn() throws UnsupportedOperationException;
    OFRolePropBsn rolePropBsn(byte[] experimenterData);
    OFStatV6.Builder buildStatV6() throws UnsupportedOperationException;
    OFStatV6 statV6(OFOxsList oxsFields);
    OFTableFeaturePropApplyCopyfield.Builder buildTableFeaturePropApplyCopyfield() throws UnsupportedOperationException;
    OFTableFeaturePropApplyCopyfield tableFeaturePropApplyCopyfield(List<U32> oxmIds);
    OFTableFeaturePropApplyCopyfieldMiss.Builder buildTableFeaturePropApplyCopyfieldMiss() throws UnsupportedOperationException;
    OFTableFeaturePropApplyCopyfieldMiss tableFeaturePropApplyCopyfieldMiss(List<U32> oxmIds);
    OFTableFeaturePropOxmValues.Builder buildTableFeaturePropOxmValues() throws UnsupportedOperationException;
    OFTableFeaturePropOxmValues tableFeaturePropOxmValues(byte[] oxmValues);
    OFTableFeaturePropWriteCopyfield.Builder buildTableFeaturePropWriteCopyfield() throws UnsupportedOperationException;
    OFTableFeaturePropWriteCopyfield tableFeaturePropWriteCopyfield(List<U32> oxmIds);
    OFTableFeaturePropWriteCopyfieldMiss.Builder buildTableFeaturePropWriteCopyfieldMiss() throws UnsupportedOperationException;
    OFTableFeaturePropWriteCopyfieldMiss tableFeaturePropWriteCopyfieldMiss(List<U32> oxmIds);
    OFActionCopyField.Builder buildActionCopyField() throws UnsupportedOperationException;
    OFControllerStatusPropUri.Builder buildControllerStatusPropUri() throws UnsupportedOperationException;
    OFControllerStatusPropUri controllerStatusPropUri(OFConnectionIndex uri);
    OFPortDescPropRecirculate.Builder buildPortDescPropRecirculate() throws UnsupportedOperationException;
    OFPortDescPropRecirculate portDescPropRecirculate(byte[] portNos);
    Match.Builder buildMatch();
    Match matchWildcardAll();
    Stat.Builder buildStat();

    OFMessageReader<OFMessage> getReader();
    OFVersion getVersion();
}
