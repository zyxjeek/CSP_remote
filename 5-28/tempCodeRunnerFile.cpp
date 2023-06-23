#include <bits/stdc++.h>
using namespace std;

int dp[1005], v[1005], w[1005], k[1005];
int c, n;

int main() {
    cin >> c >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> k[i];
    }
    for (int i = 1; i <= n; i++) {
        if (k[i] * w[i] > c)
            for (int j = w[i]; j <= c; j++)
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        else {
            int a = 1;
            while (k[i] > a) {
                k[i] -= a;
                for (int j = c; j >= a * w[i]; j--)
                    dp[j] = max(dp[j], dp[j-a*w[i]]+a*v[i]);
                a *= 2;
            }
            for (int j = c; j >= k[i] * w[i]; j--)
                dp[j] = max(dp[j], dp[j-k[i]*w[i]]+k[i]*v[i]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}