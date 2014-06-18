class Solution {
public:
    // Time: O(n*m)
    // Space: O(m)
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (L.size() == 0) {
            return result;
        }
        
        int wlen = L[0].length();
        int clen = wlen * L.size();
        if (S.length() < clen) {
            return result;
        }
        
        unordered_map<string, int> count;
        for (int i = 0; i < L.size(); i++) {
            count[L[i]]++;
        }
        
        for (int i = 0; i <= S.size() - clen; i++) {
            unordered_map<string, int> unused(count);
            for (int j = i; j < i + clen; j += wlen) {
                auto p = unused.find(S.substr(j, wlen));
                if (p == unused.end()) {
                    break;
                }
                p->second--;
                if (p->second == 0) {
                    unused.erase(p);
                }
            }
            if (unused.size() == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};
