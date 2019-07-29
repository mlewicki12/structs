
#include <iostream>
#include <assert.h>

#include "pointerlist.hpp"

int main() {
	auto list = new ML::PointerList<int>(5);

	std::cout << "[TEST] PointerList\n";
	std::cout << "\tPointerList.first()";
	
	assert(list->first() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.get()";

	assert(list->get(0) == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.add()";

	list->add(7);
	assert(list->get(1) == 7);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.insert()";

	list->insert(8, 1);
	assert(list->get(1) == 8);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.find()";

	assert(list->find(8) == 1);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.remove()";

	list->remove(1);
	assert(list->find(8) == -1);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.next()";

	list->add(2);
	assert(list->next(1) == 2);

	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerList.prev()";

	assert(list->prev(1) == 5);

	std::cout << "\t--PASSED\n\n";
}
