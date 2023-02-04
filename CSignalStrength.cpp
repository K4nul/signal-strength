#include "CSignalStrength.h"

CSignalStrength::CSignalStrength(CParam parameter) : param(parameter)
{
    transmitterInfo.transmitterAddr  = param.targetMac;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap = pcap_open_live(param.interface.data(), BUFSIZ, 1, 500, errbuf);
	if (pcap == NULL) {
		fprintf(stderr, "pcap_open_live(%s) return null - %s\n", param.interface.data(), errbuf);
        exit(1);
	}

}

CSignalStrength::~CSignalStrength(){

    pcap_close(pcap);  
}


int CSignalStrength::signalStrength()
{
    
    initscr();
    move(0,0);
    
    while(1)
    {   
        
        int status = getWirelessPacket(pcap);
        
        if (status == FAIL)
            break; 
        if (status == NEXT)
            continue;
        
        status = convertPacket();
        if (status == NEXT)    
            continue;
            
        printLog();
    }

    getch();

    
    return 0;

}

status CSignalStrength::getWirelessPacket(pcap_t* pcap)
{
  
	struct pcap_pkthdr* header;
	int res = pcap_next_ex(pcap, &header, &packet);
	if (res == 0)
        return NEXT;
	if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) {
		printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(pcap));
		return FAIL;
	}


    return SUCCESS;
	  

}

status CSignalStrength::convertPacket()
{
    ST_WIRELESS_PACKET* wirelessPacket = (ST_WIRELESS_PACKET*)packet;
   
    if(wirelessPacket->beaconFrame.frameControl != 0x80)
        return NEXT;    
    
    if(wirelessPacket->beaconFrame.transmitterAddr != param.targetMac)
        return NEXT;        

    transmitterInfo.pwr =  wirelessPacket->ieee80211RadiotapHeader.antennaSignal;
    return SUCCESS;
}

void CSignalStrength::printLog()
{
    clear();
    printw("TransmitterAddr\t\tPWR\n");
         
    printw("%s\t%d\n", std::string(transmitterInfo.transmitterAddr).data(),transmitterInfo.pwr);
    refresh();
        

}

