#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\chich\source\repos\Project6\Source.cpp"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
    TEST_CLASS(UnitTest3)
    {
    public:

        TEST_METHOD(accuracy_test)
        {
            srand(0);
            double result = monte_carlo(3, 6, 1000000);
            Assert::AreEqual(27.0, result, 0.5);
        }

        TEST_METHOD(test_small_number_of_points)
        {
            srand(0);
            double result = monte_carlo(3, 6, 10);
            Assert::IsTrue(result > 0);
        }

        TEST_METHOD(equal_test)
        {
            srand(42);
            double r1 = monte_carlo(3, 6, 10000);

            srand(42);
            double r2 = monte_carlo(3, 6, 10000);

            Assert::AreEqual(r1, r2);
        }
        TEST_METHOD(accuracy_with_more_points)
        {
            srand(0);
            double r1 = monte_carlo(3, 6, 1000);
            double r2 = monte_carlo(3, 6, 100000);

            double exact = 27.0;

            Assert::IsTrue(abs(r2 - exact) < abs(r1 - exact));
        }

    };
}