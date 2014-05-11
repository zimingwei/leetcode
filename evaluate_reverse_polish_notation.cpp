class Solution {
private:
    bool isOperator(string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
public:
    // Time: O(n)
    // Space: O(n)
    int evalRPN(vector<string> &tokens) {
        stack<int> S;
        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int y = S.top();
                S.pop();
                int x = S.top();
                S.pop();
                if (tokens[i] == "+") {
                    x += y;
                } else if (tokens[i] == "-") {
                    x -= y;
                } else if (tokens[i] == "*") {
                    x *= y;
                } else if (tokens[i] == "/") {
                    x /= y;
                }
                S.push(x);
            } else {
                S.push(stoi(tokens[i]));
            }
        }
        return S.top();
    }
};
