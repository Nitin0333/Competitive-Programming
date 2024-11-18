#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<vector<long long>> dp(n, vector<long long> (2, -1));
	
	function<long long(int, int, int)>dfs =[&](int i, int p, int tk) {
		if (dp[i][tk] == -1) {
			long long cal1 = 0, cal2 = v[i] - 2ll * tk * c;
			for (auto x : g[i]) {
				if (x == p)
					continue;
				cal1 += dfs(x, i, 0);
				cal2 += dfs(x, i, 1);
			}
			dp[i][tk] = max(cal1, cal2);
		}
		return dp[i][tk];
	};
	
	cout << dfs(0, -1, 0) << endl;
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