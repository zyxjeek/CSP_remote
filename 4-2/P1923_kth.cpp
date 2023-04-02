#include <bits/stdc++.h>
using namespace std;

int ans, k;
int v[5000005];
void kth(int l, int r) {
    int i = l, j = r, pivot = v[(l+r)/2];
    do {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;
        if (i <= j) swap(v[i++], v[j--]);
    } while(i <= j);
    if (k <= j) kth(l, j);
    else if (i <= k) kth(i, r);
    else {
        cout << v[j+1] << endl;
        exit(0);
    }
    /*
    正宗快速排序：
    if (l < j) quicksort(l, j);
    if (i < r) quicksort(i, r);
    */
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    kth(0, n-1);
    return 0;
}
