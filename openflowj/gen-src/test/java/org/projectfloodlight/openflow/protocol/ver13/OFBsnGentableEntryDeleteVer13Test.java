// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template unit_test.java
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
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.Before;
import java.util.List;
import com.google.common.collect.ImmutableList;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import org.hamcrest.CoreMatchers;



public class OFBsnGentableEntryDeleteVer13Test {
    OFFactory factory;

    final static byte[] BSN_GENTABLE_ENTRY_DELETE_SERIALIZED =
        new byte[] { 0x4, 0x4, 0x0, 0x24, 0x12, 0x34, 0x56, 0x78, 0x0, 0x5c, 0x16, (byte) 0xc7, 0x0, 0x0, 0x0, 0x2f, 0x0, 0x14, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x5, 0x0, 0x1, 0x0, 0xa, 0x1, 0x23, 0x45, 0x67, (byte) 0x89, (byte) 0xab };

    @Before
    public void setup() {
        factory = OFFactoryVer13.INSTANCE;
    }

    @Test
    public void testWrite() {
        OFBsnGentableEntryDelete.Builder builder = factory.buildBsnGentableEntryDelete();
        builder.setXid(0x12345678)
    .setTableId(GenTableId.of(20))
    .setKey(
        ImmutableList.<OFBsnTlv>of(
            factory.bsnTlvs().port(OFPort.of(5)),
            factory.bsnTlvs().mac(MacAddress.of("01:23:45:67:89:ab"))
        )
    );
        OFBsnGentableEntryDelete bsnGentableEntryDelete = builder.build();
        ByteBuf bb = Unpooled.buffer();
        bsnGentableEntryDelete.writeTo(bb);
        byte[] written = new byte[bb.readableBytes()];
        bb.readBytes(written);

        assertThat(written, CoreMatchers.equalTo(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED));
    }

    @Test
    public void testRead() throws Exception {
        OFBsnGentableEntryDelete.Builder builder = factory.buildBsnGentableEntryDelete();
        builder.setXid(0x12345678)
    .setTableId(GenTableId.of(20))
    .setKey(
        ImmutableList.<OFBsnTlv>of(
            factory.bsnTlvs().port(OFPort.of(5)),
            factory.bsnTlvs().mac(MacAddress.of("01:23:45:67:89:ab"))
        )
    );
        OFBsnGentableEntryDelete bsnGentableEntryDeleteBuilt = builder.build();

        ByteBuf input = Unpooled.copiedBuffer(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED);

        // FIXME should invoke the overall reader once implemented
        OFBsnGentableEntryDelete bsnGentableEntryDeleteRead = OFBsnGentableEntryDeleteVer13.READER.readFrom(input);
        assertEquals(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED.length, input.readerIndex());

        assertEquals(bsnGentableEntryDeleteBuilt, bsnGentableEntryDeleteRead);
   }

   @Test
   public void testReadWrite() throws Exception {
       ByteBuf input = Unpooled.copiedBuffer(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED);

       // FIXME should invoke the overall reader once implemented
       OFBsnGentableEntryDelete bsnGentableEntryDelete = OFBsnGentableEntryDeleteVer13.READER.readFrom(input);
       assertEquals(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED.length, input.readerIndex());

       // write message again
       ByteBuf bb = Unpooled.buffer();
       bsnGentableEntryDelete.writeTo(bb);
       byte[] written = new byte[bb.readableBytes()];
       bb.readBytes(written);

       assertThat(written, CoreMatchers.equalTo(BSN_GENTABLE_ENTRY_DELETE_SERIALIZED));
   }

}
