
time : buildtime timing.o
	./timing.o

arraylist : buildarraylist test.o
	./test.o

pointerlist : buildpointerlist test.o
	./test.o

buildtime : timing.cpp
	g++ -std=c++11 -o timing.o timing.cpp

buildarraylist : arrays/driver.cpp
	g++ -std=c++11 -o test.o arrays/driver.cpp

buildpointerlist : pointers/driver.cpp
	g++ -std=c++11 -o test.o pointers/driver.cpp
