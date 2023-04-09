#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> q;
	// priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < 5; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}
