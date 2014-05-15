class Solution {
private:
    void DFS(vector<int> &candidates, int diff, int start, vector<int> &combination,
             vector<vector<int> > &result) {
        if (diff == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (diff < candidates[i]) {
                continue;
            }
            combination.push_back(candidates[i]);
            DFS(candidates, diff-candidates[i], i, combination, result);
            combination.pop_back();
        }
    }
public:
    // Time: O(n!)
    // Space: O(n)
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0, combination, result);
        return result;
    }
};
