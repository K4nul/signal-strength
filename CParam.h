#include "Mac.h"
#include <iostream>
#include <vector>
#include <string>

class CParam
{
public:


	std::string interface;
	Mac targetMac;
    u_int8_t channel;

    bool parse(int argc, char* argv[]);
    void usage();
};

