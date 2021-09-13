#include "procapp.h"
#include "inputpacket.h"
#include "outpacket.h"
#include <iostream>
static void procAppReceivePacket(ProcApp& app, InputPacket& packet);
static void procAppProcessing(ProcApp& app, InputPacket& input, OutputPacket& output);
static void procAppSendPacket(ProcApp& app, OutputPacket& packet);

int procAppRun(ProcApp& app)
{
    InputPacket inputPacket;
    OutputPacket outputPacket;

    procAppReceivePacket(app, inputPacket);
    procAppProcessing(app, inputPacket, outputPacket);
    procAppSendPacket(app, outputPacket);

    return 0;
}

static void procAppReceivePacket(ProcApp& /*app*/, InputPacket& /*packet*/)
{
    std::cout << "Call procAppReceivePacket" << std::endl;
}

static void procAppProcessing(ProcApp& /*app*/, InputPacket& /*input*/, OutputPacket& /*output*/)
{
    std::cout << "Call procAppProcessing" << std::endl;
}

static void procAppSendPacket(ProcApp& /*app*/, OutputPacket& /*packet*/)
{
    std::cout << "Call procAppSendPacket" << std::endl;

}


