#include "Mac.h"
#include <iostream>

struct ST_IEEE80211_RADIOTAP_HEADER 
{
    u_int8_t        version;     
    u_int8_t        pad;
    u_int16_t       len;         
    u_int8_t		present[8];  
	u_int8_t		flags;
	u_int8_t		dataRate;
	u_int16_t		channelFrequency;
	u_int16_t		channelFlags;  
	int8_t		antennaSignal; 
	u_int8_t		antenna;
	u_int16_t		rxFlags; 
	int8_t		antennaSignalT;
	u_int8_t		antennaT;
};

struct ST_BEACON_FRAME
{
	u_int16_t frameControl; 
	u_int16_t duration;
	Mac destinationAddr;
	Mac transmitterAddr;
	Mac bssid;
	u_int16_t seqNum;
};

struct ST_WIRELESS_MANAGER
{
	u_int8_t timestamp[8];
	u_int16_t beaconInterval;
	u_int16_t capabilityInfo;
};

struct ST_SSID_PARAMETER
{
	u_int8_t tagName;
	u_int8_t tagLength;
};

struct ST_WIRELESS_PACKET
{
	ST_IEEE80211_RADIOTAP_HEADER ieee80211RadiotapHeader;
	ST_BEACON_FRAME beaconFrame;
	ST_WIRELESS_MANAGER wirelessManager;
	ST_SSID_PARAMETER ssidParameter;
};

