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
	int gold = 0, ans = 0;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0 && gold > 0) {
			gold--, ans++;
		}
		else if (a >= k)
			gold += a;
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