class Solution {
   public:
    unordered_map<int, vector<int>> edgeMap;
    unordered_set<int> visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) return true;

        for (auto edge : edges) {
            edgeMap[edge[0]].push_back(edge[1]);
            edgeMap[edge[1]].push_back(edge[0]);
        }

        return dfs(0, -1) && (n == visit.size());
    }

    bool dfs(int num, int prev) {
        if (visit.count(num)) {
            cout << num << endl;
            cout << prev <<endl;
            return false;
        } else {
            visit.insert(num);
            cout << "visit: " << visit.size() << endl;
        }
        for (auto nextnum : edgeMap[num]) {
            if (nextnum == prev) continue;
            if (dfs(nextnum, num) == false) return false;
        }
        return true;
    }
};
