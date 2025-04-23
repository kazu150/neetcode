#include <stack>
#include <iostream>

class MinStack {
    public:
        std::stack<int> stk;
        std::stack<int> min_stk;

        MinStack() {
        }
        
        // TOP要素を挿入する
        void push(int val) {
            if (min_stk.empty() || min_stk.top() >= val)
                min_stk.push(val);
            stk.push(val);
        }
        
        // TOP要素を削除する
        void pop() {
            if (!min_stk.empty() && min_stk.top() == stk.top())
                min_stk.pop();
            stk.pop();
        }
        
        // TOP要素にアクセスする
        int top() {
            return stk.top();
        }

        // 今回通常stackに追加で求められている機能
        int getMin() {
            return min_stk.empty() ? 0 : min_stk.top();
        }
    };

int main() {
    MinStack ms;

    ms.push(-2);
    ms.push(-2);
    ms.push(-3);
    ms.push(-3);
    std::cout << ms.getMin();
    ms.pop();
    std::cout << ms.getMin();
}