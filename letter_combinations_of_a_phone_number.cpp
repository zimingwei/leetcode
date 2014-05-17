class Solution {
private:
    const vector<string> mapping = {
        " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void DFS(string &digits, int index, string combination,
             vector<string> &result) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }
        
        int digit = digits[index] - '0';
        for(int i = 0; i < mapping[digit].length(); i++) {
            DFS(digits, index+1, combination+mapping[digit][i], result);
        }
    }
public:
    // Time: O(3^n)
    // Space: O(n)
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        DFS(digits, 0, "", result);
        return result;
    }
};
