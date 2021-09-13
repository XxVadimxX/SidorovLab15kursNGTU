#ifndef OUTPACKET_H
#define OUTPACKET_H

struct OutputPacketItem // Описание выходного отсчета
{
    unsigned idx;
    unsigned level;
};

#define OUTPUTPACKET_MAXCOUNT 100

struct OutputPacket // Описание пактеа с выходными данными
{
    unsigned count;
    OutputPacketItem data[OUTPUTPACKET_MAXCOUNT];
};

#endif // OUTPACKET_H
