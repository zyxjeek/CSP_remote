#include <bits/stdc++.h>
using namespace std;

struct gold {
    int w;
    double r;
    bool operator<(const gold& g) const {
        return r > g.r;
    }
    double v() {
        return w * r;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    gold g[n];
    for (gold& item : g) {
        double v;
        cin >> item.w >> v;
        item.r = v / item.w;
    }
    sort(g, g + n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].w <= t) sum += g[i].v(), t -= g[i].w;
        else {
            sum += g[i].v() * t * 1.0 / (g[i].w * 1.0);
            break;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}