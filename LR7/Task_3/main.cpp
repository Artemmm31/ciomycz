#include <iostream>
#include "header.h"

int main() {
    std::cout << "В данной программе необходимо было осуществить сложение и вычитание 2 чисел в заданной системе счисления\n"
              << "Выполнил Джигеро Артем\n";
    while (true) {
        input();
        long double base = check("Введите основание системы счисления: ");
        if (base <= 0) {
            break;
        }
        long long size;
        std::string* alphabet = genalpha(base, size);
        std::string num1, num2;
        num1 = checkkk("Введите первое число: ");
        num2 = checkkk("Введите второе число: ");
        char a;
        std::cout << "Введите операцию (+ или -): ";
        std::cin >> a;

        if (a == '+') {
            std::string result = an(num1, num2, alphabet, size);
            if (result.empty()) {
                std::cout << "Ошибка при выполнении сложения.\n";
            } else {
                std::cout << "Результат: " << result << "\n";
            }
        } else if (a == '-') {
            std::string result = sn(num1, num2, alphabet, size);
            if (result.empty()) {
                std::cout << "Ошибка при выполнении вычитания.\n";
            } else {
                std::cout << "Результат: " << result << "\n";
            }
        } else {
            std::cout << "Неподдерживаемая операция.\n";
        }
        delete[] alphabet;
    }

    return 0;
}
