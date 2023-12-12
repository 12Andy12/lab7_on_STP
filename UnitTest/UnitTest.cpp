#include "pch.h"
#include "CppUnitTest.h"
#include "../ModernCodingMemory/TMemory.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestWrite)
		{
			TMemory<int> memory;
			memory.write(5);
			int result = memory.read();
			int expected = 5;
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestAdd)
		{
			TMemory<int> memory;
			memory.add(5);
			int result = memory.read();
			int expected = 5;
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestClear)
		{
			TMemory<int> memory;
			memory.write(5);
			memory.clear();
			int result = memory.read();
			int expected = 0;
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestState)
		{
			TMemory<int> memory;
			std::string result = memory.getState();
			std::string expected = "Off";
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestState2)
		{
			TMemory<int> memory;
			memory.write(5);
			std::string result = memory.getState();
			std::string expected = "On";
			Assert::AreEqual(result, expected);
		}

		TEST_METHOD(TestState3)
		{
			TMemory<int> memory;
			memory.write(5);
			memory.clear();
			std::string result = memory.getState();
			std::string expected = "Off";
			Assert::AreEqual(result, expected);
		}
	};
}
