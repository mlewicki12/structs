
namespace ML {
	template <typename T>
	Stack<T>::Stack() {
		_top = nullptr;
	}

	template <typename T>
	Stack<T>::Stack(T val) {
		_top = new Node();
		_top->val = val;
	}

	template <typename T>
	Stack<T>* Stack<T>::clear() {
		Node* _temp;

		while(_top != nullptr) {
			_temp = _top->prev;
			delete _top;
			_top = _temp;
		}

		return this;
	}

	template <typename T>
	T Stack<T>::top() {
		if(_top != nullptr) {
			return _top->val;
		}
	}

	template <typename T>
	T Stack<T>::pop() {
		Node* _temp;

		if(_top != nullptr) {
			_temp = _top;
			_top = _top->prev;

			return _temp->val;
		}
	}

	template <typename T>
	Stack<T>* Stack<T>::push(T val) {
		Node* _temp;

		if(_top != nullptr) {
			_temp = new Node();
			_temp->val = val;
			_temp->prev = _top;

			_top = _temp;
		} else {
			_top = new Node();
			_top->val = val;
		}
	}

	template <typename T>
	bool Stack<T>::empty() {
		return _top == nullptr;
	}
}
