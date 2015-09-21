// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_virtual_class.java
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
import io.netty.buffer.ByteBuf;

abstract class OFOxmVer14 {
    // version: 1.4
    final static byte WIRE_VERSION = 5;
    final static int MINIMUM_LENGTH = 4;


    public final static OFOxmVer14.Reader READER = new Reader();

    static class Reader implements OFMessageReader<OFOxm<?>> {
        @Override
        public OFOxm<?> readFrom(ByteBuf bb) throws OFParseError {
            if(bb.readableBytes() < MINIMUM_LENGTH)
                return null;
            int start = bb.readerIndex();
            int typeLen = bb.readInt();
            bb.readerIndex(start);
            switch(typeLen) {
               case (int) 0x80002a02:
                   // discriminator value 0x80002a02L=0x80002a02L for class OFOxmArpOpVer14
                   return OFOxmArpOpVer14.READER.readFrom(bb);
               case (int) 0x80002b04:
                   // discriminator value 0x80002b04L=0x80002b04L for class OFOxmArpOpMaskedVer14
                   return OFOxmArpOpMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003006:
                   // discriminator value 0x80003006L=0x80003006L for class OFOxmArpShaVer14
                   return OFOxmArpShaVer14.READER.readFrom(bb);
               case (int) 0x8000310c:
                   // discriminator value 0x8000310cL=0x8000310cL for class OFOxmArpShaMaskedVer14
                   return OFOxmArpShaMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002c04:
                   // discriminator value 0x80002c04L=0x80002c04L for class OFOxmArpSpaVer14
                   return OFOxmArpSpaVer14.READER.readFrom(bb);
               case (int) 0x80002d08:
                   // discriminator value 0x80002d08L=0x80002d08L for class OFOxmArpSpaMaskedVer14
                   return OFOxmArpSpaMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003206:
                   // discriminator value 0x80003206L=0x80003206L for class OFOxmArpThaVer14
                   return OFOxmArpThaVer14.READER.readFrom(bb);
               case (int) 0x8000330c:
                   // discriminator value 0x8000330cL=0x8000330cL for class OFOxmArpThaMaskedVer14
                   return OFOxmArpThaMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002e04:
                   // discriminator value 0x80002e04L=0x80002e04L for class OFOxmArpTpaVer14
                   return OFOxmArpTpaVer14.READER.readFrom(bb);
               case (int) 0x80002f08:
                   // discriminator value 0x80002f08L=0x80002f08L for class OFOxmArpTpaMaskedVer14
                   return OFOxmArpTpaMaskedVer14.READER.readFrom(bb);
               case 0x30e04:
                   // discriminator value 0x30e04L=0x30e04L for class OFOxmBsnEgrPortGroupIdVer14
                   return OFOxmBsnEgrPortGroupIdVer14.READER.readFrom(bb);
               case 0x30f08:
                   // discriminator value 0x30f08L=0x30f08L for class OFOxmBsnEgrPortGroupIdMaskedVer14
                   return OFOxmBsnEgrPortGroupIdMaskedVer14.READER.readFrom(bb);
               case 0x30010:
                   // discriminator value 0x30010L=0x30010L for class OFOxmBsnInPorts128Ver14
                   return OFOxmBsnInPorts128Ver14.READER.readFrom(bb);
               case 0x30120:
                   // discriminator value 0x30120L=0x30120L for class OFOxmBsnInPorts128MaskedVer14
                   return OFOxmBsnInPorts128MaskedVer14.READER.readFrom(bb);
               case 0x32640:
                   // discriminator value 0x32640L=0x32640L for class OFOxmBsnInPorts512Ver14
                   return OFOxmBsnInPorts512Ver14.READER.readFrom(bb);
               case 0x32780:
                   // discriminator value 0x32780L=0x32780L for class OFOxmBsnInPorts512MaskedVer14
                   return OFOxmBsnInPorts512MaskedVer14.READER.readFrom(bb);
               case 0x32804:
                   // discriminator value 0x32804L=0x32804L for class OFOxmBsnIngressPortGroupIdVer14
                   return OFOxmBsnIngressPortGroupIdVer14.READER.readFrom(bb);
               case 0x32908:
                   // discriminator value 0x32908L=0x32908L for class OFOxmBsnIngressPortGroupIdMaskedVer14
                   return OFOxmBsnIngressPortGroupIdMaskedVer14.READER.readFrom(bb);
               case 0x30804:
                   // discriminator value 0x30804L=0x30804L for class OFOxmBsnL3InterfaceClassIdVer14
                   return OFOxmBsnL3InterfaceClassIdVer14.READER.readFrom(bb);
               case 0x30908:
                   // discriminator value 0x30908L=0x30908L for class OFOxmBsnL3InterfaceClassIdMaskedVer14
                   return OFOxmBsnL3InterfaceClassIdMaskedVer14.READER.readFrom(bb);
               case 0x30a04:
                   // discriminator value 0x30a04L=0x30a04L for class OFOxmBsnL3SrcClassIdVer14
                   return OFOxmBsnL3SrcClassIdVer14.READER.readFrom(bb);
               case 0x30b08:
                   // discriminator value 0x30b08L=0x30b08L for class OFOxmBsnL3SrcClassIdMaskedVer14
                   return OFOxmBsnL3SrcClassIdMaskedVer14.READER.readFrom(bb);
               case 0x30204:
                   // discriminator value 0x30204L=0x30204L for class OFOxmBsnLagIdVer14
                   return OFOxmBsnLagIdVer14.READER.readFrom(bb);
               case 0x30308:
                   // discriminator value 0x30308L=0x30308L for class OFOxmBsnLagIdMaskedVer14
                   return OFOxmBsnLagIdMaskedVer14.READER.readFrom(bb);
               case 0x32002:
                   // discriminator value 0x32002L=0x32002L for class OFOxmBsnTcpFlagsVer14
                   return OFOxmBsnTcpFlagsVer14.READER.readFrom(bb);
               case 0x32104:
                   // discriminator value 0x32104L=0x32104L for class OFOxmBsnTcpFlagsMaskedVer14
                   return OFOxmBsnTcpFlagsMaskedVer14.READER.readFrom(bb);
               case 0x31004:
                   // discriminator value 0x31004L=0x31004L for class OFOxmBsnUdf0Ver14
                   return OFOxmBsnUdf0Ver14.READER.readFrom(bb);
               case 0x31108:
                   // discriminator value 0x31108L=0x31108L for class OFOxmBsnUdf0MaskedVer14
                   return OFOxmBsnUdf0MaskedVer14.READER.readFrom(bb);
               case 0x31204:
                   // discriminator value 0x31204L=0x31204L for class OFOxmBsnUdf1Ver14
                   return OFOxmBsnUdf1Ver14.READER.readFrom(bb);
               case 0x31308:
                   // discriminator value 0x31308L=0x31308L for class OFOxmBsnUdf1MaskedVer14
                   return OFOxmBsnUdf1MaskedVer14.READER.readFrom(bb);
               case 0x31404:
                   // discriminator value 0x31404L=0x31404L for class OFOxmBsnUdf2Ver14
                   return OFOxmBsnUdf2Ver14.READER.readFrom(bb);
               case 0x31508:
                   // discriminator value 0x31508L=0x31508L for class OFOxmBsnUdf2MaskedVer14
                   return OFOxmBsnUdf2MaskedVer14.READER.readFrom(bb);
               case 0x31604:
                   // discriminator value 0x31604L=0x31604L for class OFOxmBsnUdf3Ver14
                   return OFOxmBsnUdf3Ver14.READER.readFrom(bb);
               case 0x31708:
                   // discriminator value 0x31708L=0x31708L for class OFOxmBsnUdf3MaskedVer14
                   return OFOxmBsnUdf3MaskedVer14.READER.readFrom(bb);
               case 0x31804:
                   // discriminator value 0x31804L=0x31804L for class OFOxmBsnUdf4Ver14
                   return OFOxmBsnUdf4Ver14.READER.readFrom(bb);
               case 0x31908:
                   // discriminator value 0x31908L=0x31908L for class OFOxmBsnUdf4MaskedVer14
                   return OFOxmBsnUdf4MaskedVer14.READER.readFrom(bb);
               case 0x31a04:
                   // discriminator value 0x31a04L=0x31a04L for class OFOxmBsnUdf5Ver14
                   return OFOxmBsnUdf5Ver14.READER.readFrom(bb);
               case 0x31b08:
                   // discriminator value 0x31b08L=0x31b08L for class OFOxmBsnUdf5MaskedVer14
                   return OFOxmBsnUdf5MaskedVer14.READER.readFrom(bb);
               case 0x31c04:
                   // discriminator value 0x31c04L=0x31c04L for class OFOxmBsnUdf6Ver14
                   return OFOxmBsnUdf6Ver14.READER.readFrom(bb);
               case 0x31d08:
                   // discriminator value 0x31d08L=0x31d08L for class OFOxmBsnUdf6MaskedVer14
                   return OFOxmBsnUdf6MaskedVer14.READER.readFrom(bb);
               case 0x31e04:
                   // discriminator value 0x31e04L=0x31e04L for class OFOxmBsnUdf7Ver14
                   return OFOxmBsnUdf7Ver14.READER.readFrom(bb);
               case 0x31f08:
                   // discriminator value 0x31f08L=0x31f08L for class OFOxmBsnUdf7MaskedVer14
                   return OFOxmBsnUdf7MaskedVer14.READER.readFrom(bb);
               case 0x32204:
                   // discriminator value 0x32204L=0x32204L for class OFOxmBsnVlanXlatePortGroupIdVer14
                   return OFOxmBsnVlanXlatePortGroupIdVer14.READER.readFrom(bb);
               case 0x32308:
                   // discriminator value 0x32308L=0x32308L for class OFOxmBsnVlanXlatePortGroupIdMaskedVer14
                   return OFOxmBsnVlanXlatePortGroupIdMaskedVer14.READER.readFrom(bb);
               case 0x30404:
                   // discriminator value 0x30404L=0x30404L for class OFOxmBsnVrfVer14
                   return OFOxmBsnVrfVer14.READER.readFrom(bb);
               case 0x30508:
                   // discriminator value 0x30508L=0x30508L for class OFOxmBsnVrfMaskedVer14
                   return OFOxmBsnVrfMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000606:
                   // discriminator value 0x80000606L=0x80000606L for class OFOxmEthDstVer14
                   return OFOxmEthDstVer14.READER.readFrom(bb);
               case (int) 0x8000070c:
                   // discriminator value 0x8000070cL=0x8000070cL for class OFOxmEthDstMaskedVer14
                   return OFOxmEthDstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000806:
                   // discriminator value 0x80000806L=0x80000806L for class OFOxmEthSrcVer14
                   return OFOxmEthSrcVer14.READER.readFrom(bb);
               case (int) 0x8000090c:
                   // discriminator value 0x8000090cL=0x8000090cL for class OFOxmEthSrcMaskedVer14
                   return OFOxmEthSrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000a02:
                   // discriminator value 0x80000a02L=0x80000a02L for class OFOxmEthTypeVer14
                   return OFOxmEthTypeVer14.READER.readFrom(bb);
               case (int) 0x80000b04:
                   // discriminator value 0x80000b04L=0x80000b04L for class OFOxmEthTypeMaskedVer14
                   return OFOxmEthTypeMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002801:
                   // discriminator value 0x80002801L=0x80002801L for class OFOxmIcmpv4CodeVer14
                   return OFOxmIcmpv4CodeVer14.READER.readFrom(bb);
               case (int) 0x80002902:
                   // discriminator value 0x80002902L=0x80002902L for class OFOxmIcmpv4CodeMaskedVer14
                   return OFOxmIcmpv4CodeMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002601:
                   // discriminator value 0x80002601L=0x80002601L for class OFOxmIcmpv4TypeVer14
                   return OFOxmIcmpv4TypeVer14.READER.readFrom(bb);
               case (int) 0x80002702:
                   // discriminator value 0x80002702L=0x80002702L for class OFOxmIcmpv4TypeMaskedVer14
                   return OFOxmIcmpv4TypeMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003c01:
                   // discriminator value 0x80003c01L=0x80003c01L for class OFOxmIcmpv6CodeVer14
                   return OFOxmIcmpv6CodeVer14.READER.readFrom(bb);
               case (int) 0x80003d02:
                   // discriminator value 0x80003d02L=0x80003d02L for class OFOxmIcmpv6CodeMaskedVer14
                   return OFOxmIcmpv6CodeMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003a01:
                   // discriminator value 0x80003a01L=0x80003a01L for class OFOxmIcmpv6TypeVer14
                   return OFOxmIcmpv6TypeVer14.READER.readFrom(bb);
               case (int) 0x80003b02:
                   // discriminator value 0x80003b02L=0x80003b02L for class OFOxmIcmpv6TypeMaskedVer14
                   return OFOxmIcmpv6TypeMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000204:
                   // discriminator value 0x80000204L=0x80000204L for class OFOxmInPhyPortVer14
                   return OFOxmInPhyPortVer14.READER.readFrom(bb);
               case (int) 0x80000308:
                   // discriminator value 0x80000308L=0x80000308L for class OFOxmInPhyPortMaskedVer14
                   return OFOxmInPhyPortMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000004:
                   // discriminator value 0x80000004L=0x80000004L for class OFOxmInPortVer14
                   return OFOxmInPortVer14.READER.readFrom(bb);
               case (int) 0x80000108:
                   // discriminator value 0x80000108L=0x80000108L for class OFOxmInPortMaskedVer14
                   return OFOxmInPortMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001001:
                   // discriminator value 0x80001001L=0x80001001L for class OFOxmIpDscpVer14
                   return OFOxmIpDscpVer14.READER.readFrom(bb);
               case (int) 0x80001102:
                   // discriminator value 0x80001102L=0x80001102L for class OFOxmIpDscpMaskedVer14
                   return OFOxmIpDscpMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001201:
                   // discriminator value 0x80001201L=0x80001201L for class OFOxmIpEcnVer14
                   return OFOxmIpEcnVer14.READER.readFrom(bb);
               case (int) 0x80001302:
                   // discriminator value 0x80001302L=0x80001302L for class OFOxmIpEcnMaskedVer14
                   return OFOxmIpEcnMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001401:
                   // discriminator value 0x80001401L=0x80001401L for class OFOxmIpProtoVer14
                   return OFOxmIpProtoVer14.READER.readFrom(bb);
               case (int) 0x80001502:
                   // discriminator value 0x80001502L=0x80001502L for class OFOxmIpProtoMaskedVer14
                   return OFOxmIpProtoMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001804:
                   // discriminator value 0x80001804L=0x80001804L for class OFOxmIpv4DstVer14
                   return OFOxmIpv4DstVer14.READER.readFrom(bb);
               case (int) 0x80001908:
                   // discriminator value 0x80001908L=0x80001908L for class OFOxmIpv4DstMaskedVer14
                   return OFOxmIpv4DstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001604:
                   // discriminator value 0x80001604L=0x80001604L for class OFOxmIpv4SrcVer14
                   return OFOxmIpv4SrcVer14.READER.readFrom(bb);
               case (int) 0x80001708:
                   // discriminator value 0x80001708L=0x80001708L for class OFOxmIpv4SrcMaskedVer14
                   return OFOxmIpv4SrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003610:
                   // discriminator value 0x80003610L=0x80003610L for class OFOxmIpv6DstVer14
                   return OFOxmIpv6DstVer14.READER.readFrom(bb);
               case (int) 0x80003720:
                   // discriminator value 0x80003720L=0x80003720L for class OFOxmIpv6DstMaskedVer14
                   return OFOxmIpv6DstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003804:
                   // discriminator value 0x80003804L=0x80003804L for class OFOxmIpv6FlabelVer14
                   return OFOxmIpv6FlabelVer14.READER.readFrom(bb);
               case (int) 0x80003908:
                   // discriminator value 0x80003908L=0x80003908L for class OFOxmIpv6FlabelMaskedVer14
                   return OFOxmIpv6FlabelMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004006:
                   // discriminator value 0x80004006L=0x80004006L for class OFOxmIpv6NdSllVer14
                   return OFOxmIpv6NdSllVer14.READER.readFrom(bb);
               case (int) 0x8000410c:
                   // discriminator value 0x8000410cL=0x8000410cL for class OFOxmIpv6NdSllMaskedVer14
                   return OFOxmIpv6NdSllMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003e10:
                   // discriminator value 0x80003e10L=0x80003e10L for class OFOxmIpv6NdTargetVer14
                   return OFOxmIpv6NdTargetVer14.READER.readFrom(bb);
               case (int) 0x80003f20:
                   // discriminator value 0x80003f20L=0x80003f20L for class OFOxmIpv6NdTargetMaskedVer14
                   return OFOxmIpv6NdTargetMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004206:
                   // discriminator value 0x80004206L=0x80004206L for class OFOxmIpv6NdTllVer14
                   return OFOxmIpv6NdTllVer14.READER.readFrom(bb);
               case (int) 0x8000430c:
                   // discriminator value 0x8000430cL=0x8000430cL for class OFOxmIpv6NdTllMaskedVer14
                   return OFOxmIpv6NdTllMaskedVer14.READER.readFrom(bb);
               case (int) 0x80003410:
                   // discriminator value 0x80003410L=0x80003410L for class OFOxmIpv6SrcVer14
                   return OFOxmIpv6SrcVer14.READER.readFrom(bb);
               case (int) 0x80003520:
                   // discriminator value 0x80003520L=0x80003520L for class OFOxmIpv6SrcMaskedVer14
                   return OFOxmIpv6SrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000408:
                   // discriminator value 0x80000408L=0x80000408L for class OFOxmMetadataVer14
                   return OFOxmMetadataVer14.READER.readFrom(bb);
               case (int) 0x80000510:
                   // discriminator value 0x80000510L=0x80000510L for class OFOxmMetadataMaskedVer14
                   return OFOxmMetadataMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004404:
                   // discriminator value 0x80004404L=0x80004404L for class OFOxmMplsLabelVer14
                   return OFOxmMplsLabelVer14.READER.readFrom(bb);
               case (int) 0x80004508:
                   // discriminator value 0x80004508L=0x80004508L for class OFOxmMplsLabelMaskedVer14
                   return OFOxmMplsLabelMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004601:
                   // discriminator value 0x80004601L=0x80004601L for class OFOxmMplsTcVer14
                   return OFOxmMplsTcVer14.READER.readFrom(bb);
               case (int) 0x80004702:
                   // discriminator value 0x80004702L=0x80004702L for class OFOxmMplsTcMaskedVer14
                   return OFOxmMplsTcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002402:
                   // discriminator value 0x80002402L=0x80002402L for class OFOxmSctpDstVer14
                   return OFOxmSctpDstVer14.READER.readFrom(bb);
               case (int) 0x80002504:
                   // discriminator value 0x80002504L=0x80002504L for class OFOxmSctpDstMaskedVer14
                   return OFOxmSctpDstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002202:
                   // discriminator value 0x80002202L=0x80002202L for class OFOxmSctpSrcVer14
                   return OFOxmSctpSrcVer14.READER.readFrom(bb);
               case (int) 0x80002304:
                   // discriminator value 0x80002304L=0x80002304L for class OFOxmSctpSrcMaskedVer14
                   return OFOxmSctpSrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001c02:
                   // discriminator value 0x80001c02L=0x80001c02L for class OFOxmTcpDstVer14
                   return OFOxmTcpDstVer14.READER.readFrom(bb);
               case (int) 0x80001d04:
                   // discriminator value 0x80001d04L=0x80001d04L for class OFOxmTcpDstMaskedVer14
                   return OFOxmTcpDstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001a02:
                   // discriminator value 0x80001a02L=0x80001a02L for class OFOxmTcpSrcVer14
                   return OFOxmTcpSrcVer14.READER.readFrom(bb);
               case (int) 0x80001b04:
                   // discriminator value 0x80001b04L=0x80001b04L for class OFOxmTcpSrcMaskedVer14
                   return OFOxmTcpSrcMaskedVer14.READER.readFrom(bb);
               case 0x14004:
                   // discriminator value 0x14004L=0x14004L for class OFOxmTunnelIpv4DstVer14
                   return OFOxmTunnelIpv4DstVer14.READER.readFrom(bb);
               case 0x14108:
                   // discriminator value 0x14108L=0x14108L for class OFOxmTunnelIpv4DstMaskedVer14
                   return OFOxmTunnelIpv4DstMaskedVer14.READER.readFrom(bb);
               case 0x13e04:
                   // discriminator value 0x13e04L=0x13e04L for class OFOxmTunnelIpv4SrcVer14
                   return OFOxmTunnelIpv4SrcVer14.READER.readFrom(bb);
               case 0x13f08:
                   // discriminator value 0x13f08L=0x13f08L for class OFOxmTunnelIpv4SrcMaskedVer14
                   return OFOxmTunnelIpv4SrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80002002:
                   // discriminator value 0x80002002L=0x80002002L for class OFOxmUdpDstVer14
                   return OFOxmUdpDstVer14.READER.readFrom(bb);
               case (int) 0x80002104:
                   // discriminator value 0x80002104L=0x80002104L for class OFOxmUdpDstMaskedVer14
                   return OFOxmUdpDstMaskedVer14.READER.readFrom(bb);
               case (int) 0x80001e02:
                   // discriminator value 0x80001e02L=0x80001e02L for class OFOxmUdpSrcVer14
                   return OFOxmUdpSrcVer14.READER.readFrom(bb);
               case (int) 0x80001f04:
                   // discriminator value 0x80001f04L=0x80001f04L for class OFOxmUdpSrcMaskedVer14
                   return OFOxmUdpSrcMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000e01:
                   // discriminator value 0x80000e01L=0x80000e01L for class OFOxmVlanPcpVer14
                   return OFOxmVlanPcpVer14.READER.readFrom(bb);
               case (int) 0x80000f02:
                   // discriminator value 0x80000f02L=0x80000f02L for class OFOxmVlanPcpMaskedVer14
                   return OFOxmVlanPcpMaskedVer14.READER.readFrom(bb);
               case (int) 0x80000c02:
                   // discriminator value 0x80000c02L=0x80000c02L for class OFOxmVlanVidVer14
                   return OFOxmVlanVidVer14.READER.readFrom(bb);
               case (int) 0x80000d04:
                   // discriminator value 0x80000d04L=0x80000d04L for class OFOxmVlanVidMaskedVer14
                   return OFOxmVlanVidMaskedVer14.READER.readFrom(bb);
               case 0x32c06:
                   // discriminator value 0x32c06L=0x32c06L for class OFOxmBsnInnerEthDstVer14
                   return OFOxmBsnInnerEthDstVer14.READER.readFrom(bb);
               case 0x32d0c:
                   // discriminator value 0x32d0cL=0x32d0cL for class OFOxmBsnInnerEthDstMaskedVer14
                   return OFOxmBsnInnerEthDstMaskedVer14.READER.readFrom(bb);
               case 0x32e06:
                   // discriminator value 0x32e06L=0x32e06L for class OFOxmBsnInnerEthSrcVer14
                   return OFOxmBsnInnerEthSrcVer14.READER.readFrom(bb);
               case 0x32f0c:
                   // discriminator value 0x32f0cL=0x32f0cL for class OFOxmBsnInnerEthSrcMaskedVer14
                   return OFOxmBsnInnerEthSrcMaskedVer14.READER.readFrom(bb);
               case 0x33002:
                   // discriminator value 0x33002L=0x33002L for class OFOxmBsnInnerVlanVidVer14
                   return OFOxmBsnInnerVlanVidVer14.READER.readFrom(bb);
               case 0x33104:
                   // discriminator value 0x33104L=0x33104L for class OFOxmBsnInnerVlanVidMaskedVer14
                   return OFOxmBsnInnerVlanVidMaskedVer14.READER.readFrom(bb);
               case 0x32a04:
                   // discriminator value 0x32a04L=0x32a04L for class OFOxmBsnVxlanNetworkIdVer14
                   return OFOxmBsnVxlanNetworkIdVer14.READER.readFrom(bb);
               case 0x32b08:
                   // discriminator value 0x32b08L=0x32b08L for class OFOxmBsnVxlanNetworkIdMaskedVer14
                   return OFOxmBsnVxlanNetworkIdMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004e02:
                   // discriminator value 0x80004e02L=0x80004e02L for class OFOxmIpv6ExthdrVer14
                   return OFOxmIpv6ExthdrVer14.READER.readFrom(bb);
               case (int) 0x80004f04:
                   // discriminator value 0x80004f04L=0x80004f04L for class OFOxmIpv6ExthdrMaskedVer14
                   return OFOxmIpv6ExthdrMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004801:
                   // discriminator value 0x80004801L=0x80004801L for class OFOxmMplsBosVer14
                   return OFOxmMplsBosVer14.READER.readFrom(bb);
               case (int) 0x80004902:
                   // discriminator value 0x80004902L=0x80004902L for class OFOxmMplsBosMaskedVer14
                   return OFOxmMplsBosMaskedVer14.READER.readFrom(bb);
               case (int) 0x80004c08:
                   // discriminator value 0x80004c08L=0x80004c08L for class OFOxmTunnelIdVer14
                   return OFOxmTunnelIdVer14.READER.readFrom(bb);
               case (int) 0x80004d10:
                   // discriminator value 0x80004d10L=0x80004d10L for class OFOxmTunnelIdMaskedVer14
                   return OFOxmTunnelIdMaskedVer14.READER.readFrom(bb);
               case (int) 0x80005201:
                   // discriminator value 0x80005201L=0x80005201L for class OFOxmPbbUcaVer14
                   return OFOxmPbbUcaVer14.READER.readFrom(bb);
               case (int) 0x80005302:
                   // discriminator value 0x80005302L=0x80005302L for class OFOxmPbbUcaMaskedVer14
                   return OFOxmPbbUcaMaskedVer14.READER.readFrom(bb);
               default:
                   throw new OFParseError("Unknown value for discriminator typeLen of class OFOxmVer14: " + typeLen);
            }
        }
    }
}
