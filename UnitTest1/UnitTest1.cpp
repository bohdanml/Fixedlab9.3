#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Fixedlab9.3\lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestSorting)
        {
            
            const int size = 3;
            Zodiac people[size] = {
                {"Andriy", "Kum", "Capricorn", {1, 15, 1990}},
                {"Petro", "Kum", "Leo", {5, 20, 1985}},
                {"Vasul", "Kum", "Aries", {3, 10, 2000}}
            };

            
            sortZodiacArray(people, size);

            
            Assert::AreEqual("Andriy", people[0].lastName.c_str());
            Assert::AreEqual("Petro", people[1].lastName.c_str());
            Assert::AreEqual("Vasul", people[2].lastName.c_str());
        }
    };
}