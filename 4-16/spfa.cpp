#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;
};
vector<edge> gh[100005];
int dist[100005];
bool vis[100005];
queue<int> q;
int n, m, p;

void spfa() {
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        dist[i] = INT_MAX;
    }
    q.push(p);
    vis[p] = true;
    dist[p] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        vis[node] = false;
        for (edge e : gh[node]) {
            if (dist[node] + e.w < dist[e.v]) {
                dist[e.v] = dist[node] + e.w;
                if (!vis[e.v]) {
                    q.push(e.v);
                    vis[e.v] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        int u;
        edge e;
        cin >> u >> e.v >> e.w;
        gh[u].push_back(e);
    }
    spfa();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}