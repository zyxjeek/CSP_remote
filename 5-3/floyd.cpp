#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX / 2;
int gh[505][505];
int n, m;
void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                gh[j][k] = min(gh[j][k], gh[j][i] + gh[i][k]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, l;
        cin >> x >> y >> l;
        gh[x][y] = l;
        gh[y][x] = l;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (gh[i][j] == 0 && i != j) gh[i][j] = inf;
    floyd();
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) sum += gh[i][j];
        cout << sum << endl;
    }
    return 0;
}