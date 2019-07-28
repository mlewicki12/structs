
#ifndef ML_LIST_POINTER
#define ML_LIST_POINTER

#include <iostream>

namespace ML {
	template <typename T>
	class List {
		private:
			class Node {
				public:
					Node(T val);
					T visit();
					Node* next();
					Node* next(Node* val);
					Node* next(T val);
				private:
					T _data;
					Node* _next;
			};

		public:
			List(T val);

			/* FIRST */
			T first();

			/* END */
			T end();

			/* RETRIEVE */
			T get(int pos);

			/* INSERT */
			List<T>* insert(T val, int pos);

			/* LOCATE */
			int find(T val);

			/* DELETE */
			List<T>* remove(int pos);

			/* NEXT */
			T next(int pos);

			/* PREVIOUS */
			T prev(int pos);

			/* MAKENULL */
			List<T>* clear();

			List<T>* add(T val);

			/* PRINTLIST */
			void print();
		private:
			Node* _head;
	};
}

#include "list.tcc"

#endif
