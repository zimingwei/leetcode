class Solution {
private:
    bool isScramble(string &s1, int l1, string &s2, int l2, int size) {
        if (size == 1 && s1[l1] == s2[l2]) {
            return true;
        }
        
        vector<int> C(26, 0);
        for (int i = l1; i < l1+size; i++) {
            C[s1[i]-'a']++;
        }
        for (int i = l2; i < l2+size; i++) {
            C[s2[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (C[i] != 0) {
                return false;
            }
        }
        
        for (int i = 1; i < size; i++) {
            bool result = (isScramble(s1, l1, s2, l2, i) && 
                           isScramble(s1, l1+i, s2, l2+i, size-i)) || (
                           isScramble(s1, l1, s2, l2+size-i, i) &&
                           isScramble(s1, l1+i, s2, l2, size-i));
            if (result == true) {
                return true;
            }
        }
        return false;
    }

public:
    // Time: O(4^n)
    // Space: O(n)
    bool isScramble(string s1, string s2) {
        return isScramble(s1, 0, s2, 0, s1.size());
    }
};
