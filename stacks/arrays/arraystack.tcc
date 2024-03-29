
#include <cstdio>
#include <stdlib.h>

namespace ML {
	template <typename T>
	ArrayStack<T>::ArrayStack() {
		_size = 4;
		_inner = (T*) malloc(sizeof(T)*_size);
		_cur = 0;
	}

	template <typename T>
	ArrayStack<T>::ArrayStack(T val) {
		_size = 4;
		_inner = (T*) malloc(sizeof(T)*_size);

		_inner[0] = val;
		_cur = 1;
	}

	template <typename T>
	ArrayStack<T>* ArrayStack<T>::clear() {
		_cur = 0;
	}

	template <typename T>
	T ArrayStack<T>::top() {
		if(_cur > 0) {
			return _inner[_cur];
		}
	}

	template <typename T>
	T ArrayStack<T>::pop() {
		_cur -= 1;
		return _inner[_cur + 1];
	}

	template <typename T>
	ArrayStack<T>* ArrayStack<T>::push(T val) {
		T* temp;

		if(_cur + 1 == _size) {
			_size *= 2;
			temp = (T*) realloc(_inner, sizeof(T)*_size);

			if(temp != nullptr) {
				_inner = temp;
			} else {
				free(_inner);
				puts("Error reallocating memory");
				exit(1);
			}
		}

		_cur += 1;
		_inner[_cur] = val;
		return this;	
	}

	template <typename T>
	bool ArrayStack<T>::empty() {
		return _cur <= 0;
	}
}
