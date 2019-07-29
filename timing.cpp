
#include <iostream>
#include <list>
#include <stack>
#include <ctime>

#include "lists/arrays/arraylist.hpp"
#include "lists/pointers/pointerlist.hpp"

#include "stacks/arrays/arraystack.hpp"
#include "stacks/pointers/pointerstack.hpp"

#define TEST_SIZE 32768

int main() {
	auto arraylist = new ML::ArrayList<int>(8);
	clock_t start, stop;
	
	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		arraylist->add(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to an array based list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto pointerlist = new ML::PointerList<int>(8);
	
	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		pointerlist->add(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to a pointer based list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	std::list<int> stdlist = {8};

	start = clock();
	for(int i = 0; i < TEST_SIZE; ++i) {
		stdlist.push_back(i);
	}
	stop = clock();

	std::cout << " -- Adding " << TEST_SIZE << " elements to standard list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto arraystack = new ML::ArrayStack<int>();
	
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
