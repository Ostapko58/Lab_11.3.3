#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.3.3/Lab_11.3.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student stud;
			Assert::AreEqual(BinSearch(stud, 3, "кос", Specialnists(2), 1, "example.bin")+1, 2);
		}
	};
}
