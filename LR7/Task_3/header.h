#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <iostream>

std::string* genalpha(long long base, long long& size);
long long stv(const std::string& sym, std::string* alph, long long size);
std::string vts(long long val, std::string* alph, long long size);
std::string an(const std::string& n1, const std::string& n2, std::string* alph, long long size);
std::string sn(const std::string& n1, const std::string& n2, std::string* alph, long long size);
long double check(const std::string& x);
int input();
std::string checkkk(const std::string& x);