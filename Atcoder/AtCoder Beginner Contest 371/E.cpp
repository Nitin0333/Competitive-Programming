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
	
	vector<int> lst(n + 1, -1);
	vector<long long> dp(n);
	
	for (int i = 0; i < n; i++) {
		if (i)
			dp[i] += dp[i - 1];
		dp[i] += i - lst[v[i]];
		lst[v[i]] = i;
	}
	
	debug(dp);
	
	cout << accumulate(dp.begin(), dp.end(), 0ll);
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