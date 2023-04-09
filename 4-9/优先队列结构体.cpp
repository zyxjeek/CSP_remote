#include <bits/stdc++.h>
using namespace std;

struct node {
    int pos, dis;
    bool operator<(const node& a) const {
        return dis > a.dis; //改为优先小
    }
} node_1;

int main() {
    priority_queue<node> q;
    int m, n;
    for (int i = 0; i < 2; i++) {
        cin >> m >> n;
        node_1.pos = m;
        node_1.dis = n;
        q.push(node_1);
    }
    // cout << q.top().dis
    while (!q.empty()) {
        node n = q.top();
        q.pop();
        cout << n.pos << ' ' << n.dis << endl;
    }
    return 0;
}