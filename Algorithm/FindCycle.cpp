#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, m, cnt = 0, verS = -1, verE = -1;
int vis[N];
vector<vector<int>> gp;
vector<int> p;
bool dfs(int s, int last) {
    vis[s] = 1;
    for (int i: gp[s]) {
        if (i != last) {
            if (vis[i]) {
                verS = i;
                verE = s;
                return true;
            }
            p[i] = s;
            if (dfs(i, s)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    gp.resize(n + 1);
    p.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, p[i])) {
            break;
        }
    }
    if (verS == -1) {
        cout << "IMPOSSIBLE" <<'\n';
    }
    else {
        vector<int> ans;
        ans.emplace_back(verS);
        for (int i = verE; i != verS; i = p[i]) {
            ans.emplace_back(i);
        }
        ans.emplace_back(verS);
        cout << ans.size() << endl;
        for (int c: ans)
            cout << c << ' ';
        cout << '\n';
    }   
    return 0;
}
