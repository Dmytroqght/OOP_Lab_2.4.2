#include "pch.h"
#include "CppUnitTest.h"
// Вкажіть правильний шлях до заголовного файлу вашого класу
#include "../OOP_Lab_2.4.2/String.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringUnitTests
{
    TEST_CLASS(StringTests)
    {
    public:

        TEST_METHOD(TestConstructorAndLength)
        {
            String s("Test", 50);
            Assert::AreEqual(4, s.length());
            Assert::AreEqual(50, s.getSize());

            // Перевірка порожнього рядка
            String emptyStr(100);
            Assert::AreEqual(0, emptyStr.length());
        }

        TEST_METHOD(TestFindSubstring)
        {
            String s("Hello World", 50);
            String sub1("World");
            String sub2("C++");
            String sub3("H");

            // Індексація в класі починається з 1
            Assert::AreEqual(7, s.find(sub1));
            Assert::AreEqual(1, s.find(sub3));
            Assert::AreEqual(-1, s.find(sub2)); // Підрядок не знайдено
        }

        TEST_METHOD(TestRemoveSubstring)
        {
            String s("Visual Studio", 50);

            // Видаляємо " Studio" (7 символів, починаючи з 7-ї позиції)
            s.remove(7, 7);

            std::string result = (std::string)s;
            Assert::AreEqual(std::string("Visual"), result);
            Assert::AreEqual(6, s.length());
        }

        TEST_METHOD(TestRemoveOutOfBounds)
        {
            String s("Data", 50);
            // Спроба видалити більше символів, ніж є до кінця рядка
            s.remove(3, 10);

            std::string result = (std::string)s;
            Assert::AreEqual(std::string("Da"), result);
            Assert::AreEqual(2, s.length());
        }

        TEST_METHOD(TestInsertSubstring)
        {
            String s("C Programming", 50);
            String sub("++");

            // Вставляємо "++" після 'C' (індекс 2)
            s.insert(2, sub);

            std::string result = (std::string)s;
            Assert::AreEqual(std::string("C++ Programming"), result);
            Assert::AreEqual(15, s.length());
        }

        TEST_METHOD(TestConcatenation)
        {
            String s1("Object ", 50);
            String s2("Oriented", 50);

            String s3 = s1 + s2;

            std::string result = (std::string)s3;
            Assert::AreEqual(std::string("Object Oriented"), result);
            Assert::AreEqual(15, s3.length());
        }

        TEST_METHOD(TestSizeLimitTruncation)
        {
            // Створюємо рядок з максимальним розміром 5
            String s1("123", 5);
            String s2("45678");

            // Під час зчеплення результат має обрізатися до 5 символів
            String s3 = s1 + s2;

            std::string result = (std::string)s3;
            Assert::AreEqual(std::string("12345"), result);
            Assert::AreEqual(5, s3.length());
        }
    };
}