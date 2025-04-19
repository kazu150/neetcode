#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash;

        for (auto x : nums){
            if (hash.find(x) != hash.end())
                return true;
            else
                hash[x] = true;
        }
        return false;
    }
};

int main(void) {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    int result = sol.hasDuplicate(nums);

    // for (auto x : nums)
    //     cout << x << " ";
    // cout << endl;
    cout << result;

    return 0;
}
