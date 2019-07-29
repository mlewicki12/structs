
#ifndef ML_LIST_ARRAY
#define ML_LIST_ARRAY

namespace ML {
	template <typename T>
	class List {
		private:
			T* _inner;
			int _size;
			int _cur;
		public:
			List(int size);
			List(int size, T* vals);
			
			int first();
			List<T>* add(T val);
			T get(int pos);
			List<T>* insert(T val, int pos);
			int find(T val);
			void print();
			void remove(int pos);
			T next(int pos);
			T prev(int pos);
			List<T>* clear();
	};
}

#include "list.tcc"

#endif
