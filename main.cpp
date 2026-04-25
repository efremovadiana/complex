#include <iostream>
#include "complex.h"
#include "clocale"

int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");

    int passed = 0;
    int failed = 0;

    // Тест конструкторов
    std::cout << "\nТест конструкторов:" << std::endl;

    complex c1;
    if (c1.getRe() == 0 && c1.getIm() == 0) {
        std::cout << "c1 = complex() - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "c1 = complex() - Неверно" << std::endl;
        failed++;
    }

    complex c2(5.0);
    if (c2.getRe() == 5.0 && c2.getIm() == 0) {
        std::cout << "c2 = complex(5.0) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "c2 = complex(5.0) - Неверно" << std::endl;
        failed++;
    }

    complex c3(2.0, 3.0);
    if (c3.getRe() == 2.0 && c3.getIm() == 3.0) {
        std::cout << "c3 = complex(2.0, 3.0) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "c3 = complex(2.0, 3.0) - Неверно" << std::endl;
        failed++;
    }

    // Тест сопряженных
    std::cout << "\nТест сопряжённых:" << std::endl;
    complex c4(3.0, 4.0);
    complex c4_conj = c4.conj();
    if (c4_conj.getRe() == 3.0 && c4_conj.getIm() == -4.0) {
        std::cout << "сопряжённое к (3+4i) = 3-4i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "сопряжённое (3+4i) - Неверно" << std::endl;
        failed++;
    }

    // Тест abs
    std::cout << "\nТест abs:" << std::endl;
    complex c5(3.0, 4.0);
    double mod = c5.abs();
    if (mod == 5.0) {
        std::cout << "abs(3+4i) = 5 - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "abs(3+4i) - Неверно, получили " << mod << std::endl;
        failed++;
    }

    // Тест арифметики complex + complex
    std::cout << "\nТест арифметики:" << std::endl;
    complex a(2.0, 3.0);
    complex b(1.0, -2.0);

    complex sum = a + b;
    if (sum.getRe() == 3.0 && sum.getIm() == 1.0) {
        std::cout << "(2+3i) + (1-2i) = 3+i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(2+3i) + (1-2i) - Неверно" << std::endl;
        failed++;
    }

    complex diff = a - b;
    if (diff.getRe() == 1.0 && diff.getIm() == 5.0) {
        std::cout << "(2+3i) - (1-2i) = 1+5i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(2+3i) - (1-2i) - Неверно" << std::endl;
        failed++;
    }

    complex mult = a * b;
    if (mult.getRe() == 8.0 && mult.getIm() == -1.0) {
        std::cout << "(2+3i) * (1-2i) = 8-i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(2+3i) * (1-2i) - Неверно" << std::endl;
        failed++;
    }

    // Тест с double
    std::cout << "\nТест с double:" << std::endl;
    complex d(5.0, 3.0);

    complex d_sum = d + 2.0;
    if (d_sum.getRe() == 7.0 && d_sum.getIm() == 3.0) {
        std::cout << "(5+3i) + 2 = 7+3i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(5+3i) + 2 - Неверно" << std::endl;
        failed++;
    }

    // Тест -= с double
    std::cout << "\nТест operator -= double:" << std::endl;
    complex test1(10.0, 5.0);
    test1 -= 3.0;
    if (test1.getRe() == 7.0 && test1.getIm() == 5.0) {
        std::cout << "(10+5i) -= 3 -> (7+5i) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(10+5i) -= 3 - Неверно" << std::endl;
        std::cout << "Ожидали (7, 5), получили (" << test1.getRe() << ", " << test1.getIm() << ")" << std::endl;
        failed++;
    }

    // Тест += с double
    complex test2(4.0, 2.0);
    test2 += 1.0;
    if (test2.getRe() == 5.0 && test2.getIm() == 2.0) {
        std::cout << "(4+2i) += 1 -> (5+2i) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(4+2i) += 1 - Неверно" << std::endl;
        failed++;
    }

    // Тест *= с double
    complex test3(3.0, 2.0);
    test3 *= 2.0;
    if (test3.getRe() == 6.0 && test3.getIm() == 4.0) {
        std::cout << "(3+2i) *= 2 -> (6+4i) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(3+2i) *= 2 - Неверно" << std::endl;
        failed++;
    }

    // Тест /= с double
    complex test4(10.0, 6.0);
    test4 /= 2.0;
    if (test4.getRe() == 5.0 && test4.getIm() == 3.0) {
        std::cout << "(10+6i) /= 2 -> (5+3i) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "(10+6i) /= 2 - Неверно" << std::endl;
        failed++;
    }

    // Тест унарного минуса
    std::cout << "\nТест унарного минуса:" << std::endl;
    complex e(5.0, -3.0);
    complex minus_e = -e;
    if (minus_e.getRe() == -5.0 && minus_e.getIm() == 3.0) {
        std::cout << "-(5-3i) = -5+3i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "-(5-3i) - Неверно" << std::endl;
        failed++;
    }

    // Вывод результатов
    std::cout << "\n Результаты" << std::endl;
    std::cout << "Пройдено: " << passed << std::endl;
    std::cout << "Не пройдено: " << failed << std::endl;

    if (failed == 0) {
        std::cout << "\nВсе тесты пройдены" << std::endl;
        return 0;
    } else {
        std::cout << "\nЕсть ошибки" << std::endl;
        return 1;
    }
}
