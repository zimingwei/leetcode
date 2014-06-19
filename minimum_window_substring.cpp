class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    string minWindow(string S, string T) {
        vector<int> expected(256, 0);
        vector<int> appeared(256, 0);
        for (int i = 0; i < T.length(); i++) {
            expected[T[i]]++;
        }
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        for (int right = 0; right < S.length(); right++) {
            if (expected[S[right]] > 0) {
                appeared[S[right]]++;
                if (appeared[S[right]] <= expected[S[right]]) {
                    count++;
                }
            }
            if (count == T.length()) {
                while (expected[S[left]] == 0 || 
                       appeared[S[left]] > expected[S[left]]) {
                    appeared[S[left]]--;
                    left++;
                }
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
            }
        }
        return (minLen == INT_MAX) ? "" : S.substr(minLeft, minLen);
    }
};
