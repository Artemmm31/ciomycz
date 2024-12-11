#include "header.h"
#include <string>
#include <cmath>
#include <iostream>

// O(n), n - dlina num
std::string ntd(const std::string& num) {
    if (num == "0") return "0"; 
    bool neg = num[0] == '-';
    std::string bin = neg ? num.substr(1) : num;

    if (neg) {
        for (char& b : bin) {
            b = (b == '0') ? '1' : '0';
        }
        bool c = true;
        for (int i = bin.length() - 1; i >= 0 && c; --i) {
            if (bin[i] == '1') {
                bin[i] = '0';
            } else {
                bin[i] = '1';
                c = false;
            }
        }
        if (c) {
            bin = '1' + bin;
        }
    }
    return bin;
}

//O(n), n - max dlina n1 n2
std::string sum(const std::string& n1, const std::string& n2) {
    int m = std::max(n1.length(), n2.length()); 
    std::string p1 = std::string(m - n1.length(), '0') + n1;
    std::string p2 = std::string(m - n2.length(), '0') + n2; 

    std::string res(m + 1, '0'); 
    bool c = false; 
    for (int i = m - 1; i >= 0; --i) { 
        int b1 = p1[i] - '0';
        int b2 = p2[i] - '0'; 

        int s = b1 + b2 + c; 
        res[i + 1] = (s % 2) + '0'; 
        c = (s > 1);                
    }
    if (c) {
        res[0] = '1'; 
    } else {
        res = res.substr(1); 
    }

    return res;
}
void print(const std::string& a1, const std::string& a2, const std::string& s) {
    std::cout << "Дополнительный код первого числа: " << a1 << std::endl;
    std::cout << "Дополнительный код второго числа: " << a2 << std::endl;
    std::cout << "Сумма в дополнительном коде: " << s << std::endl;
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