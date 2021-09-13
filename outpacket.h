#ifndef OUTPACKET_H
#define OUTPACKET_H

struct OutputPacketItem
{
    unsigned idx;
    unsigned level;
};

#define OUTPUTPACKET_MAXCOUNT 100

struct OutputPacket
{
    unsigned count;
    OutputPacketItem data[OUTPUTPACKET_MAXCOUNT];
};

#endif // OUTPACKET_H
