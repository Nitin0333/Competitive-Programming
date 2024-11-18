#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int l, r, k;
	cin >> l >> r >> k;
	
	int mx = l - 1, up = r, low = l;
	while (low <= up) {
		long long md = (low * 1ll + up) / 2;
		
		if (md * k <= r) {
			mx = md;
			low = md + 1;
		}
		else {
			up = md - 1;
		}
	}
	
	cout << mx - l + 1 << endl;
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