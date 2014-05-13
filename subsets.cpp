class Solution {
private:
    void DFS(vector<int> &S, int step, vector<int> &subset,
             vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(subset);
            return;
        }
        
        DFS(S, step+1, subset, result);
        
        subset.push_back(S[step]);
        DFS(S, step+1, subset, result);
        subset.pop_back();
    }
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> subset;
        DFS(S, 0, subset, result);
        return result;
    }
};

class Solution {
private:
    void DFS(vector<int> &S, int start, vector<int> &subset,
             vector<vector<int> > &result) {
        result.push_back(subset);
        
        for (int i = start; i < S.size(); i++) {
            subset.push_back(S[i]);
            DFS(S, i+1, subset, result);
            subset.pop_back();
        }
    }
public:
    // Time: O(2^n)
    // Space: O(n)
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> subset;
        DFS(S, 0, subset, result);
        return result;
    }
};
