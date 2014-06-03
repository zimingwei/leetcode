class Solution {
public:
    // Time: O(n^2logn)
    // Space: O(n^2)
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        unordered_map<int, set<pair<int, int>>> hash;
        set<vector<int>> result;
        for (int i = 0; i < num.size(); i++) {
            for (int j = i+1; j < num.size(); j++) {
                int sum = num[i] + num[j];
                if (hash.count(target-sum) > 0) {
                    for (auto &p: hash[target-sum]) {
                        vector<int> tmp = {p.first, p.second, num[i], num[j]};
                        result.insert(tmp);
                    }
                }
            }
            for (int j = 0; j < i; j++) {
                int sum = num[i] + num[j];
                // logn time to insert into set
                hash[sum].insert(make_pair(num[j], num[i]));
            }
        }
        return vector<vector<int> >(result.begin(), result.end());
    }
};
