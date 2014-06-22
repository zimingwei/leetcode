class Solution {
public:
    // Time: O(n)
    // Space: O(1)
    int atoi(const char *str) {
        long long result = 0;
        bool positive = true;
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-') {
                positive = false;
            }
            i++;
        }
        while (str[i] != '\0') {
            if (!isdigit(str[i])) {
                break;
            }
            result = result * 10 + str[i] - '0';
            if (positive && result > INT_MAX) {
                return INT_MAX;
            }
            if (!positive && -result < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return positive ? result : -result;
    }
};
