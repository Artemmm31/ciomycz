#include "header.h"
// O(base * n) n - kol-vo simvolov v kazdom alph
std::string* genalpha(long long base, long long& size) {
    size = base;
    std::string* alph = new std::string[base];
    for (long long i = 0; i < base; ++i) {
        if (i < 10) {
            alph[i] = std::string(1, '0' + i);
        } else {
            long long val = i - 10;
            std::string sym;
            while (val >= 0) {
                sym = char('A' + val % 26) + sym;
                val = val / 26 - 1;
            }
            alph[i] = sym;
        }
    }
    return alph;
}

//O(n) n - razmer alph
long long stv(const std::string& sym, std::string* alph, long long size) {
    for (long long i = 0; i < size; ++i) {
        if (alph[i] == sym) {
            return i;
        }
    }
    return -1;
}

std::string vts(long long val, std::string* alph, long long size) {
    if (val < 0 || val >= size) {
        return "";
    }
    return alph[val];
}

//O(maxLen * n), n - razmer alph
std::string an(const std::string& n1, const std::string& n2, std::string* alph, long long size) {
    long long base = size;
    std::string res;
    long long carry = 0;
    unsigned long long len1 = n1.size(), len2 = n2.size();
    unsigned long long maxLen = std::max(len1, len2);
    for (unsigned long long i = 0; i < maxLen || carry > 0; ++i) {
        long long val1 = i < len1 ? stv(std::string(1, n1[len1 - 1 - i]), alph, size) : 0;
        long long val2 = i < len2 ? stv(std::string(1, n2[len2 - 1 - i]), alph, size) : 0;

        if (val1 == -1 || val2 == -1) {
            return ""; 
        }
        long long sum = val1 + val2 + carry;
        std::string sym = vts(sum % base, alph, size);

        if (sym.empty()) return ""; 

        res = sym + res;
        carry = sum / base;
    }

    return res;
}

//O(len1 * n) n - razmer alph
std::string sn(const std::string& n1, const std::string& n2, std::string* alph, long long size) {
    long long base = size;
    std::string res;
    long long borrow = 0;

    unsigned long long len1 = n1.size(), len2 = n2.size();

    if (len1 < len2 || (len1 == len2 && n1 < n2)) {
        return "";
    }

    for (unsigned long long i = 0; i < len1; ++i) {
        long long val1 = stv(std::string(1, n1[len1 - 1 - i]), alph, size);
        long long val2 = i < len2 ? stv(std::string(1, n2[len2 - 1 - i]), alph, size) : 0;

        if (val1 == -1 || val2 == -1) {
            return "";
        }
        long long diff = val1 - val2 - borrow;

        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        std::string sym = vts(diff, alph, size);
        if (sym.empty()) {
            return "";
        }
        res = sym + res;
    }
    while (res.size() > 1 && res[0] == alph[0][0]) {
        res.erase(0, 1);
    }
    return res;
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
            if (!isdigit(c) && !(c >= 'A' && c <= 'Z')) {
                a = false;
                break;
            }
        }
        if (a) {
            break; 
        } else {
            std::cout << "Некорректный ввод! Введите строку, содержащую только цифры либо большие буквы английского алфавита.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return y;
}
