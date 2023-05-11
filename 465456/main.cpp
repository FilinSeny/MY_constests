#include <iostream>

using namespace std;

void f(const char *, long long) {cout << 1;}
void f(int, short) {cout << 2;}

void f(int, int) {cout << 3;}

int main()
{
    f(0, 5L);
    return 0;
}
