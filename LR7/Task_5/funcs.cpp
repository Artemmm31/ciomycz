#include "header.h"
int countOnes(int x) {
    int bitCount = 0;
    while (x) {
        if (x & 1) {
            bitCount++;
        }
        x >>= 1;
    }
    return bitCount;
}

void feelgr(int divisions[]) { //создает группы бочек на основе битов
    divisions[0] = 0;
    divisions[1] = 32;

    for (int i = 1; i <= 29; ++i) {
        int bitCount = countOnes(i);
        int step = 0;

        if (bitCount == 1) step = 16;
        else if (bitCount == 2) step = 8;
        else if (bitCount == 3) step = 4;
        else if (bitCount == 4) step = 2;

        divisions[i + 1] = divisions[i] + step;
    }
}

void getOneBit(int x, int positions[], int& total) { //распределение рабов по группам для проверки
    total = 0;
    int idx = 0; 
    while (x > 0) {
        if (x & 1) {
            positions[total++] = idx;
        }
        x >>= 1;
        idx++;
    }
}

void findgr(const int divisions[], bool testers[], const bool containers[]) { //ищем в какой группе яд
    for (int i = 0; i < 29; ++i) {
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount);

        for (int j = 0; j < bitCount; ++j) {
            for (int k = divisions[i]; k < divisions[i + 1]; ++k) {
                if (!testers[bits[j]]) {
                    testers[bits[j]] = containers[k];
                }
            }
        }
    }
}

int numgrbar(const bool testers[]) { //двоичное число по состоянию рабов => понимаем в какой группе
    int index = 0;
    int multiplier = 1;
    for (int i = 0; i < 5; ++i) {
        index += testers[i] * multiplier;
        multiplier *= 2;
    }
    return index;
}

void killedslaves(bool testers[]) { //убираем мертвых
    for (int i = 0; i < 5; ++i) {
        testers[i] = false;
    }
}

void findbar(int index, const int divisions[], bool testers[], const bool containers[]) { //ищем бочку
    for (int k = divisions[index], i = 0; k < divisions[index + 1]; ++k, ++i) {
        int bits[5];
        int bitCount = 0;
        getOneBit(i, bits, bitCount);

        for (int j = 0; j < bitCount; ++j) {
            if (!testers[bits[j]]) {
                testers[bits[j]] = containers[k];
            }
        }
    }
}
int check(const std::string& x) {
    int y;
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
    int x;
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