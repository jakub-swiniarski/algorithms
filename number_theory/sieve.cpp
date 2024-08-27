// sieve of eratosthenes

#include <cmath>
#include <iostream>

using ull = unsigned long long;

int main(void) {
    ull n;
    std::cout << "Enter the limit: ";
    std::cin >> n;

    bool is_prime[n + 1];
    std::fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    ull limit = std::sqrt(n);
    for (int i = 2; i <= limit + 1; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }

    for (int i = 0; i <= n; i++) {
        if (is_prime[i])
            std::cout << i << '\n';
    }

    return 0;
}
