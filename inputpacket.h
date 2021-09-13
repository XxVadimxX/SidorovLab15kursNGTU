#ifndef INPUTPACKET_H
#define INPUTPACKET_H

struct InputPacketItem
{
    unsigned level;
};

#define INPUTPACKET_MAXCOUNT 100

struct InputPacket
{
    unsigned count;
    InputPacketItem data[INPUTPACKET_MAXCOUNT];
};

#endif // INPUTPACKET_H
