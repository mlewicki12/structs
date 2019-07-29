
#ifndef ML_STACK_ARRAY
#define ML_STACK_ARRAY

namespace ML {
	template <typename T>
	class Stack {
		private:
			T* _inner;
			int _size;
			int _cur;

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
