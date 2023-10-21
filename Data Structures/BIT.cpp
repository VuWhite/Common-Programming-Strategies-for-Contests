template <class T> struct BIT {
	int N;
	vector<T> data;
	void init(int _N) {
		N = _N;
		data.resize(N);
	}
	void add(int p, T x) {
		for (++p; p <= N; p += p & -p) {
			data[p - 1] += x;
		}
	}
	T sum(int l, int r) {
		return sum(r + 1) - sum(l);
	}
	T sum(int r) {
		T s = 0;
		for (; r; r -= r & -r) {
			s += data[r - 1];
		}
		return s;
	}
	int lower_bound(T sum) {
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			int npos = pos + pw;
			if (npos <= N && data[npos - 1] < sum) {
				pos = npos, sum -= data[pos - 1];
			}
		}
		return pos;
	}
};

template <class T> struct SegTree {
	const T ID{};
	T cmb(T a, T b) {return max(a, b);}
	int n;
	vector<T> seg;
	void init(int _n) {
		for (n = 1; n < _n;) n *= 2;
		seg.assign(2 * n, ID);
	}
	void pull(int p) {
		seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
	}
	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) {
			pull(p);
		}
	}
	T query(int l, int r) { //zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = cmb(ra, seg[l++]);
			if (r & 1) rb = cmb(seg[--r], rb);
		}
		return cmb(ra, rb);
	}
};