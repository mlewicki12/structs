
#include <iostream>
#include "list.hpp"

int main() {
	auto test = new ML::List<int>(5);
	std::cout << test->head()->visit() << "\n";

}
