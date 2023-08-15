#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int Nmax = 7;
const int mod = 7;

struct Matrix {
    int n, m;
    int mp[Nmax][Nmax];

    //constructor
    Matrix(int x, int y) {
        n = x;
        m = y;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mp[i][j] = 0;
    }

    //overload operators
    Matrix operator * (const Matrix b) {
        Matrix c(n, b.m);

        //legal multiplication if and only if m == b.n;
        if (m == b.n) {
            for (int i = 1; i <= c.n; i++)
                for (int k = 1; k <= m; k++) 
                    for (int j = 1; j <= c.m; j++)
                        c.mp[i][j] = (c.mp[i][j] + (mp[i][k] * b.mp[k][j]) % mod) % mod;
            
        } else {
            printf("multiplication undefined\n");
            showMatrix();
        }
        return c;
    }

    Matrix operator + (const Matrix b) {
        Matrix c(n, m);

        //legal sum if and only if the two matrices have the same dimensions.
        if (m == b.m && n == b.n) {
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= m; j++)
                    c.mp[i][j] = mp[i][j] + mp[i][j];
        } else {
            printf("sum undefined\n");
        }

        return c;
    }

    //for debugging
    void showMatrix() {
        printf("n: %d, m: %d\n", n, m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                printf("%4d%c", mp[i][j], " \n"[j == m]);
    }
};

int main() {
    string line;
    
    while (getline(cin, line)) {
        int A[3], idx = 0;
        string token;
        size_t pos;
        while ((pos = line.find(' ')) != string::npos) {
            token = line.substr(0, pos);
            A[idx++] = stoi(token);
            line.erase(0, pos + 1);
        }
        A[idx] = stoi(line);
        if (A[0] == 0 && A[1] == 0 && A[2] == 0)
            break;
        
        if (A[2] <= 2) {
            cout << 1 << endl;
            continue;
        }

        A[2] -= 2;

        Matrix std_mt(2, 2), ans(2, 2);
        std_mt.mp[1][1] = A[0], std_mt.mp[1][2] = A[1], std_mt.mp[2][1] = 1;
        ans.mp[1][1] = ans.mp[2][2] = 1; // initialized as an identity matrix

        while (A[2]) {
            //divide and conquer
            if (A[2] & 1) {
                ans = ans * std_mt;
            }
            std_mt = std_mt * std_mt;
            A[2] >>= 1;
        }

        Matrix initial_mt(2, 1);
        initial_mt.mp[1][1] = initial_mt.mp[2][1] = 1;
        ans = ans * initial_mt;

        cout << ans.mp[1][1] << endl;
    }
    return 0;
}