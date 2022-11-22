#include "pch.h"
#include "CppUnitTest.h"
#include "../src/records.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCppDemo
{
	TEST_CLASS(UnitTestCppDemo)
	{
	public:

		TEST_METHOD(Test_get_num_grade)
		{
			StudentRecords sr;
            char grade = 'A';
			float result = 0.0f;

			switch (grade) {
			case 'A':
				result = sr.get_num_grade(*"A");
				Assert::IsTrue(4.0f == result);
				break;
			case 'B':
				result = sr.get_num_grade(*"B");
				Assert::IsTrue(3.0f == result);
				break;
			case 'C':
				result = sr.get_num_grade(*"C");
				Assert::IsTrue(1.0f == result);
				break;
			default:
				result = sr.get_num_grade(*"D");
				Assert::IsTrue(0.0f == result);
				break;
			}
		}

		TEST_METHOD(Test_get_course_name)
		{
			try {
				StudentRecords sr;
				int id = 1;
				string result = "";

				switch (id) {
				case 1:
					result = sr.get_course_name(1);
					printf("%s\n", result.c_str());
					Assert::IsTrue("Algebra" == result);
					break;
				case 2:
					result = sr.get_course_name(2);
					Assert::IsTrue("Physics" == result);
					break;

				case 3:
					result = sr.get_course_name(3);
					Assert::IsTrue("English" == result);
					break;

				default:
					result = sr.get_course_name(3);
					Assert::IsTrue("Algebra" == result);

					break;

				}



			}
			catch (exception& exc)
			{
				cout << "Exception has occurred!" << endl;
			}
	}


	};
}
