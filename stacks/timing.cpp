
#include <iostream>
#include <stack>
#include <ctime>

#include "arrays/arraystack.hpp"
#include "pointers/pointerstack.hpp"

#define TEST_SIZE 32768

int main() {
	auto arraystack = new ML::ArrayStack<int>();
	clock_t start, stop;
	
	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		arraystack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to an array based stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto pointerstack = new ML::PointerStack<int>();
	
	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		pointerstack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to a pointer based stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto stdstack = new std::stack<int>();

	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		stdstack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to standard stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";
}
