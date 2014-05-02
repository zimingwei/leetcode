class Solution {
private:
    vector<bool> used;
    vector<int> permutation;
    
    void DFS(vector<int> &num, vector<vector<int> > &result, int n) {
        int size = num.size();
        if (n == size) {
            result.push_back(permutation);
            return;
        }
        
        for (int i = 0; i < size; i++) {
            if (!used[i]) {
                used[i] = true;
                permutation[n] = num[i];
                DFS(num, result, n+1);
                used[i] = false;
            }
        }
    }
    
public:
    // Time: O(n!)
    // Space: O(n)
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        used = vector<bool>(num.size(), false);
        permutation = vector<int>(num.size());
        DFS(num, result, 0);
        return result;
    }
};
