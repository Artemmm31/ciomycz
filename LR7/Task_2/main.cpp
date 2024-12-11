#include <iostream>
#include <string>
#include <limits>
#include "header.h"

int main() {
    std::cout << "В данном задании необходимо было найти сумму 2 чисел в доп коде и вывести в прямом\n"
              << "Выполнил Джигеро Артем\n"
              << "Вариант 7\n";
    while (true) {
        input();
        std::string num1, num2;
        num1 = checkkk("Введите число: ");
        num2 = checkkk("Введите 2 число: ");
        std::string add1 = ntd(num1);
        std::string add2 = ntd(num2);
        std::string summ = sum(add1, add2);    
        print(add1, add2, summ);
        std::cout << "Сумма в прямом коде: " << summ << std::endl;
    }
    return 0;
}

