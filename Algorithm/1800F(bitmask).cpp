#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for (int i = a; i < b; i++)
const int N = 1e5 * 2 + 4;
long long solve() {
	int n;
	long long ans = 0;
	cin >> n;
	string s;
	vector<int> had, need;
	rep(i, 0, n) {
		cin >> s;
		vector<int> cnt(26, 0);
		for (char c : s) {
			cnt[c - 'a']++;
		}
		int mask = 0;
		rep(j, 0, 26) {
			if (cnt[j] & 1) {
				mask = mask | (1 << j);
			}
		}
		rep(j, 0, 26) {
			if (!cnt[j])
				had.emplace_back((j << 26) | mask);
		}
		rep(j, 0, 26) {
			if (!cnt[j]) {
				int new_mask = (1 << 26);
				new_mask--;
				new_mask ^= mask;
				new_mask ^= (1 << j);
				need.emplace_back(new_mask | (j << 26));
			}
		}
	}
	sort(had.begin(), had.end());
	sort(need.begin(), need.end());
	for (int i = 0, j = 0; i < had.size() && j < need.size();) {
		if (had[i] < need[j]) 
			i++;
		else if (had[i] > need[j])
			j++;
		else {
			int cnt = 1;
			while (i + 1 < had.size() && had[i] == had[i + 1]) {
				i++;
				cnt++;
			}
			ans += cnt;
			while (j + 1 < need.size() && need[j] == need[j+1]) {
				j++;
				ans += cnt;
			}
			i++, j++;
		}
	}
	ans >>= 1;
	return ans;
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << solve() <<'\n';
	return 0;
}
