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
	
	if (l >= r)
		cout << l << endl;
	else {
		int lo = 0, hi = l, ans = 0;
		
		while (lo <= hi) {
			int md = (lo + hi) / 2, dif = l - md, dif2 = r - md;
			if (dif * 2 >= dif2) {
				ans = md;
				lo = md + 1;
			}
			else 
				hi = md - 1;
		}
		
		cout << ans << endl;
	}
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