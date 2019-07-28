
#include <iostream>
#include "list.hpp"

int main() {
	auto test = new ML::List<int>(5);
	std::cout << test->head()->visit() << "\n";

	test->add(1)->add(4)->add(3);
	std::cout << test->get(1)->visit() << "\n";

	test->insert(10, 2);
	std::cout << test->get(2)->visit() << "\n";

	std::cout << test->find(4) << " " << test->find(15) << "\n";
	
	std::cout << "list 1: ";
		test->print();

	test->remove(2);

	std::cout << "list 2: ";
		test->print();

	std::cout << test->next(2)->visit() << "\n";
	std::cout << test->prev(2)->visit() << "\n";

	test->clear()->print();
}
