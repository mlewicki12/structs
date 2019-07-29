
#include <stdio.h>
#include <stdlib.h>

namespace ML {
	template <typename T>
	ArrayList<T>::ArrayList(int size) {
		_size = size;

		if(size <= 0) {
			_size = 1;
		}

		_inner = (T*) malloc(sizeof(T)*_size);
		_cur = 0;
	}

	template <typename T>
	ArrayList<T>::ArrayList(int size, T* vals) {
		_size = size;

		if(size <= 0) {
			_size = 1;
		}

		_inner = (T*) malloc(sizeof(T)*_size);
		for(int i = 0; i < size; ++i) {
			_inner[i] = vals[i];
		}

		_cur = size;
	}

	template <typename T>
	T ArrayList<T>::first() {
		return _inner[0];
	}

	template <typename T>
	ArrayList<T>* ArrayList<T>::add(T val) {
		if(_cur == _size) {
			T* newInner;
			_size *= 2;
			newInner = (T*) realloc(_inner, sizeof(T) * _size);

			if(newInner != nullptr) {
				_inner = newInner;
			} else {
				free(_inner);
				puts("Error reallocating memory");
				exit (1);
			}
			
		}

		_inner[_cur] = val;
		_cur += 1;

		return this;
	}

	template <typename T>
	T ArrayList<T>::get(int pos) {
		if(pos < _size) {
			return _inner[pos];
		}
	}

	template <typename T>
	ArrayList<T>* ArrayList<T>::insert(T val, int pos) {
		if(_cur + 1 == _size) {
			T* newInner;
			_size *= 2;
			newInner = (T*) realloc(_inner, sizeof(T) * _size);

			if(newInner != nullptr) {
				_inner = newInner;
			} else {
				free(_inner);
				puts("Error reallocation memory");
				exit(1);
			}
		}

		for(int i = _cur; i > pos; --i) {
			_inner[i] = _inner[i-1];
		}
		
		_inner[pos] = val;
		_cur += 1;
		return this;
	}

	template <typename T>
	int ArrayList<T>::find(T val) {
		for(int i = 0; i < _cur; ++i) {
			if(val == _inner[i]) {
				return i;
			}
		}

		return -1;
	}

	template <typename T>
	void ArrayList<T>::print() {
		for(int i = 0; i < _cur; ++i) {
			std::cout << _inner[i] << " ";
		}

		std::cout << "\n";
	}

	template <typename T>
	void ArrayList<T>::remove(int pos) {
		for(int i = pos; i < _cur - 1; ++i) {
			_inner[i] = _inner[i + 1];
		}

		_cur -= 1;
	}

	template <typename T>
	T ArrayList<T>::next(int pos) {
		if(pos < _cur) {
			return _inner[pos + 1];
		}

		return -1;
	}

	template <typename T>
	T ArrayList<T>::prev(int pos) {
		if(pos < _cur && pos != 0) {
			return _inner[pos - 1];
		}

		return -1;
	}

	template <typename T>
	ArrayList<T>* ArrayList<T>::clear() {
		_cur = 0;
		return this;
	}
}
