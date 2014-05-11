class Solution {
private:
    void subsets(vector<int> &S, int step, vector<int> &subset,
                 vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(subset);
            return;
        }
        
        subsets(S, step+1, subset, result);
        
        subset.push_back(S[step]);
        subsets(S, step+1, subset, result);
        subset.pop_back();
    }
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> subset;
        subsets(S, 0, subset, result);
        return result;
    }
};
