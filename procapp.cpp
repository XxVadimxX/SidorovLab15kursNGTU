#include "procapp.h"
#include "inputpacket.h"
#include "outpacket.h"
#include <iostream>
using namespace std;

static bool procAppReceivePacket(ProcApp& app, InputPacket& packet);
static void procAppProcessing(ProcApp& app, InputPacket& input, OutputPacket& output);
static void procAppSendPacket(ProcApp& app, OutputPacket& packet);
static void processingImpl(const InputPacket& input, OutputPacket& output, const ProcConfig& config);

int procAppRun(ProcApp& app)
{
    InputPacket inputPacket;
    OutputPacket outputPacket;

    while(1)
    {
        bool needContinue = procAppReceivePacket(app, inputPacket);
        if(!needContinue)
            break;
        procAppProcessing(app, inputPacket, outputPacket);
        procAppSendPacket(app, outputPacket);
    }
    return 0;
}

static bool procAppReceivePacket(ProcApp& /*app*/, InputPacket& packet)
{
//    std::cout << "===========Call procAppReceivePacket===========" << std::endl;
    std::cout << "count= ";
    std::cin >> packet.count;
    if(packet.count > INPUTPACKET_MAXCOUNT)
        return false;
    std::cout << "items= ";

    for(unsigned i = 0; i< packet.count; ++i)
        std::cin >> packet.data[i].level;
    return true;
}

static void procAppProcessing(ProcApp& app, InputPacket& input, OutputPacket& output)
{
//    std::cout << "===========Call procAppProcessing===========" << std::endl;
    processingImpl(input, output, app.procConfig);
    return;
}

static void procAppSendPacket(ProcApp& /*app*/, OutputPacket& packet)
{
//    std::cout << "===========Call procAppSendPacket===========" << std::endl;
    std::cout << "count= " << packet.count << std::endl;
    std::cout << "items= ";
    for(unsigned i = 0; i < packet.count; ++i)
        std::cout << "(" << packet.data[i].idx << ' ' << packet.data[i].level << ")";
    std::cout << std::endl;
    return;

}

static void processingImpl(const InputPacket& input, OutputPacket& output, const ProcConfig& config)
{
//    std::cout << "===========Call processingImpl===========" << std::endl;
    unsigned outCount = 0;
    bool left = false;
    unsigned leftIdx = 0;
    for(unsigned i = 1; (i + 1) < input.count; ++i)
    {
        unsigned level = input.data[i].level;
        if(input.data[i-1].level < level)
        {
            left = true;
            leftIdx = i;
        }

        if(left && level > input.data[i+1].level)
        {
            if(config.coeff*input.data[i-1].level > level && config.coeff*input.data[i+1].level > level)
            {
                output.data[outCount].level = level;
                output.data[outCount].idx = (leftIdx + i) / 2;
                outCount++;
            }
            left = false;
        }
    }
    output.count = outCount;
    std::cout << outCount << std::endl;
    return;
}










