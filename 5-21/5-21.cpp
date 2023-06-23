#include <bits/stdc++.h>
using namespace std;

int w[10005], v[10005], c, f[100005], n;

int main() {
	cin >> c >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= c; j++) {
			f[j] = max(f[j], f[j-w[i]] + v[i]);
		}
	}
	cout << f[c];
	return 0;
}