#include <iostream>

using namespace std;
typedef long long ll;

const int MaxN = 55;
const ll MOD = 1;

unsigned int C[MaxN][MaxN];

struct Matrix {
    int n, m;
    unsigned int mp[MaxN][MaxN];

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

void init_C() {
    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    
    // Pascal's triangles for the binomial coefficients
    for (int i = 2; i <= 50; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

unsigned int solve() {
    ll N, K; cin >> N >> K;

    if (N == 1) return 1;
    ll T = N - 1;

    Matrix base(K + 2, K + 2), ans(K + 2, K + 2), initial_mt(K + 2, 1);
    for (int i = 1; i <= K + 2; i++) {
        ans.mp[i][i] = 1;
        initial_mt.mp[i][1] = i == 1 ? 1 : (1LLu << K + 2 - i);
        if (i == 1) {
            base.mp[1][1] = base.mp[1][2] = 1;
            continue;
        }

        for (int j = 1; j <= K + 2; j++) {
            base.mp[i][j] = C[K + 2 - i][K + 2 - j];
        }
    }

    while (T) {
        if (T & 1) {
            ans = ans * base;
        }
        base = base * base;
        T >>= 1;
    }

    ans = ans * initial_mt;

    return ans.mp[1][1];
}

int main() {
    init_C();

    int t, cnt = 1; cin >> t;
    while (t--) {
        printf("Case %d: %u\n", cnt++, solve());
    }
    return 0;
}
