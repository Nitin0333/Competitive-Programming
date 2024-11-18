#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long x, y, k;
	cin >> x >> y >> k;
	long long t1 = (x + k - 1) / k, t2 = (y + k - 1) / k;
	long long ans = 2 * max(t1, t2);
	cout << ans - (t1 >  t2) << endl;
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