#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, k;
	cin >> n >> k;
	
	long long ans = 0, pt, s = 1ll * n * k + (n * (n - 1ll)) / 2;
	
	function<long long(int)>sum =[&](int md) {
		return s - 2ll * md * k - (md * (md - 1ll));
	};
	
	debug(s);
	
	int l = 1, h = n;
	while (l <= h) {
		int md = (l + h) / 2;
		long long val = sum(md);
		debug(md, val);
		if (val >= 0) {
			ans = abs(val);
			pt = md;
			l = md + 1;
		}
		else
			h = md - 1;
	}
	
	ans = min(ans, abs(sum(pt + 1)));
	
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