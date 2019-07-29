
#include <iostream>
#include <assert.h>

#include "pointerstack.hpp"

int main() {
	auto stack = new ML::PointerStack<int>();

	std::cout << "[TEST] PointerStack\n";
	std::cout << "\tPointerStack.push(), PointerStack.top()";

	stack->push(5);
	assert(stack->top() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerStack.pop()";

	stack->push(7);
	assert(stack->pop() == 7);
	assert(stack->top() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerStack.empty()";
	assert(stack->empty() == 0);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tPointerStack.clear()";
	stack->clear();
	assert(stack->empty() == 1);
	std::cout << "\t--PASSED\n";
}
