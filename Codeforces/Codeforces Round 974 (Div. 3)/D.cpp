#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, d, k;
	cin >> n >> d >> k;
	
	vector<vector<int>> ad(n + 1), rm(n + 1);
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		ad[l].push_back(i);
		rm[r].push_back(i);
	}
	
	// debug(ad);
	// debug(rm);
		
	set<int> s;
	int mx = 0, mxi = 1, mn = n + 1, mni = 1;
	for (int i = 1; i <= n; i++) {
		if (i > d)
			for (auto x : rm[i - d])
				s.erase(x);
		for (auto x : ad[i])
			s.insert(x);
		int sz = s.size();
		// debug(i, sz);
		if (sz > mx) {
			mx = sz;
			mxi = max(1, i - d + 1);
		}
		if (i >= d) {
			if (sz < mn) {
				mn = sz;
				mni = max(1, i - d + 1);
			}
		}
	}
	
	cout << mxi << " " << mni << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}
}