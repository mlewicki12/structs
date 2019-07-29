
#include <iostream>
#include <stack>
#include <ctime>

#include "arrays/arraystack.hpp"
#include "pointers/pointerstack.hpp"

int main() {
	auto arraystack = new ML::ArrayStack<int>();
	clock_t start, stop;
	
	start = clock();
	for(int i = 0; i < 1024; ++i) {
		arraystack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to an array based stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto pointerstack = new ML::PointerStack<int>();
	
	start = clock();
	for(int i = 0; i < 1024; ++i) {
		pointerstack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to a pointer based stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto stdstack = new std::stack<int>();

	start = clock();
	for(int i = 0; i < 1024; ++i) {
		stdstack->push(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to standard stack -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";
}
