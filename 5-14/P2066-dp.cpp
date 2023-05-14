#include <bits/stdc++.h>
using namespace std;

int a[20][20], dp[20][20];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // for (int i = 1; i <= m; i++) dp[1][i] = a[1][i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j - k]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}