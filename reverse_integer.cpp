class Solution {
public:
    // Time: O(logn), where n is value of input integer
    // Space: O(1)
    int reverse(int x) {
        int result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};
