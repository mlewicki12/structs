
#ifndef ML_STACK_POINTER
#define ML_STACK_POINTER

namespace ML {
	template <typename T>
	class PointerStack {
		private:
			struct Node {
				T val;
				Node* prev;
			};

			Node* _top;

		public:
			PointerStack();
			PointerStack(T val);

			/* MAKENULL */
			PointerStack* clear();

			/* TOP */
			T top();

			/* POP */
			T pop();

			/* PUSH */
			PointerStack* push(T val);

			/* CLEAR */
			bool empty();
	};
}

#include "pointerstack.tcc"

#endif
