class Solution {
public:
    // Time: O(logn)
    // Space: O(1)
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int d = 1;
        while (x / d >= 10) {
            d *= 10;
        }
        while (x > 0) {
            int l = x / d;
            int r = x % 10;
            if (l != r) {
                return false;
            }
            x = (x % d) / 10;
            d /= 100;
        }
        return true;
    }
};
