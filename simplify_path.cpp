class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    string simplifyPath(string path) {
        stack<string> dirs;
        for (int i = 0; i < path.size(); ) {
            int j = i + 1;
            while (j < path.size()) {
                if (path[j] == '/') {
                    break;
                }
                j++;
            }
            string dir = path.substr(i+1, j-i-1);
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dirs.empty()) {
                        dirs.pop();
                    }
                } else {
                    dirs.push(dir);
                }
            }
            i = j;
        }
        string result;
        while (!dirs.empty()) {
            result = "/" + dirs.top() + result;
            dirs.pop();
        }
        return result.empty() ? "/" : result;
    }
};
