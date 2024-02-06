#include <vector>

class MergeSort {
public:
    static void Sort(std::vector<int>& vec);
    static bool CheckSorted(const std::vector<int>& vec);
private:
    static void Merge(std::vector<int>& vec, const std::vector<int>& left, const std::vector<int>& right);
};