// bubble sort

#include <iostream>
#include <utility>
#include <vector>

std::vector<int> bubble_sort(const std::vector<int>& v) {
    std::vector<int> v_new = v;

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v_new[j] > v_new[j + 1])
                std::swap(v_new[j], v_new[j + 1]);
        }
    }

    return v_new;
}

int main(void) {
    int n;
    std::cout << "How many numbers?\n";
    std::cin >> n;

    std::cout << "Enter the numbers.\n";
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }

    std::cout << "Sorted numbers:\n";
    std::vector<int> v_sorted = bubble_sort(v);
    for (const auto& i : v_sorted)
        std::cout << i << '\n';

    return 0;
}
