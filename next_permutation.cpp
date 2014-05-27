class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    void nextPermutation(vector<int> &num) {
        for (int i = num.size() - 2; i >= 0; i--) {
            if (num[i] < num[i+1]) {
                int j = num.size() - 1;
                while (j > i && num[j] <= num[i]) {
                    j--;
                }
                swap(num[i], num[j]);
                reverse(num.begin()+i+1, num.end());
                return;
            }
        }
        reverse(num.begin(), num.end());
        return;
    }
};
