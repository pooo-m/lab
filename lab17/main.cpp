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
	int c = 1;
	int d = 2;
	int e = 3;
	try {
		a.enque(c);
		a.enque(d);
		a.enque(e);
	}
	catch (bad_alloc& e) { cerr << e.what();}
	queue<int> b;
	try {
		b.enque(e);
		b.enque(d);
		b.enque(c);
	}
	catch (bad_alloc& e) { cerr << e.what(); }
	a = b;
	cout << a << "\n\n";
	a.deque();
	cout << a;
	try {
		b.deque();
		b.deque();
		b.deque();
		b.deque();
	}
	catch (out_of_range& e) { cerr << e.what(); }
	cout <<"\n\n" <<  b <<"\n\n" << b.getSize();
	return 0;
}