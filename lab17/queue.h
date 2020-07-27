#ifndef QUEUE
#define QUEUE
#include <iostream>
using namespace std;

template <class T> class queue {
	struct node {
		T value;
		node* next;
	};
	node* tmp;
	node* head;
	node* last;
	int size;
public:
	queue() {
		head = last = tmp = NULL;
		size = 0;
	}

	queue(queue<T>& obj);
	~queue();
	void enque(T obj);
	T deque();
	int getSize() { return size; };
	void clear() { size = 0; }
	queue<T>& operator = (queue<T>& obj);
	template <class T> friend ostream& operator << (ostream& os, queue<T>& obj);
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
