class Solution {
public:
   int longestValidParentheses(string s) {
        stack<int> stk;     // Create a stack to keep track of indices
        stk.push(-1);       // Initialize the stack with -1 as a base index
        int ans = 0;        // Initialize the answer variable to store the maximum length

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                stk.push(i);  // Push the index of an opening parenthesis onto the stack
            else {
                if(stk.size() == 1)
                    stk.top() = i;  // If stack contains only the base index, update it to the current index
                else {
                    stk.pop();       // Pop the top index from the stack
                    ans = max(ans, i - stk.top());  // Calculate the current valid length and update the answer
                }
            }
        }
        return ans;   // Return the maximum valid length
    }

};