
namespace ML {
	template <typename T>
	PointerList<T>::Node::Node(T val) {
		_data = val;
		_next = nullptr;
	}

	template <typename T>
	T PointerList<T>::Node::visit() {
		return _data;
	}

	template <typename T>
	typename PointerList<T>::Node* PointerList<T>::Node::next() {
		return _next;
	}

	template <typename T>
	typename PointerList<T>::Node* PointerList<T>::Node::next(Node* val) {
		_next = val;
		return this;
	}

	template <typename T>
	typename PointerList<T>::Node* PointerList<T>::Node::next(T val) {
		_next = new Node(val);
		return this;
	}

	// --------- //

	template <typename T>
	PointerList<T>::PointerList(T val) {
		_head = new Node(val);
	}

	template <typename T>
	T PointerList<T>::first() {
		return _head->visit();
	}

	template <typename T>
	T PointerList<T>::end() {
		Node* _cur = _head;

		while(_cur->next() != nullptr) {
			_cur = _cur->next();
		}

		return _cur->visit();
	}

	template <typename T>
	T PointerList<T>::get(int pos) {
		Node* _cur = _head;

		while(_cur != nullptr && pos > 0) {
			_cur = _cur->next();
			pos -= 1;
		}

		if(_cur != nullptr) {
			return _cur->visit();
		}
	}

	template <typename T>
	PointerList<T>* PointerList<T>::insert(T val, int pos) {
		Node* _cur = _head;
		Node* temp;
		Node* add = new Node(val);

		while(_cur != nullptr && (pos - 1) > 0) {
			_cur = _cur->next();
			pos -= 1;
		}

		temp = _cur->next();
		_cur->next(add);
		add->next(temp);

		return this;
	}

	template <typename T>
	int PointerList<T>::find(T val) {
		Node* _cur = _head;
		int pos = 0;

		while(_cur != nullptr) {
			if(_cur->visit() == val) {
				break;
			}

			_cur = _cur->next();
			pos += 1;
		}

		if(_cur == nullptr) {
			return -1;
		}

		return pos;
	}

	template <typename T>
	PointerList<T>* PointerList<T>::remove(int pos) {
		Node* _cur = _head;
		Node* _prev;

		while(_cur != nullptr && pos > 0) {
			_prev = _cur;
			_cur = _cur->next();
			pos -= 1;			
		}

		if(_cur != nullptr) {
			_prev->next(_cur->next());
		}

		return this;
	}

	template <typename T>
	T PointerList<T>::next(int pos) {
		Node* _cur = _head;

		while(_cur != nullptr && pos > 0) {
			_cur = _cur->next();
			pos -= 1;
		}

		if(_cur != nullptr) {
			return _cur->next()->visit();
		}
	}

	template <typename T>
	T PointerList<T>::prev(int pos) {
		Node* _cur = _head;
		Node* _prev;

		while(_cur != nullptr && pos > 0) {
			_prev = _cur;
			_cur = _cur->next();
			pos -= 1;
		}

		if(pos != 0) {
			return -1;
		}

		return _prev->visit();
	}

	template <typename T>
	PointerList<T>* PointerList<T>::clear() {
		Node* _cur = _head;
		Node* _temp;

		while(_cur != nullptr) {
			_temp = _cur->next();
			delete _cur;

			_cur = _temp;
		}

		_head = nullptr;
		return this;
	}

	template <typename T>
	PointerList<T>* PointerList<T>::add(T val) {
		Node* _cur = _head;

		while(_cur->next() != nullptr) {
			_cur = _cur->next();
		}

		_cur->next(val);
		return this;
	}

	template <typename T>
	void PointerList<T>::print() {
		Node* _cur = _head;

		while(_cur != nullptr) {
			std::cout << _cur->visit() << " ";
			_cur = _cur->next();
		}

		std::cout << "\n";
	}
}
