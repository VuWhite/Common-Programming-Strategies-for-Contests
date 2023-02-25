#include <numeric>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct dsu{
    vector<size_t> pa, size, sum;
    explicit dsu(size_t size_): pa(size_ *2), size(size_ * 2, 1), sum(size_ * 2) {
        iota(pa.begin(), pa.begin() + size_, size_);
        iota(pa.begin() + size_, pa.end(), size_);
        iota(sum.begin() + size_, sum.end(), 0);
    }
    size_t find(size_t x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    void move(size_t x, size_t y) {
      auto fx = find(x), fy = find(y);
      if (fx == fy) return;
      pa[x] = fy;
      --size[fx], ++size[fy];
      sum[fx] -= x, sum[fy] += x;
    }
    void unite(size_t x, size_t y) { 
        x = find(x), y = find(y);
        if (x == y) {
            return;
        }
        if (size[x] > size[y]) 
            swap(x,y);
        pa[x] = y;
        sum[y] += sum[x];
        size[y] += size[x];
    }
};
int main()
{
    size_t n, m, t, x, y;
    while (cin >> n >> m) {
        dsu d(n+1);
        while (m--) {
            cin >> t;
            switch (t) {
                case 1:
                    cin >> x >> y;
                    d.unite(x, y);
                    break;
                case 2:
                    cin >> x >> y;
                    d.move(x, y);
                    break;
                case 3:
                    cin >> x;
                    x = d.find(x);
                    cout << d.size[x] << ' ' << d.sum[x] << '\n';
                    break;
                defaul:
                    assert(false);
            }
        }
    }
    return 0;
}
