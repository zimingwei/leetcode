class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int last = -1;
        stack<int> leftP;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftP.push(i);
            } else {
                if (leftP.empty()) {
                    last = i;
                } else {
                    leftP.pop();
                    if (leftP.empty()) {
                        maxLen = max(maxLen, i-last);
                    } else {
                        maxLen = max(maxLen, i-leftP.top());
                    }
                }
            }
        }
        return maxLen;
    }
};
