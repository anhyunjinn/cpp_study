#include <iostream>
#include <vector>
#include "mergeSort.h"

int main() {
    std::vector<int> vec = {12, 11, 13, 5, 6};
    
    std::cout << "Original Vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 머지 소트 적용
    MergeSort::Sort(vec);

    std::cout << "Sorted Vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
