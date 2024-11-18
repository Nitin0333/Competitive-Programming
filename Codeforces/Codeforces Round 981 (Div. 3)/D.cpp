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
	
	map<long long, int> m;
	m[0] = 0;
	
	vector<int> dp(n + 1);

	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		
		sum += a;
		
		if (m.find(sum) == m.end()) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = max(dp[m[sum]] + 1, dp[i - 1]);
		}
		
		m[sum] = i;
	}
	
	cout << dp[n] << endl;
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