#include <iostream>
#include <utility>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 0x3fffffffffff;
int n, m;
vector<pair<int, long long>> adj[N];
long long dis1[N], dis2[N];
int processed[N], procs[N];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++) {
        dis1[i] = INF;
        dis2[i] = INF;
    }
    dis1[1] = 0;
    priority_queue<pair<long long, int>> pq, pq2;
    pq.push({0, 1});
    while (!pq.empty()) {
        int a = pq.top().second;
        pq.pop();
        if (processed[a]) {
            continue;
        }
        processed[a] = 1;
        for (auto u: adj[a]) {
            int b = u.first, w = u.second;
            if (dis1[a] + w < dis1[b]) {
                dis1[b] = dis1[a] + w;
                pq.push({-dis1[b], b});
            }
        }
    }
    dis2[n] = 0;
    pq2.push({0, n});
    while (!pq2.empty()) {
        int a = pq2.top().second;
        pq2.pop();
        if (procs[a]) {
            continue;
        }
        procs[a] = 1;
        for (auto u: adj[a]) {
            int b = u.first, w = u.second;
            if (dis2[a] + w < dis2[b]) {
                dis2[b] = dis2[a] + w;
                pq2.push({-dis2[b], b});
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis1[i] + dis2[i]);
    }
    cout << ans << '\n';
}
int main() {
    solve();
    return 0;
}
