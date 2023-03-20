#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int n, q;
long long a[N], tagI[N], tagS[N];
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        tagI[l]++, tagI[r + 1]--;
        tagS[r + 1] -= (r - l + 1);
    }
    long long s = 0, d = 0;
    for (int i = 0; i < n; i++) {
        d += tagI[i];
        s += tagS[i] + d;
        a[i] += s;
        cout << a[i] << ' ';
    }
    cout << '\n';   
    return 0;
}
