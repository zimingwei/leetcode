class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string getPermutation(int n, int k) {
        vector<char> num;
        int mod = 1;
        string result;
        
        for (int i = 1; i <= n; i++) {
            num.push_back('0'+i);
            mod *= i;
        }
        k--;
        for (int i = 0; i < n; i++) {
            mod /= n - i;
            result.push_back(num[k/mod]);
            num.erase(num.begin()+k/mod);
            k %= mod;
        }
        return result;
    }
};
