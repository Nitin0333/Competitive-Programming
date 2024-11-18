#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	string s = "narek";
	
	long long inf = -1e17;
	
	vector<vector<long long>> dp(n, vector<long long> (5, inf));
	
	function<long long(int, int)>fun =[&](int i, int j) {
		// debug(i, j);
		if (i == n) {
			return j * -1ll;
		}
		if (dp[i][j] == inf) {
			dp[i][j] = 0;
			dp[i][j] = fun(i + 1, j);
			int j1 = j;
			int ad = 0;
			for (int k = 0; k < m; k++) {
				if (v[i][k] == s[j1]) {
					if (j1 == 4)
						ad += 5;
					j1 = (j1 + 1) % 5;
				}
				else if (v[i][k] == 'n' || v[i][k] == 'a' || v[i][k] == 'r' || v[i][k] == 'e' || v[i][k] == 'k')
					ad--;
			}
			// debug(i, j, ad);
			dp[i][j] = max(dp[i][j], ad + fun(i + 1, j1));
			// debug(dp[i][j]);
		}
		return dp[i][j];	
	};
	
	fun(0, 0);
	
	cout << max(0ll, dp[0][0]) << endl;
	
	// for (auto x : dp)
	// 	debug(x);
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
