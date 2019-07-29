
#ifndef ML_LIST_POINTER
#define ML_LIST_POINTER

#include <iostream>

namespace ML {
	template <typename T>
	class PointerList {
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
			PointerList(T val);

			/* FIRST */
			T first();

			/* END */
			T end();

			/* RETRIEVE */
			T get(int pos);

			/* INSERT */
			PointerList<T>* insert(T val, int pos);

			/* LOCATE */
			int find(T val);

			/* DELETE */
			PointerList<T>* remove(int pos);

			/* NEXT */
			T next(int pos);

			/* PREVIOUS */
			T prev(int pos);

			/* MAKENULL */
			PointerList<T>* clear();

			PointerList<T>* add(T val);

			/* PRINTLIST */
			void print();
		private:
			Node* _head;
	};
}

#include "pointerlist.tcc"

#endif
