
#include <iostream>
#include "arraystack.hpp"

int main() {
	auto stack = new ML::ArrayStack<int>(5);

	stack->push(7)->push(10);
	std::cout << stack->pop() << "\n";

	std::cout << stack->top() << "\n";

	std::cout << stack->empty() << "\n";
		stack->clear();
	std::cout << stack->empty() << "\n";
}
