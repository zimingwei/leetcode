class Solution {
private:
    void DFS(vector<int> &num, int diff, int start, vector<int> &combination,
             vector<vector<int> > &result) {
        if (diff == 0) {
            result.push_back(combination);
            return;
        }
        int prev = -1;
        for (int i = start; i < num.size(); i++) {
            if (prev == num[i]) {
                continue;
            }
            if (diff < num[i]) {
                continue;
            }
            prev = num[i];
            combination.push_back(num[i]);
            DFS(num, diff-num[i], i+1, combination, result);
            combination.pop_back();
        }
    }

public:
    // Time: O(n!)
    // Space: O(n)
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> combination;
        sort(num.begin(), num.end());
        DFS(num, target, 0, combination, result);
        return result;
    }
};
