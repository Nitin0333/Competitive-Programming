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
	
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	long long ans = 0, sum = 0;
	
	for (int i = 0; i < n; i++) {
		long long clk = v[i] - sum, tot = clk * (n - i);
		if (tot < k) {
			ans += tot + 1;
			sum = v[i];
			k -= tot;
		}
		else {
			ans += k;
			break;
		}
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