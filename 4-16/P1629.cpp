#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;
};
struct node {
    int pos, dis;
    bool operator<(const node& b) const {
        return dis > b.dis;
    }
};
vector<edge> gh[1005], gh1[1005];
int dist[1005];
bool vis[1005];
int n, m;
priority_queue<node> q;

void dijkstra(vector<edge> g[]) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        vis[i] = false;
    }
    node u{1, 0};
    q.push(u);
    dist[1] = 0;
    while (!q.empty()) {
        u = q.top();
        q.pop();
        if (vis[u.pos]) continue;
        vis[u.pos] = true;
        for (edge e : g[u.pos]) {
            if (dist[u.pos] + e.w < dist[e.v]) {
                dist[e.v] = dist[u.pos] + e.w;
                q.push({e.v, dist[e.v]});
            }
        }
    }
}

int main() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u;
        edge e;
        cin >> u >> e.v >> e.w;
        gh[u].push_back(e);
        gh1[e.v].push_back({u, e.w});
    }
    dijkstra(gh);
    for (int i = 1; i <= n; i++) ans += dist[i];
    dijkstra(gh1);
    for (int i = 1; i <= n; i++) ans += dist[i];
    cout << ans << endl;
    return 0;
}
