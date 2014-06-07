class Solution {
private:
    void DFS(string &s, int step, int start, string ip, 
             vector<string> &result) {
        if (step == 4) {
            if (start == s.size()) {
                ip.pop_back();
                result.push_back(ip);
            }
            return;
        }
        
        if (s.size() - start > (4 - step) * 3) { // key cutoff
            return;
        }
        if (s.size() - start < (4 - step)) {
            return;
        }

        int num = 0;
        for (int i = start; i < start+3; i++) {
            num = num * 10 + s[i] - '0';
            if (num < 256) {
                ip += s[i];
                DFS(s, step+1, i+1, ip+'.', result);
            }
            if (num == 0) { // consecutive 0's are not allowed
                return;
            }
        }
    }

public:
    // Time: O(?)
    // Space: O(1)
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        DFS(s, 0, 0, "", result);
        return result;
    }
};
