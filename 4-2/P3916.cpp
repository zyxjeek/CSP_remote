#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> gh[100001];
int ans[100001];

void solve(int x, int v) {
    ans[x] = v;
    for (int i : gh[x])
        if (ans[i] == 0)
            solve(i, v);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        gh[v].push_back(u);
    }
    for (int i = n; i >= 0; i--)
        if (ans[i] == 0) solve(i, i);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}