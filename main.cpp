#include <iostream>
#include <vector>
#include <algorithm>

class solution
{
  public:
    int hIndex(const std::vector<int> & citations) {
        std::vector<int> sorted = citations;    
        std::sort(sorted.begin(), sorted.end(), [](int i, int j){return i>j;});

        for (int i = 0; i < int(sorted.size()); i++) {
            if (sorted[i] > i)
                continue;
            else if (sorted[i] == i)
                return sorted[i];
            else
                return sorted[i-1];
        }
    }
};

int main()
{
    std::vector<int> nums{3,0,6,1,5};

    solution soln;
    int hindex = soln.hIndex(nums);

    std::cout << "The H-index is:\n";
    std::cout << hindex << std::endl;
}
