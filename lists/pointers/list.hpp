
#ifndef ML_LIST_POINTER
#define ML_LIST_POINTER

namespace ML {
	template <typename T>
	class List {
		private:
			class Node {
				public:
					Node(T val);
					T visit();
					T next();
					Node* next(Node* val);
					Node* next(T val);
				private:
					T _data;
					Node* _next;
			};

		public:
			List(T val);
			Node* head();
			Node* end();
			List<T>* add(Node* val);
			List<T>* add(T val);
		private:
			Node* _head;
	};
}

#include "list.tcc"

#endif
