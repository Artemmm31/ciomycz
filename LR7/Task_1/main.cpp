#include "header.h"

int main() {
    std::cout << "В данном задании необходимо было перевести число из доп кода в обратный\n"
              << "Выполнил Джигеро Артем\n"
              << "Вариант 7\n";
    while (true) {
        input();
        std::string in = checkkk("Введите число: ");
        std::cout << "Обратный код: " << abc(in) << '\n';
        return 0;
    }
}
