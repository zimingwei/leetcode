class Solution {
public:
    // Time: O(n^2)
    // Space: O(1)
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int size = num.size();
        int result = 0;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < size-2; i++) {
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = num[i] + num[left] + num[right];
                int diff = abs(target - sum);
                if (diff < minDiff) {
                    minDiff = diff;
                    result = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};
