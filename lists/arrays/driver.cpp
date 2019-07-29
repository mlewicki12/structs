
#include <iostream>
#include <assert.h>

#include "arraylist.hpp"

int main() {
	int init[] = {5};
	auto list = new ML::ArrayList<int>(1, init);

	std::cout << "[TEST] ArrayList\n";
	std::cout << "\tArrayList.first()";
	
	assert(list->first() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.get()";

	assert(list->get(0) == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.add()";

	list->add(7);
	assert(list->get(1) == 7);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.insert()";

	list->insert(8, 1);
	assert(list->get(1) == 8);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.find()";

	assert(list->find(8) == 1);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.remove()";

	list->remove(1);
	assert(list->find(8) == -1);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.next()";

	list->add(2);
	assert(list->next(1) == 2);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayList.prev()";

	assert(list->prev(1) == 5);

	std::cout << "\t--PASSED\n\n";
}
