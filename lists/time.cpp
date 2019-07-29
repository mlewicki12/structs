
#include <iostream>
#include <list>
#include <ctime>

#include "arrays/arraylist.hpp"
#include "pointers/pointerlist.hpp"

int main() {
	auto arraylist = new ML::ArrayList<int>(8);
	clock_t start, stop;
	
	start = clock();
	for(int i = 0; i < 1024; ++i) {
		arraylist->add(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to an array based list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	auto pointerlist = new ML::PointerList<int>(8);
	
	start = clock();
	for(int i = 0; i < 1024; ++i) {
		pointerlist->add(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to a pointer based list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";

	std::list<int> stdlist = {8};

	start = clock();
	for(int i = 0; i < 1024; ++i) {
		stdlist.push_back(i);
	}
	stop = clock();

	std::cout << " -- Adding 1024 elements to standard list -- \n";
	std::cout << (1000*((double)stop-start)/CLOCKS_PER_SEC) << " milliseconds\n";
}
