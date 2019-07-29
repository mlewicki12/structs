
#ifndef ML_STACK_ARRAY
#define ML_STACK_ARRAY

namespace ML {
	template <typename T>
	class ArrayStack {
		private:
			T* _inner;
			int _size;
			int _cur;

		public:
			ArrayStack();
			ArrayStack(T val);

			/* MAKENULL */
			ArrayStack* clear();

			/* TOP */
			T top();

			/* POP */
			T pop();

			/* PUSH */
			ArrayStack* push(T val);

			/* CLEAR */
			bool empty();
	};
}

#include "arraystack.tcc"

#endif
