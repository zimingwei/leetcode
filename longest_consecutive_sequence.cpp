class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> checked;
        for (int i = 0; i < num.size(); i++) {
            checked[num[i]] = false;
        }
        int longest = 0;
        for (int i = 0; i < num.size(); i++) {
            if (!checked[num[i]]) {
                int length = 1;
                checked[num[i]] = true;
                for (int n = num[i]+1; checked.find(n) != checked.end(); n++) {
                    length++;
                    checked[n] = true;
                }
                for (int n = num[i]-1; checked.find(n) != checked.end(); n--) {
                    length++;
                    checked[n] = true;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
