class Solution {
private:
    string fillLine(vector<string> &line, int L, bool last) {
        string s;
        if (line.size() == 1 || last) {
            int len = 0;
            for (auto word : line) {
                if (!s.empty()) {
                    s.append(1, ' ');
                    len++;
                }
                len += word.length();
                s.append(word);
            }
            s.append(L-len, ' ');
        } else {
            int totalLen = 0;
            for (auto word : line) {
                totalLen += word.length();
            }
            int spaceSize = (L - totalLen) / (line.size() - 1);
            int extra = (L - totalLen) % (line.size() - 1);
            for (int i = 0; i < line.size(); i++) {
                if (!s.empty()) {
                    if (i > extra) {
                        s.append(spaceSize, ' ');
                    } else {
                        s.append(spaceSize+1, ' ');
                    }
                }
                s.append(line[i]);
            }
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int len = 0;
        vector<string> line;
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            int wLen = words[i].length();
            if (len + wLen > L) {
                result.push_back(fillLine(line, L, false));
                line.clear();
                len = 0;
            }
            line.push_back(words[i]);
            len += wLen + 1;
        }
        result.push_back(fillLine(line, L, true));
        return result;
    }
};
