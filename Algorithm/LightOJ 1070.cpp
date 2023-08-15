#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
typedef unsigned long long ull;

const int MaxN = 7;
const ull MOD = (ull(1) << 63);

struct Matrix {
    int n, m;
    ull mp[MaxN][MaxN];

    Matrix(int x, int y) {
        n = x, m = y;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mp[i][j] = 0;
    }

    Matrix operator * (Matrix b) {
        Matrix res(n, b.m);
        if (m == b.n) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    for (int k = 1; k <= b.m; k++)
                        res.mp[i][k] = res.mp[i][k] + mp[i][j] * b.mp[j][k];
        } else {
            printf("Multiplication Undefined\n");
        }
        return res;
    }
};

ull solve() {
    int A, B, n;
    cin >> A >> B >> n;
    

    if (!n) return 2LLu;
    if (n == 1) return A;
    if (n == 2) return 1LLu * A * A - 2LLu * B;

    Matrix base(2, 2), ans(2, 2), init(2, 1);
    base.mp[1][1] = A, base.mp[1][2] = -B, base.mp[2][1] = 1;
    ans.mp[1][1] = 1, ans.mp[2][2] = 1;
    init.mp[2][1] = A, init.mp[1][1] = 1LLu * A * A - 2LLu * B;

    n -= 2;
    while (n) {
        if (n & 1LLu) {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }

    ans = ans * init;
    return ans.mp[1][1];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t, cnt = 1; cin >> t;

    while (t--) {
        cout << "Case " << cnt++ << ": " << solve() << '\n';
    }

    return 0;
}