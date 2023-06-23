#include <bits/stdc++.h>
using namespace std;

int a[20005], dp[20005], m, n, ans = INT_MIN;

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) a[i] = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n-1; j++) {
            int t;
            cin >> t;
            dp[j] = a[j] = max(a[j], t);
        }
    }
    for (int i = 1; i < n-1; i++) {
        dp[i] = max(dp[i], dp[i-1] + a[i]);
    }
    for (int i = 0; i < n-1; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}