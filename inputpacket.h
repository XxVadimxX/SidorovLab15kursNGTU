#ifndef INPUTPACKET_H
#define INPUTPACKET_H

struct InputPacketItem // Описание входного отсчета
{
    unsigned level;
};

#define INPUTPACKET_MAXCOUNT 100

struct InputPacket // Описание пактеа с входными данными
{
    unsigned count;
    InputPacketItem data[INPUTPACKET_MAXCOUNT];
};

#endif // INPUTPACKET_H
