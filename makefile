LDLIBS += -lpcap

all: signalStrength

signalStrength: CParam.o Mac.o WirelessPacket.o CSignalStrength.o main.o CParam.h Mac.h WirelessPacket.h CSignalStrength.h
	g++ -g CParam.o Mac.o WirelessPacket.o CSignalStrength.o main.o -o $@ -lncurses ${LDLIBS}  

CParam.o : CParam.h CParam.cpp
	g++ -g -c -o $@ CParam.cpp

Mac.o : Mac.h Mac.cpp 
	g++ -g -c -o $@ Mac.cpp 

WirelessPacket.o : Mac.h WirelessPacket.h WirelessPacket.cpp  
	g++ -g -c -o $@  WirelessPacket.cpp

CSignalStrength.o : CParam.h Mac.h WirelessPacket.h CSignalStrength.h CSignalStrength.cpp 
	g++ -g -c -o $@ CSignalStrength.cpp 

main.o: CParam.h Mac.h CSignalStrength.h WirelessPacket.h  main.cpp 
	g++ -g -c -o $@ main.cpp

clean:
	rm -f signalStrength *.o
