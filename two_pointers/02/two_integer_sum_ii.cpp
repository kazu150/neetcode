#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int k = 0;
        int l = numbers.size() - 1;
        while (1) {
            if (numbers[k] + numbers[l] == target)
                break;
            else if (numbers[k] + numbers[l] < target)
                k++;
            else
                l--;
        }

        vector<int> result = { k + 1, l + 1 };
        return result;
    }
};

int main() {
    Solution sol;

    int target = 5;
    vector<int> numbers = {1, 2, 4, 5};
    vector<int> result = sol.twoSum(numbers, target);

    cout << result[0] << " " << result[1];
}