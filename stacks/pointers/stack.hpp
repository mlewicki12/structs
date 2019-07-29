
#ifndef ML_STACK_POINTER
#define ML_STACK_POINTER

namespace ML {
	template <typename T>
	class Stack {
		private:
			struct Node {
				T val;
				Node* prev;
			};

			Node* _top;

		public:
			Stack();
			Stack(T val);

			/* MAKENULL */
			Stack* clear();

			/* TOP */
			T top();

			/* POP */
			T pop();

			/* PUSH */
			Stack* push(T val);

			/* CLEAR */
			bool empty();
	};
}

#include "stack.tcc"

#endif
