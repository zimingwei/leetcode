class Solution {
private:
    bool isPalindrome(string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void DFS(string &s, int start, vector<string> &solution, 
             vector<vector<string>> &result) {
        if (start == s.length()) {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                solution.push_back(s.substr(start, i-start+1));
                DFS(s, i+1, solution, result);
                solution.pop_back();
            }
        }
    }
    
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> solution;
        DFS(s, 0, solution, result);
        return result;
    }
};
