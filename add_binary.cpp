class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        int n = max(a.size(), b.size());
        string result;
        for (int i = 0; i < n; i++) {
            int va = (i < a.size()) ? a[i] - '0' : 0;
            int vb = (i < b.size()) ? b[i] - '0' : 0;
            int val = va + vb + carry;
            carry = val / 2;
            result.push_back('0' + val%2);
        }
        if (carry > 0) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
