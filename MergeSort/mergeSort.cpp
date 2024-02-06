#include "mergeSort.h"
#include <iostream>

void MergeSort::Sort(std::vector<int>& vec) {
    int size = vec.size();

    if (size > 1){
        while(CheckSorted(vec)!=true){
            int mid = size / 2;
            std::vector<int> left(vec.begin(), vec.begin()+mid);
            std::vector<int> right(vec.begin()+mid, vec.end());

            Sort(left);
            Sort(right);

            Merge(vec,left,right);
        }

    }
}

bool MergeSort::CheckSorted(const std::vector<int>&vec){
    int size = vec.size();
    for (int i = 1; i < size; ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true;
}

void MergeSort::Merge(std::vector<int>& vec, const std::vector<int>& left, const std::vector<int>& right) {
    int i = 0, j = 0, k = 0;
    int leftSize = left.size();
    int rightSize = right.size();

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        } else {
            vec[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        vec[k++] = left[i++];
    }

    while (j < rightSize) {
        vec[k++] = right[j++];
    }
}
