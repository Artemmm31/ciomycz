#include <iostream>
#include "header.h"
int main() {
    while(true) {
        std::cout << "В данном задании необходимо было проверить делимости числа на 3, 79, 151 не используя умножение, деление и остаток от деления"
                  << "Выполнил Джигеро Артем"
                  << "Вариант 7";
        input();
        long double num = check("Введите число: ");
        const int num1 = 3;
        const int num2 = 79;
        const int num3 = 151;
        num = (num < 0) ? -num : num;
        std::cout << "На " << num1 << ": " << (isDivisible(num, num1) ? "Да" : "Нет") << '\n';
        std::cout << "На " << num2 << ": " << (isDivisible(num, num2) ? "Да" : "Нет") << '\n';
        std::cout << "На " << num3 << ": " << (isDivisible(num, num3) ? "Да" : "Нет") << '\n';
    }
    return 0;
}