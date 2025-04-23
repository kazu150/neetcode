#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;
            unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
            
            for (char c : s) {
                if (pairs[c]) {
                    if (!stack.empty() && stack.top() == pairs[c])
                        stack.pop();
                    else
                        return false;
                } else {
                    // pairsに存在しない（＝閉じ括弧じゃない）ならstackに積む
                    stack.push(c);
                }
            }

            if (stack.empty())
                return true;
            else
                return false;
        }
    };

int main() {
    string s = "()[{}";

    Solution sol;
    cout << sol.isValid(s);

}