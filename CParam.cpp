#include "CParam.h"
#include "Mac.h"

void CParam::usage() 
{
	printf("syntax : signal-strength <interface> <mac>\n");
	printf("sample : signal-strength mon0 00:11:22:33:44:55\n");
	


}


bool CParam::parse(int argc, char* argv[])
{
	if (argc < 3 || 4 < argc) {
		usage();
		return false;
	}

	interface = std::string(argv[1]);
	targetMac = std::string(argv[2]);
		
	if(argc == 4)
	{
		channel = std::stoi(argv[3]);
	}else
	{
		channel = 0;
	}

	return true;
}

