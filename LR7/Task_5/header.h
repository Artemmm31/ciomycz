#include <cstring>
#include <iostream>
#include <string>
#include <limits>
int countOnes(int n);
void feelgr(int groops[]);
void getOneBit(int n, int indices[], int& count);
void findgr(const int groops[], bool slaves[], const bool barrels[]);
int numgrbar(const bool slaves[]);
void killedslaves(bool slaves[]);
void findbar(int number, const int groops[], bool slaves[], const bool barrels[]);
int check(const std::string& x);
int input();