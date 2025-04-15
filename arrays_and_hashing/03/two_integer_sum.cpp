#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
      vector<int> twoSum(vector<int>& nums, int target) {
          unordered_map<int, int> hash;
          vector<int> res;

          for(int i = 0; i < nums.size(); ++i){
            hash[target - nums[i]] = i;
          }

          for(int i = 0; i < nums.size(); ++i){
              if (hash.find(nums[i]) != hash.end()){
                if (i == hash[nums[i]])
                  continue;
                res.push_back(i);
                res.push_back(hash[nums[i]]);
                break;
              }
          }
          return res;
      }
};
  

// nums = { 100, 101, 102 };
// target = 201;
// として、
// 201からその数引いて、hash{101 => 0, 100 => 1, 99 => 2}が作れる
// numsの値を１個ずつ適用していき、hashの中身と同じものを突き止める。
// nums内のindex, hashのkeyが答えとなるはず
// 計算量O(n)、空間計算量O(n)となるはず
int main()
{
  Solution sol;

  vector<int> nums = {4,5,6};
  vector<int> result = sol.twoSum(nums, 10);
  cout << result[0] << " ";
  cout << result[1] << endl;
}