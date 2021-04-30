#include <iostream>
#include "ZFraction.hpp"
using namespace std;

int main()
{
    ZFraction a(1, 1);
    ZFraction b(2, 1);
    ZFraction c;
    c = b + b - a * b;
    cout << c;
    

    return 0;
}