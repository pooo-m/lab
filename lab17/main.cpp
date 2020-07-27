#include"queue.h" 
#include <iostream>
using namespace std;
int main() {
	/*Point a;
	a.x = 4;
	a.y = 5;
	a.z = 6;
	Point f;
	f.x = 77;
	f.y = 66;
	f.z = 55;
	Point m;
	m.x = 0;
	m.y = 1;
	m.z = 2;
	queue <Point> b;
	b.enque (a);
	b.enque(f);
	//cout << b;
	b.clear();
	b.enque(f);
	b.enque(a);
	b.enque(m);
	//cout << b << "\n";
	cout << b.getSize();
	queue <Point> c;
	c = b;
	cout <<"\n\n" << c;
	queue <Point> pr;
	try {
		pr.deque();
	}
	catch (out_of_range& e) { cerr << e.what(); }*/
	queue<int> a;
	a.enque(1);
	a.enque(2);
	a.enque(3);
	queue<int> b;
	b.enque(3);
	b.enque(2);
	b.enque(1);
	a = b;
	try {
		b.deque();
		b.deque();
		b.deque();
		b.deque();
	}
	catch (out_of_range& e) { cerr << e.what(); }
	cout << a;
	return 0;
}