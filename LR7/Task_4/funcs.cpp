#include "header.h"
//O((n/p) * logn)
bool isDivisible(int n, int p) {
    int r = n;
    while (r >= p) { //O(n/p)
        int s = p;
        while ((s << 1) <= r) { //O(logn)
            s <<= 1;  
        }
        r -= s; 
    }
    return r == 0;
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