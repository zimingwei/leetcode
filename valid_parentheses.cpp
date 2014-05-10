class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool isValid(string s) {
        stack<char> S;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(s[i]);
            } else {
                if (S.empty()) {
                    return false;
                }
                char c = S.top();
                if ((c == '(' && s[i] == ')') || 
                    (c == '[' && s[i] == ']') ||
                    (c == '{' && s[i] == '}')) {
                    S.pop();
                } else {
                    return false;
                }
            }
        }
        return S.empty();
    }
};
