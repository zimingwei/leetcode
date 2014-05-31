class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> group;
        vector<string> result;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            group[key].push_back(strs[i]);
        }
        for (auto it = group.begin(); it != group.end(); it++) {
            if (it->second.size() > 1) {
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        return result;
    }
};
