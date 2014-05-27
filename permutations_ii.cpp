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
                if(i > 0 && num[i] == num[i-1] && !used[i-1]) {
                    continue;
                }
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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        used = vector<bool>(num.size(), false);
        permutation = vector<int>(num.size());
        sort(num.begin(), num.end());
        DFS(num, result, 0);
        return result;
    }
};
