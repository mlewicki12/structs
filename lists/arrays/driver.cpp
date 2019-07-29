
#include <iostream>
#include "list.hpp"

int main() {
	int init[] = {5, 4, 5};

	auto test = new ML::List<int>(3, init);
	std::cout << test->first() << "\n";

	test->add(1)->add(4)->add(3);
	std::cout << test->get(1) << "\n";

	test->insert(10, 2);
	std::cout << test->get(2) << "\n";

	std::cout << test->find(4) << " " << test->find(15) << "\n";
	
	std::cout << "list 1: ";
		test->print();

	test->remove(2);

	std::cout << "list 2: ";
		test->print();

	std::cout << test->next(2) << "\n";
	std::cout << test->prev(2) << "\n";

	test->clear()->print();
}
