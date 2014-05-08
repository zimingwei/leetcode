class Solution {
private:
    vector<int> combination;
    vector<vector<int> > result;
    
    void DFS(int n, int k, int start, int count) {
        if (count == k) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            DFS(n, k, i+1, count+1);
            combination.pop_back();
        }
    }
public:
    // Time: O(n!)
    vector<vector<int> > combine(int n, int k) {
        DFS(n, k, 1, 0);
        return result;
    }
};
