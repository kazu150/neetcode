#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> hash;

            // {}と書くだけで0初期化できる
            int alp_count[26] = {};

            string key;
            for (auto x : strs){
                key = "";
                for (int i = 0; i < 26; ++i)
                    alp_count[i] = 0;
                for (int i = 0; x[i]; i++)
                    alp_count[x[i] - 'a']++;
                    
                for (int i = 0; i < 26; i++){
                    if (alp_count[i] == 0)
                        continue;
                    key += (char)('a' + i);
                    key += (char)(alp_count[i] + '0');
                }
                hash[key].push_back(x);
            }

            vector<vector<string>> result = {};
            for (auto pair : hash)
                result.push_back(pair.second);
            return result;
        }
};

int main(){
  Solution sol;
  vector<string> strs = {"act","pots","tops","cat","stop","hat"};
  vector<vector<string>> result = sol.groupAnagrams(strs);

  for (int i = 0; i < result.size(); i++){
    for (int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }
}