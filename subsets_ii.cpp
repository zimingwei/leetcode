class Solution {
private:
    void DFS(vector<int> &S, int start, vector<int> &subset,
             vector<vector<int> > &result) {
        result.push_back(subset);
        
        for (int i = start; i < S.size(); i++) {
            if (i > start && S[i] == S[i-1]) {
                continue;
            }
            subset.push_back(S[i]);
            DFS(S, i+1, subset, result);
            subset.pop_back();
        }
    }
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> subset;
        DFS(S, 0, subset, result);
        return result;
    }
};
