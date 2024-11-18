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
	
	vector<int> v(n + 1, 0);
	for (int i = 1; i <= n; i++) 
		cin >> v[i];
	
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
	
	function<int(int, int)>fun =[&](int i, int prev) {
		if (i == n + 1) 
			return 0;
		
		if (dp[i][prev] == -1) {
			dp[i][prev] = 1e6;
			if (prev == 0) {
				dp[i][prev] = min(dp[i][prev], 1 + fun(i + 1, prev));
				dp[i][prev] = min(dp[i][prev], fun(i + 1, i));
			}
			if (v[i] > v[prev])
				dp[i][prev] = min(dp[i][prev], 1 + fun(i + 1, prev));
			else {
				dp[i][prev] = min(dp[i][prev], fun(i + 1, prev));
				dp[i][prev] = min(dp[i][prev], fun(i + 1, i));
			}
		}
		return dp[i][prev];
	};
	
	cout << fun(1, 0) << endl;
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