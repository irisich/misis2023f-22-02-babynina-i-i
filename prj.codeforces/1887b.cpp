#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<pair<int, int>>> adj(n + 1);
    const int inf = 0x3f3f3f3f;
    vector<int> dis(n + 1, inf);
    for (int i = 1; i <= t; i++) {
        int m;
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }
    int k;
    cin >> k;  
    vector<vector<int>> at(t + 1);
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        at[x].emplace_back(i);
    }
    
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.emplace(0, 1);
    while (heap.size()) {
        auto [d, t] = heap.top();
        heap.pop();
        if (dis[t] != inf) continue;
        dis[t] = d;
        for (auto [v, day] : adj[t]) {
            auto it = upper_bound(at[day].begin(), at[day].end(), d);
            if (it != at[day].end()) {
                heap.emplace(*it, v);
            }
        }
    }
    
    if (dis[n] == inf) dis[n] = -1;
    cout << dis[n] << '\n';
    return 0;
}
