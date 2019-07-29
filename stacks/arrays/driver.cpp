
#include <iostream>
#include <assert.h>

#include "arraystack.hpp"

int main() {
	auto stack = new ML::ArrayStack<int>();

	std::cout << "[TEST] ArrayStack\n";
	std::cout << "\tArrayStack.push(), ArrayStack.top()";

	stack->push(5);
	assert(stack->top() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayStack.pop()";

	stack->push(7);
	assert(stack->pop() == 7);
	assert(stack->top() == 5);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayStack.empty()";
	assert(stack->empty() == 0);
	std::cout << "\t--PASSED\n\n";

	std::cout << "\tArrayStack.clear()";
	stack->clear();
	assert(stack->empty() == 1);
	std::cout << "\t--PASSED\n";
}
