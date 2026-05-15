#define _USE_MATH_DEFINES
#include <iostream>
#include "complex.h"
#include <cmath>
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
    std::cout << "\nТест оператор с double:" << std::endl;
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

    // Тест полярного конструктора
    std::cout << "\n Тест полярного конструктора" << std::endl;

    complex polar1(5.0, 0.0, true);
    if (std::abs(polar1.getRe() - 5.0) < 1e-9 && std::abs(polar1.getIm() - 0.0) < 1e-9) {
        std::cout << "Полярный (5, 0) = (5, 0) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "Полярный (5, 0) = (5, 0) - Неверно" << std::endl;
        failed++;
    }

    complex polar2(1.0, M_PI / 2, true);
    if (std::abs(polar2.getRe() - 0.0) < 1e-9 && std::abs(polar2.getIm() - 1.0) < 1e-9) {
        std::cout << "Полярный (1, pi/2) = (0, 1) - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "Полярный (1, pi/2) - Неверно" << std::endl;
        failed++;
    }

    // Тест метода arg()
    std::cout << "\n Тест arg() " << std::endl;

    complex arg1(1.0, 0.0);
    double a1 = arg1.arg();
    if (std::abs(a1 - 0.0) < 1e-9) {
        std::cout << "arg(1+0i) = 0 - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "arg(1+0i) = " << a1 << " - Неверно" << std::endl;
        failed++;
    }

    complex arg2(0.0, 1.0);
    double a2 = arg2.arg();
    if (std::abs(a2 - M_PI / 2) < 1e-9) {
        std::cout << "arg(0+1i) = pi/2 - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "arg(0+1i) = " << a2 << " - Неверно" << std::endl;
        failed++;
    }

    // Тест операторов с double слева
    std::cout << "\n Тест double + complex " << std::endl;

    complex left_test1 = 2.0 + complex(3.0, 4.0);
    if (left_test1.getRe() == 5.0 && left_test1.getIm() == 4.0) {
        std::cout << "2 + (3+4i) = 5+4i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "2 + (3+4i) - Неверно" << std::endl;
        failed++;
    }

    complex left_test2 = 2.0 * complex(3.0, 4.0);
    if (left_test2.getRe() == 6.0 && left_test2.getIm() == 8.0) {
        std::cout << "2 * (3+4i) = 6+8i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "2 * (3+4i) - Неверно" << std::endl;
        failed++;
    }

    // Тест деления complex / complex
    std::cout << "\n Тест complex / complex " << std::endl;

    complex div_test1(1.0, 0.0);
    complex div_test2(0.0, 1.0);
    complex div_result = div_test1 / div_test2;
    if (std::abs(div_result.getRe() - 0.0) < 1e-9 && std::abs(div_result.getIm() - (-1.0)) < 1e-9) {
        std::cout << "1 / i = -i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "1 / i = (" << div_result.getRe() << ", " << div_result.getIm() << ") - Неверно" << std::endl;
        failed++;
    }

    // Тест complex / double (проверка исправления ошибки)
    std::cout << "\n Тест complex / double (проверка исправления) " << std::endl;
    complex div_fix_test(6.0, 8.0);
    complex div_fix_result = div_fix_test / 2.0;
    if (div_fix_result.getRe() == 3.0 && div_fix_result.getIm() == 4.0) {
        std::cout << "(6+8i)/2 = 3+4i - Верно (ошибка исправлена)" << std::endl;
        passed++;
    } else {
        std::cout << "(6+8i)/2 = (" << div_fix_result.getRe() << ", "
                  << div_fix_result.getIm() << ") - Ошибка осталась! Неверно" << std::endl;
        failed++;
    }

    // Тест цепочки операций
    std::cout << "\n Тест цепочки операций " << std::endl;
    complex chain1(1.0, 1.0);
    complex chain2(2.0, 2.0);
    complex chain3(3.0, 3.0);
    complex chain_result = (chain1 + chain2) * chain3;
    if (std::abs(chain_result.getRe() - 0.0) < 1e-9 && std::abs(chain_result.getIm() - 18.0) < 1e-9) {
        std::cout << "((1+i)+(2+2i))*(3+3i) = 0+18i - Верно" << std::endl;
        passed++;
    } else {
        std::cout << "Цепочка операций - Неверно" << std::endl;
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
