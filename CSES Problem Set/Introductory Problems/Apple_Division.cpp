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
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	long long sum = accumulate(v.begin(), v.end(), 0ll), ans = 1e15;
	
	for (int msk = 0; msk < (1 << n); msk++) {
		long long tsum = 0;
		for (int i = 0; i < n; i++) {
			if ((msk >> i) & 1)
				tsum += v[i];
		}
		
		ans = min(ans, abs(sum - 2 * tsum));
	}
	
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;
	
	while (t--) {
		solve();
	}
}