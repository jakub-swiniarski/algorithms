// bubble sort

#include <iostream>
#include <utility>
#include <vector>

std::vector<int> bubble_sort(std::vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    return v;
}

int main(void) {
    int n;
    std::cout << "How many numbers?\n";
    std::cin >> n;

    std::cout << "Enter the numbers.\n";
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    std::cout << "Sorted numbers:\n";
    std::vector<int> v_sorted = bubble_sort(v);
    for (const auto& i : v_sorted)
        std::cout << i << '\n';

    return 0;
}
