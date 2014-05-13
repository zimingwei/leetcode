class Solution {
public:
    // Time: O(n^2)
    // Space: O(1)
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int target = 0;
        int size = num.size();
        
        for (int i = 0; i < size-2 ; i++) {
            if (i != 0 && num[i] == num[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = size - 1;
            int diff = target - num[i];
            while (j < k) {
                if (num[j] + num[k] == diff) {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[j]);
                    triplet.push_back(num[k]);
                    result.push_back(triplet);
                    j++;
                    k--;
                    while (j < k && num[j] == num[j-1]) {
                        j++;
                    }
                    while (j < k && num[k] == num[k+1]) {
                        k--;
                    }
                } else if (num[j] + num[k] < diff) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};
