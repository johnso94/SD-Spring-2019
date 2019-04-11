ShapeDriver:  Shape.o ShapeDriver.o
	g++ -g -Wall -std=c++11 -o ShapeDriver Shape.o ShapeDriver.o

Shape.o:  Shape.cpp Shape.h
	g++ -g -Wall -std=c++11 -c Shape.cpp

ShapeDriver.o: ShapeDriver.cpp
	g++ -g -Wall -std=c++11 -c ShapeDriver.cpp

RectangleDriver:  Shape.o Rectangle.o RectangleDriver.o
	g++ -g -Wall -std=c++11 -o RectangleDriver Rectangle.o RectangleDriver.o Shape.o

Rectangle.o:  Rectangle.cpp Rectangle.h Shape.h
	g++ -g -Wall -std=c++11 -c Rectangle.cpp

RectangleDriver.o: RectangleDriver.cpp Rectangle.h Shape.h
	g++ -g -Wall -std=c++11 -c RectangleDriver.cpp

CircleDriver:  Shape.o Circle.o CircleDriver.o
	g++ -g -Wall -std=c++11 -o CircleDriver Circle.o CircleDriver.o Shape.o

Circle.o:  Circle.cpp Circle.h Shape.h
	g++ -g -Wall -std=c++11 -c Circle.cpp

CircleDriver.o: CircleDriver.cpp Circle.h Shape.h
	g++ -g -Wall -std=c++11 -c CircleDriver.cpp