#include <iostream>
#include "header.h"


int main() {
    while (true) {
        input();
        std::cout << "В данном задании необходимо было найти отравленную бочку из 240 вариантов используя 5 рабов за 48 часов(после начала действия яда раб умирал через 24 часа)\n"
                  << "Выполнил Джигеро Артем\n";
        bool barrels[240] = {false};
        bool slaves[5] = {false};
        int groops[31];
        feelgr(groops);
        int n = check("Введите номер бочки, которая будет отравлена: ");
        barrels[n - 1] = true;
        findgr(groops, slaves, barrels);
        int a = numgrbar(slaves);
        killedslaves(slaves);
        findbar(a, groops, slaves, barrels);
        int b = numgrbar(slaves) + groops[a] + 1;
        std::cout << "Отравленная бочка: " << b << '\n';
    }
    return 0;
}
