
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
	List<T>* List<T>::add(T val) {
		Node* _cur = end();
		_cur->next(val);

		return this;
	}
}
