#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int l, r;
	cin >> l >> r;
	
	long long up = 1, hg = r, ans = 1;
	
	while (up <= hg) {
		long long md = (up + hg) / 2;
		long long lst = (md * (md - 1)) / 2 + l;
		if (lst <= r) {
			ans = md;
			up = md + 1;
		}
		else
			hg = md - 1;
	}
	
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