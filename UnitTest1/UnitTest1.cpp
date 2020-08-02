#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab17\queue.h"
#include <stdlib.h>
#include <ctime>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test_Enque_Deque)
		{
			queue<int> a;
			int arr[10];
			srand(time(NULL));
			for (int i = 0; i < 10; i++) {
				arr[i] = rand() % 150;
				a.enque(arr[i]);
			}
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(a.deque(),arr[i]);
			}
			try {
				a.deque();
				Assert::IsFalse(true);
			}
			catch (...) {           
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestSize)
		{
			queue<int> a;
			int b = 1;
			int c = 2;
			int d = 3;
			a.enque(b);
			a.enque(c);
			a.enque(d);
			Assert::AreEqual(3, a.getSize());
		}
		TEST_METHOD(Test_)
		{
			queue<int> a;
			queue<int> b;
			srand(time(NULL));
			for (int i = 0; i < 10; i++) {
				int n = rand() % 150;
				a.enque(n);
			}
			b = a;
			for (int i = 0; i < 10; i++) 
				Assert::AreEqual(a.deque(), b.deque());
		}
	};
}
