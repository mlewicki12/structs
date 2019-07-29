
time : buildtime timing.o
	./timing.o

arraylist : buildarraylist test.o
	./test.o

pointerlist : buildpointerlist test.o
	./test.o

arraystack : buildarraystack test.o
	./test.o

pointerstack : buildpointerstack test.o
	./test.o

buildtime : timing.cpp
	g++ -std=c++11 -o timing.o timing.cpp

buildarraylist : lists/arrays/driver.cpp
	g++ -std=c++11 -o test.o lists/arrays/driver.cpp

buildpointerlist : lists/pointers/driver.cpp
	g++ -std=c++11 -o test.o lists/pointers/driver.cpp

buildarraystack : stacks/arrays/driver.cpp
	g++ -std=c++11 -o test.o stacks/arrays/driver.cpp

buildpointerstack : stacks/pointers/driver.cpp
	g++ -std=c++11 -o test.o stacks/pointers/driver.cpp
