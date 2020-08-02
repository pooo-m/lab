#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std;
template <class T>
struct node {
	T value;
	node* next;
};

template <class T> class queue {
	node<T>* head;
	node<T>* tail;
	size_t size;
public:
	queue() {
		head = tail = nullptr;
		size = 0;
	}

	queue(queue<T>& obj);
	~queue();
	void enque(T& obj);
	T deque();
	int getSize() const { return size; };
	void clear() { size = 0; }
	queue<T>& operator = (const queue<T>& obj);
	template <class T> friend ostream& operator << (ostream& os, queue<T> const & obj);
};
#include "queue.ipp"
#endif
/*struct Point {
	int x;
	int y;
	int z;
	friend ostream& operator << (ostream& out, Point obj) {
		out << "x= " << obj.x << ", y= " << obj.y << ", z = " << obj.z;
		return out;
	}
};*/
