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
vector<edge> gh[100005];
priority_queue<node> q;
bool vis[100005];
int dist[100005];
int n, m, s;

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dist[i] = INT_MAX;
    }
    q.push({s, 0});
    dist[s] = 0;
    while (!q.empty()) {
        node _n = q.top();
        q.pop();
        if (vis[_n.pos]) continue;
        vis[_n.pos] = true;
        for (edge e : gh[_n.pos]) {
            if (dist[_n.pos] + e.w < dist[e.v]) {
                dist[e.v] = dist[_n.pos] + e.w;
                q.push({e.v, dist[e.v]});
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x;
        edge e;
        cin >> x >> e.v >> e.w;
        gh[x].push_back(e);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    return 0;
}