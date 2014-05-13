class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        
        for (int i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); i++) {
            int diff = target - numbers[i];
            if (hash.find(diff) != hash.end() && hash[diff] != i) {
                result.push_back(i+1);
                result.push_back(hash[diff]+1);
                break;
            }
        }
        return result;
    }
};
