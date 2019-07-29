
#ifndef ML_LIST_ARRAY
#define ML_LIST_ARRAY

namespace ML {
	template <typename T>
	class ArrayList {
		private:
			T* _inner;
			int _size;
			int _cur;
		public:
			ArrayList(int size);
			ArrayList(int size, T* vals);
			
			T first();
			ArrayList<T>* add(T val);
			T get(int pos);
			ArrayList<T>* insert(T val, int pos);
			int find(T val);
			void print();
			void remove(int pos);
			T next(int pos);
			T prev(int pos);
			ArrayList<T>* clear();
	};
}

#include "arraylist.tcc"

#endif
