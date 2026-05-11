#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\chich\source\repos\laba3tests\Source.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(mergeSort_standard)
		{
			std::vector<int> arr = { 5, 2, 9, 1, 5, 6 };
			std::vector<int> expected = { 1, 2, 5, 5, 6, 9 };
			mergeSort(arr);
			Assert::IsTrue(arr == expected);
		}
		TEST_METHOD(quickSort_reverse)
		{
			std::vector<int> arr = { 5, 4, 3, 2, 1 };
			std::vector<int> expected = { 1, 2, 3, 4, 5 };
			quickSort(arr, 0, arr.size() - 1);
			Assert::IsTrue(arr == expected);
		}
		TEST_METHOD(radixSort_odinakov)
		{
			std::vector<int> arr = { 10, 10, 10, 10 };
			std::vector<int> expected = { 10, 10, 10, 10 };
			radix_sort(arr);
			Assert::IsTrue(arr == expected);
		}

		TEST_METHOD(empty_arr)
		{
			std::vector<int> arr = {};
			mergeSort(arr);
			Assert::IsTrue(arr.empty());
			if (!arr.empty()) {
				quickSort(arr, 0, arr.size() - 1);
			}
			Assert::IsTrue(arr.empty());
		}
		TEST_METHOD(combine_carts_test)
		{
			std::vector<std::vector<int>> carts = { {1, 2}, {3}, {4, 5} };
			std::vector<int> expected = { 1, 2, 3, 4, 5 };
			std::vector<int> result = combine_carts(carts);
			Assert::IsTrue(result == expected);
		}
		TEST_METHOD(radixSort_largeNumbers)
		{
			std::vector<int> arr = { 1000, 5, 123, 9999, 0 };
			std::vector<int> expected = { 0, 5, 123, 1000, 9999 };
			radix_sort(arr);
			Assert::IsTrue(arr == expected);
		}
	};
}