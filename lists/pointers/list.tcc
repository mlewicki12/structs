
namespace ML {
	template <typename T>
	List<T>::Node::Node(T val) {
		_data = val;
		_next = nullptr;
	}

	template <typename T>
	T List<T>::Node::visit() {
		return _data;
	}

	template <typename T>
	typename List<T>::Node* List<T>::Node::next() {
		return _next;
	}

	template <typename T>
	typename List<T>::Node* List<T>::Node::next(Node* val) {
		_next = val;
		return this;
	}

	template <typename T>
	typename List<T>::Node* List<T>::Node::next(T val) {
		_next = new Node(val);
		return this;
	}

	// --------- //

	template <typename T>
	List<T>::List(T val) {
		_head = new Node(val);
	}

	template <typename T>
	typename List<T>::Node* List<T>::head() {
		return _head;
	}

	template <typename T>
	typename List<T>::Node* List<T>::end() {
		Node* _cur = _head;
		while(_cur->next() != nullptr) {
			_cur = _cur->next();
		}

		return _cur;
	}

	template <typename T>
	typename List<T>::Node* List<T>::get(int pos) {
		Node* _cur = _head;
		while(_cur != nullptr && pos > 0) {
			_cur = _cur->next();
			pos -= 1;
		}

		return _cur;
	}

	template <typename T>
	List<T>* List<T>::insert(T val, int pos) {
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
	int List<T>::find(T val) {
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
	List<T>* List<T>::remove(int pos) {
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
	typename List<T>::Node* List<T>::next(int pos) {
		Node* _cur = _head;

		while(_cur != nullptr && pos > 0) {
			_cur = _cur->next();
			pos -= 1;
		}

		if(_cur == nullptr) {
			return nullptr;
		}

		return _cur->next();
	}

	template <typename T>
	typename List<T>::Node* List<T>::prev(int pos) {
		Node* _cur = _head;
		Node* _prev;

		while(_cur != nullptr && pos > 0) {
			_prev = _cur;
			_cur = _cur->next();
			pos -= 1;
		}

		if(pos != 0) {
			return nullptr;
		}

		return _prev;
	}

	template <typename T>
	List<T>* List<T>::clear() {
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
	List<T>* List<T>::add(T val) {
		Node* _cur = end();
		_cur->next(val);

		return this;
	}

	template <typename T>
	void List<T>::print() {
		Node* _cur = _head;
		while(_cur != nullptr) {
			std::cout << _cur->visit() << " ";
			_cur = _cur->next();
		}

		std::cout << "\n";
	}
}
