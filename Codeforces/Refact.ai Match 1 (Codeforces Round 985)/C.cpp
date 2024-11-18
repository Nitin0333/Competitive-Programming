#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

// void solve() {
// 	int n;
// 	cin >> n;
	
// 	vector<int> v(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> v[i];
// 	}
	
// 	vector<int> pre(n), mx(n);
// 	int sum = 0;
// 	for (int i = 0; i < n; i++) {
// 		if (sum < v[i])
// 			sum++;
// 		else if (sum > v[i])
// 			sum--;
		
// 		pre[i] = sum;
// 		mx[i] = pre[i];
// 		if (i)
// 			mx[i] = max(mx[i - 1], mx[i]);
// 	}

// 	function<bool(int)>chk =[&](int md) {
// 		vector<int> suf(n + 1, md);
// 		int val = md;

// 		for (int i = n - 1; i > -1; i--) {
// 			if (mx[i] >= val) {
// 				return true;
// 			}
			
// 			if (v[i] >= val)
// 				val--;
// 			else
// 				val++;
// 		}
		
// 		return val <= 0;
// 	};
	
// 	int l = 0, r = n, ans = 0;
// 	while (l <= r) {
// 		int md = (l + r) / 2;
		
// 		if (chk(md)) {
// 			ans = md;
// 			l = md + 1;
// 		}
// 		else {
// 			r = md - 1;
// 		}
// 	}
	
// 	if (ans == n) 
// 		ans--;
	
// 	cout << ans << endl;
// }

void solve() {
	int n;
	cin >> n;
	
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
	}
	
	vector<vector<int>> dp(n + 1, vector<int> (3));
	for (int i = 1; i <= n; i++) {
		if (v[i] > dp[i - 1][0]) {
			dp[i][0] = dp[i - 1][0] + 1;
		}
		else if (v[i] < dp[i - 1][0]) {
			dp[i][0] = dp[i - 1][0] - 1;
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}
		
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		
		if (dp[i - 1][1] > v[i]) {
			dp[i][2] = dp[i - 1][1] - 1;
		}
		else if (dp[i - 1][1] < v[i]) {
			dp[i][2] = dp[i - 1][1] + 1;
		}
		else {
			dp[i][2] = dp[i - 1][1];
		}
		
		if (dp[i - 1][2] > v[i]) {
			dp[i][2] = max(dp[i][2], dp[i - 1][2] - 1);
		}
		else if (dp[i - 1][2] < v[i]) {
			dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
		}
		else {
			dp[i][2] = max(dp[i][2], dp[i - 1][2]);
		}
	}
	
	int ans = max(dp[n][1], dp[n][2]);
	if (ans == n)
		ans--;
	
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