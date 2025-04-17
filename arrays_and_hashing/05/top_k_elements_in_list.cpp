#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count_nums;
            vector<vector<int>> freq(nums.size() + 1);

            // hashmapにする（{4: 1, 5: 2, 6: 4, 7: 1}みたいな）
            for (auto num : nums){
                if (count_nums.find(num) != count_nums.end())
                    count_nums[num]++;
                else
                    count_nums[num] = 1;
            }

            // 出現頻度別のarrayにする（{{4, 7}, {5}, {}, {6},...}みたいな）
            for (auto count_num : count_nums){
                freq[count_num.second].push_back(count_num.first);
            }

            // freq.size()が可能性のある最大の頻度で、そこからk番目に到達するまで下がっていく
            vector<int> result = {};
            int i = 0;
            int current = freq.size() - 1;
            while (i < k) {
                if (freq[current].empty()){
                    current--;
                    continue;
                } 
                for (int x : freq[current]){
                    if (i >= k)
                        break;
                    result.push_back(x);
                    i++;
                }
                current--;
            }

            return result;
        }
    };

    
int main(){
    Solution sol;
    vector<int> nums = { 4, 5, 5, 6, 6, 6, 6, 7 };
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);
    for (auto item : result)
        cout << item << " ";
}
