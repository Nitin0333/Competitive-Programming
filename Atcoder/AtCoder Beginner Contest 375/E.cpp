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
	
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	
	int sum = accumulate(b.begin(), b.end(), 0);
	
	int inf = 1e7;
	vector<vector<vector<int>>> dp(n, vector<vector<int>> (sum, vector<int> (sum, -1)));
	
	function<int(int, int, int)>fun =[&](int i, int t1, int t2) {
		if (i == n) {
			if (t1 == t2 && sum - t1 - t2 == t1)
				return 0;
			return inf;
		}
		
		if (dp[i][t1][t2] == -1) {
			int res = (a[i] != 1) + fun(i + 1, t1 + b[i], t2);
			res = min(res, (a[i] != 2) + fun(i + 1, t1, t2 + b[i]));
			res = min(res, (a[i] != 3) + fun(i + 1, t1, t2));
			dp[i][t1][t2] = res;
		}
		return dp[i][t1][t2];
	};
	
	int ans = fun(0, 0, 0);
	
	if (ans >= inf) {
		ans = -1;
	}
	
	cout << ans << endl;
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