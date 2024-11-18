#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n;
	cin >> n;
	
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	
	long long ans = 0;
	vector<int> t = v;
	do {
		long long val = 0;
		for (int i = 0; i < n; i++) {
			if (i & 1)
				val |= t[i];
			else
				val &= t[i];
		}
		ans = max(ans, val);
		next_permutation(t.begin(), t.end());
	}while (v != t);
	
	cout << ans << endl;
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