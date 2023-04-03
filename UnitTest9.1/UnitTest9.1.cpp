#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91
{
	TEST_CLASS(UnitTest91)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student students[3] = {
				{ "Aaaa", I, Kn, 1, 3, 4},
				{ "bbbb", I, Kn, 3, 2, 3},
				{ "cccc", I, Kn, 3, 3, 5}
			};
			int expected = 5;

			int actual = CountMarks(students, 3);

			Assert::AreEqual(expected, actual);
		}
	};
}
