// fibonacci sequence

#include <iostream>

using ull = unsigned long long;

ull fib(ull n) {
    if (n < 2)
        return n;

    ull a = 0;
    ull b = 1;

    for (ull i = 2; i <= n; i++) {
        ull t = a;
        a = b;
        b = t + b;
    }

    return b;
}

int main(void) {
    ull n;
    std::cout << "Enter the position of the Fibonacci number you want to calculate: ";
    std::cin >> n;
    ull result = fib(n);
    std::cout << result << '\n';

    return 0;
}
