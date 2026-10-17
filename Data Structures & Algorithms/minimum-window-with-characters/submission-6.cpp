class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.size() == 0) return "";
        if (t.size() > s.size()) return "";
        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        int l = 0;
        pair<int, int> res = {-1, -1};
        int curLen = INT_MAX;

        int have = 0;

        for (char c : t) {
            countT[c] = 1 + countT[c];
        }

        int need = countT.size();

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < curLen) {
                    curLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (countT.count(s[l]) && (window[s[l]] < countT[s[l]])) {
                    have--;
                }

                l++;
            }
        }

        if (curLen == INT_MAX) return "";
        string ress = s.substr(res.first, curLen);

        return ress;
    }
};
