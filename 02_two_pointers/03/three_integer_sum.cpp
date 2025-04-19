#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // 一旦ソートしちゃう
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;

            // 真ん中数値を移動させる。これがn回分
            for (int m = 1; m < nums.size() - 1; m++){
                int k = 0;
                int l = nums.size() - 1;

                // 両端の数字を移動させる。これもn回分
                while (k < m && m < l){
                    if (nums[k] + nums[l] == nums[m] * -1) {
                        // 微妙な対応だが、計算量的には問題ないはず
                        int is_duplicate = 0;
                        for (auto x : result){
                            if (
                                x[0] == nums[k] &&
                                x[1] == nums[m] &&
                                x[2] == nums[l]
                            ) is_duplicate = 1;
                        }
                        if (!is_duplicate)
                            result.push_back({ nums[k], nums[m], nums[l] });
                        l--;
                        k++;
                    } else if (nums[k] + nums[l] > nums[m] * -1)
                        l--;
                    else
                        k++;
                }
            }

            return result;
        }
    };

int main(){
    Solution sol;

    // vector<int> nums = { -1, 0, 1, 2, -1, -4 };
    // vector<int> nums = { 1, 1, 0, 0, 0, -1, -1 };
    // vector<int> nums = { 0, 0, 0, 0, 0, 0, 0 };
    // vector<int> nums = { 3, 0, -2, -1, 1, 2 };
    vector<int> nums = { -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4 };
    vector<vector<int>> result = sol.threeSum(nums);

    for (auto x : result){
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}