# DVDArrayPDriver: DVD.o DVDArrayP.o DVDArrayPDriver.o
# 	g++ -g -Wall -std=c++11 -o DVDArrayPDriver DVD.o DVDArrayP.o DVDArrayPDriver.o

# DVD.o: DVD.cpp DVD.h
# 	g++ -g -Wall -std=c++11 -c DVD.cpp

# DVDArrayP.o: DVD.h DVD.cpp DVDArrayP.h DVDArrayP.cpp
# 	g++ -g -Wall -std=c++11 -c DVDArrayP.cpp

# DVDArrayPDriver.o: DVDArrayPDriver.cpp DVD.h DVDArrayP.h
# 	g++ -g -Wall -std=c++11 -c DVDArrayPDriver.cpp
DVDArrayPDriver:  DVDArrayPDriver.o DVDArrayP.o DVD.o
	g++ -g -Wall -std=c++11 -o DVDArrayPDriver DVD.o DVDArrayP.o DVDArrayPDriver.o

DVDArrayPDriver.o:  DVDArrayPDriver.cpp DVDArrayP.h DVD.h
	g++ -g -Wall -std=c++11 -c DVDArrayPDriver.cpp

DVDArrayP.o:  DVDArrayP.cpp DVDArrayP.h DVD.h DVDArrayP2.cpp
	g++ -g -Wall -std=c++11 -c DVDArrayP.cpp

DVD.o:  DVD.cpp DVD.h
	g++ -g -Wall -std=c++11 -c DVD.cpp
