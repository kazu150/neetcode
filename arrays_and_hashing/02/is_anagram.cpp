#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
      bool isAnagram(string s, string t) {
          unordered_map<int, int> hash;
          
          for (auto x : s){
            if (hash.find(x) == hash.end())
              hash[x] = 1;
            else
              hash[x]++;
          }

          for (auto x : t){
            if (hash[x] == 1){
              hash.erase(x);
            }
            else if (hash.find(x) != hash.end()){
              hash[x]--;
            } else {
              return false;
            }
          }

          if (hash.size() == 0)
            return true;
          else
            return false;
      }
};

int main(void){
  Solution sol;
  string s = "rcacear";
  string t = "carrace";

  bool res = sol.isAnagram(s, t);

  cout << res;
}