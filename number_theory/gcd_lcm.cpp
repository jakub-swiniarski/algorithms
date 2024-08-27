// greatest common divisor and least common multiple

#include <iostream>

using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b; // (a * b) / gcd(a, b), but i want to prevent overflow
}

int main(void) {
    ll a, b;
    std::cin >> a >> b;

    std::cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << '\n';
    std::cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << '\n';

    return 0;
}
