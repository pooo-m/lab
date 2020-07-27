#ifdef QUEUE
template <class T>
inline queue<T> ::queue(queue& obj) {
	node* cur2 = obj.head;
	node* n = nullptr;
	try {
		n = new node;
	}
	catch (const bad_alloc& e) {
		throw bad_alloc(e);
	}

	n->value = cur2->value;
	n->next = NULL;
	head = n;
	last = n;
	size = 1;
	int i = obj.getSize();
	cur2 = cur2->next;
	while (size < i) {
		try {
			n = new node;
		}
		catch (const bad_alloc& e) {
			throw bad_alloc(e);
		}
		n->value = cur2->value;
		n->next = NULL;
		last->next = n;
		last = n;
		size++;
	}
};

template <class T>
inline queue<T>::~queue() {
	node* cur = head;
	node* prev = cur;
	while (cur) {
		cur = cur->next;
		delete prev;
		prev = cur;
	}
};

template<class T>
inline void queue<T> ::enque(T obj) {
	if (!size && !last) {
		node* n = nullptr;
		try {
			n = new node;
		}
		catch (const bad_alloc& e) {
			throw bad_alloc(e);
		}
		n->value = obj;
		n->next = NULL;
		head = n;
		last = n;
		size++;
		return;
	}
	if (!size && last) {
		head->value = obj;
		last = head;
		size++;
		return;
	}
	if (!(last->next)) {
		node* n = nullptr;
		try {
			n = new node;
		}
		catch (const bad_alloc& e) {
			throw bad_alloc(e);
		}
		n->value = obj;
		n->next = NULL;
		last->next = n;
		last = n;
		size++;
		return;
	}
	else
	{
		last->next->value = obj;
		last = last->next;
		size++;
		return;
	}
};

template <class T>
inline T queue<T> ::deque() {// добавить исключение
	if (!size) throw (std::out_of_range("we dont have elements"));
	node* cur = head;
	T val = cur->value;
	head = head->next;
	size--;
	delete cur;
	return val;
};

template <class T>
inline ostream& operator << (ostream& os, queue<T>& obj) {
	obj.tmp = obj.head;
	int i = 0;
	int n = obj.getSize();
	while (i < n) {
		os << obj.tmp->value << "\n";
		obj.tmp = obj.tmp->next;
		i++;
	}
	return os;
};

template <class T>
inline queue<T>& queue<T> :: operator = (queue<T>& obj) {
	if (this == &obj) return *this;
	if (size) {
		node* cur = head;
		node* prev = cur;
		while (cur) {
			cur = cur->next;
			delete prev;
			prev = cur;
		}
	}
	node* cur2 = obj.head;
	node* c = new node;
	c->value = cur2->value;
	c->next = NULL;
	head = c;
	last = c;
	size = 1;
	cur2 = cur2->next;
	int i = 1;
	while (i < obj.getSize()) {
		c = new node;
		c->value = cur2->value;
		c->next = NULL;
		last->next = c;
		last = c;
		size++;
		cur2 = cur2->next;
		i++;
	}
	return *this;
};

#endif 
