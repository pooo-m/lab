#ifdef QUEUE
#include <new>
#include <cstdlib>
template <class T>
inline queue<T> ::queue(queue& obj) {
	node<T>* cur2 = obj.head;
	node<T>* n = nullptr;
	n = new(nothrow)node<T>;
	if (!n) exit(EXIT_FAILURE);
	n->value = cur2->value;
	n->next = nullptr;
	head = n;
	tail = n;
	size = 1;
	int i = obj.getSize();
	cur2 = cur2->next;
	while (size < i) {
		n = new (nothrow) node<T>;
		if (!n) {
			delete this;
			exit(EXIT_FAILURE);
		}
		n->value = cur2->value;
		n->next = NULL;
		tail->next = n;
		tail = n;
		size++;
	}
};

template <class T>
inline queue<T>::~queue() {
	node<T>* cur = head;
	node<T>* prev = cur;
	while (cur) {
		cur = cur->next;
		delete prev;
		prev = cur;
	}
};

template<class T>
inline void queue<T> ::enque(T& obj) {
	if (size) {
		if (tail->next) {
			tail->next->value = obj;
			tail = tail->next;
		}
		else {
			node<T>* n;
			try {  n = new node<T>;
			}
			catch (const bad_alloc& e) {
				throw bad_alloc(e);
			}
			n->value = obj;
			n->next = nullptr;
			tail->next = n;
			tail = n;
		}
	}
	else {
		if (!head)  try {
			head = new node<T>;
		}
		catch (const bad_alloc& e) {
			throw bad_alloc(e);
		}
		head->value = obj;
		head->next = nullptr;
		tail = head;
	}
	size++;
};

template <class T>
inline T queue<T> ::deque() {// добавить исключение
	if (!size) throw (std::out_of_range("we dont have elements"));
	node<T>* cur = head;
	T val = cur->value;
	head = head->next;
	size--;
	delete cur;
	return val;
};

template <class T>
inline ostream& operator << (ostream& os, queue <T> const & obj) {
	node<T>* cur = obj.head;
	int i = 0;
	int n = obj.getSize();
	while (i < n) {
		os << cur->value << "\n";
		cur = cur->next;
		i++;
	}
	return os;
};

template <class T>
inline queue<T>& queue<T> :: operator = (const queue <T>& obj) {
	if (this == &obj) return *this;
	if (size) {
		node<T>* cur = head;
		node<T>* prev = cur;
		while (cur) {
			cur = cur->next;
			delete prev;
			prev = cur;
		}
	}
	node<T>* cur2 = obj.head;
	node<T>* c = new node<T>;
	c->value = cur2->value;
	c->next = nullptr;
	head = c;
	tail = c;
	size = 1;
	cur2 = cur2->next;
	int i = 1;
	while (i < obj.getSize()) {
		c = new node<T>;
		c->value = cur2->value;
		c->next = nullptr;
		tail->next = c;
		tail = c;
		size++;
		cur2 = cur2->next;
		i++;
	}
	return *this;
};

#endif 

