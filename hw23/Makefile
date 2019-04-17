ShapeDriver:  Shape.o ShapeDriver.o sd_fun.o str_util.o
	g++ -g -Wall -std=c++11 -o ShapeDriver Shape.o ShapeDriver.o  sd_fun.o str_util.o

Shape.o:  Shape.cpp Shape.h sd_fun.h
	g++ -g -Wall -std=c++11 -c Shape.cpp

ShapeDriver.o: ShapeDriver.cpp Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c ShapeDriver.cpp

RectangleDriver:  Shape.o Rectangle.o RectangleDriver.o sd_fun.o str_util.o
	g++ -g -Wall -std=c++11 -o RectangleDriver Rectangle.o RectangleDriver.o Shape.o sd_fun.o str_util.o

Rectangle.o:  Rectangle.cpp Rectangle.h Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c Rectangle.cpp

RectangleDriver.o: RectangleDriver.cpp Rectangle.h Rectangle.cpp Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c RectangleDriver.cpp

CircleDriver:  Shape.o Circle.o CircleDriver.o sd_fun.o str_util.o
	g++ -g -Wall -std=c++11 -o CircleDriver Circle.o CircleDriver.o Shape.o sd_fun.o str_util.o

Circle.o:  Circle.cpp Circle.h Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c Circle.cpp

CircleDriver.o: CircleDriver.cpp Circle.h Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c CircleDriver.cpp

ShapeDriver1: Shape.o Rectangle.o Circle.o ShapeDriver1.o sd_fun.o str_util.o
	g++ -g -Wall -std=c++11 -o ShapeDriver1 Rectangle.o Circle.o ShapeDriver1.o Shape.o sd_fun.o str_util.o

ShapeDriver2: Shape.o Rectangle.o Circle.o ShapeDriver2.o sd_fun.o str_util.o
	g++ -g -Wall -std=c++11 -o ShapeDriver2 Rectangle.o Circle.o ShapeDriver2.o Shape.o sd_fun.o str_util.o

testShapeInput: Shape.o Rectangle.o Circle.o ShapeDriver2.o sd_fun.o str_util.o testShapeInput.o
	g++ -g -Wall -std=c++11 -o testShapeInput Rectangle.o Circle.o testShapeInput.o Shape.o sd_fun.o str_util.o

testShapeInput.o: testShapeInput.cpp Rectangle.h Rectangle.cpp Circle.cpp Circle.h Shape.h Shape.cpp sd_fun.h
	g++ -g -Wall -std=c++11 -c testShapeInput.cpp

Clean:
	rm *.gch