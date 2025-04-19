#include <iostream>
using namespace std;

bool is_alphanumeric(char c){
  return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
}

bool is_uppercase(char c){
  return (c >= 'A' && c <= 'Z');
}

class Solution {
public:
    bool isPalindrome(string s) {
        int k = 0;
        int l = s.size() - 1;
        while (k < l){
          while (!is_alphanumeric(s[k]) && k < l)
              k++;
          while (!is_alphanumeric(s[l]) && k < l)
              l--;
          if (is_uppercase(s[k]))
              s[k] -= 'A' - 'a';
          if (is_uppercase(s[l]))
              s[l] -= 'A' - 'a';

          // ポインターを両端からスライドさせて真ん中でやめるだけ
          if (s[k] != s[l])
              return false;
          k++;
          l--;
        }
        return true;
    }
};

int main(){
    Solution sol;

    string s = "Was it a car or a cat I saw?";
    // string s = "0P";
    bool result = sol.isPalindrome(s);
    cout << result;
}