#include "Mac.h"
#include "CParam.h"
#include "WirelessPacket.h"
#include <iostream>
#include <string> 
#include <vector>
#include <map>
#include <utility>
#include <unistd.h>
#include <stdio.h>
#include <pcap.h>
#include <ncurses.h>

enum status
{
    SUCCESS,
    FAIL,
    NEXT
};

struct ST_TRANSMITTER_INFO
{
	Mac transmitterAddr;
	int8_t pwr;
};


class CSignalStrength 
{
private:
	
	pcap_t* pcap;	
    CParam param;
    const u_char* packet;
	ST_TRANSMITTER_INFO transmitterInfo;
    

public:

    CSignalStrength(CParam parameter);
    ~CSignalStrength();
    int signalStrength();

private:

    status getWirelessPacket(pcap_t* pcap);
    status convertPacket();
	void printLog();
	void setChannel();

};