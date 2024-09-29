// selection sort

#include <iostream>
#include <utility>
#include <vector>

std::vector<int> selection_sort(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int i_min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[i_min])
                i_min = j;
        }
        std::swap(v[i], v[i_min]);
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
    std::vector<int> v_sorted = selection_sort(v);
    for (const auto& i : v_sorted)
        std::cout << i << '\n';
    

    return 0;
}
