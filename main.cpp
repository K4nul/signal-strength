#include "CSignalStrength.h"
#include <iostream>
#include <stdbool.h>
#include <stdio.h>


int main(int argc, char* argv[]) {
	
	CParam param;
	if (!param.parse(argc,argv))
		return -1;


	CSignalStrength signalStrength(param);
	signalStrength.signalStrength();

	return 0;
}
