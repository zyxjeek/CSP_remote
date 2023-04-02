#include <bits/stdc++.h>
using namespace std;

set<int> gh[100001];
int n, m;
bool vis[100001];
void dfs(int);
void bfs(int);

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gh[u].insert(v);
    }
    dfs(1);
    memset(vis, false, sizeof(vis));
    cout << endl;
    bfs(1);
    return 0;
}

void dfs(int x) {
    if (vis[x]) return;
    cout << x << ' ';
    vis[x] = true;
    for (auto i : gh[x]) dfs(i);
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (auto i : gh[node])
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
    }
}