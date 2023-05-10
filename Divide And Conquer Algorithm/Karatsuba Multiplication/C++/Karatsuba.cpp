#include <iostream>
#include <cmath>

using namespace std;

int numDigits(int n)
{
    return floor(log10(n)) + 1;
}

int karatsuba(int x, int y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }

    int n = max(numDigits(x), numDigits(y));
    int n2 = n / 2;

    int a = x / static_cast<int>(pow(10, n2));
    int b = x % static_cast<int>(pow(10, n2));
    int c = y / static_cast<int>(pow(10, n2));
    int d = y % static_cast<int>(pow(10, n2));

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

    int result = ac * static_cast<int>(pow(10, 2 * n2)) + (ad_plus_bc * static_cast<int>(pow(10, n2))) + bd;
    return result;
}

int main()
{
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    int result = karatsuba(x, y);
    cout << "Product: " << result << endl;

    return 0;
}
