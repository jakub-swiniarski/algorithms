// sieve of eratosthenes

#include <cmath>
#include <iostream>
#include <vector>

using ull = unsigned long long;

std::vector<ull> sieve(ull n) {
    std::vector<bool> is_prime(n + 1, true);
    std::vector<ull> primes;

    is_prime[0] = is_prime[1] = false;
    ull limit = std::sqrt(n);

    for (ull i = 2; i <= limit + 1; i++) {
        if (!is_prime[i])
            continue;
        for (ull j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }

    for (ull i = 0; i <= n; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }

    return primes;
}

int main(void) {
    ull n;
    std::cout << "Enter the limit: ";
    std::cin >> n;

    for (auto i : sieve(n))
        std::cout << i << '\n';

    return 0;
}
