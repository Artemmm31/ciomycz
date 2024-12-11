#include "header.h"
// O(n), n - dlina twc
std::string abc(const std::string& twc) {
    if (twc.empty()) return "";
    unsigned long long len = twc.size();
    char sign = twc[0];
    std::string oc = twc; 
    if (sign == '1') {
        for (int i = 1; i < len; ++i) {
            oc[i] = (twc[i] == '0') ? '1' : '0';
        }
    }
    return oc;
}
long double check(const std::string& x) {
    long double y;
    std::cout << x;
    while (true) {
        std::cin >> y;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Пожалуйста, следуйте инструкции и введите число и только число!" << "\n";
        }
        else {
            break;
        }
    }
    return y;
}
int input() {
    long double x;
    x = check("Введите: 1 - продолжить программу, 2 - завершить программу: ");
    if (x == 1) {
        return 1;
    }
    else if (x == 2) {
        exit(0);
    }
    else {
        std::cout << "Неверный ввод, давайте попробуем еще раз!\n";
        return input();
    }
}
//O(n), n - dlina x
std::string checkkk(const std::string& x) {
    std::string y;
    std::cout << x;
    while (true) {
        std::cin >> y;
        bool a = true;
        for (char c : y) {
            if (c != '0' && c != '1') {
                a = false;
                break;
            }
        }
        if (a) {
            break; 
        } else {
            std::cout << "Некорректный ввод! Введите строку, содержащую только 0 и 1.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return y;
}