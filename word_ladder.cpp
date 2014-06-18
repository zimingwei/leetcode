class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        queue<pair<string, int>> Q;
        Q.push(make_pair(start, 1));
        visited.insert(start);
        while (!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int step = p.second;
            for (int i = 0; i < p.first.length(); i++) {
                string s = p.first;
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i] = c;
                    if (s == end) {
                        return step + 1;
                    }
                    if (dict.count(s) && !visited.count(s)) {
                        visited.insert(s);
                        Q.push(make_pair(s, step+1));
                    }
                }
            }
        }
        return 0;
    }
};
