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
	
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) 
		cin >> v[i];
	
	long long ans = 0;
	
	for (int i = 1; i <= n; i++) {
		ans += max(0, v[i - 1] - v[i]);
		v[i] = max(v[i], v[i - 1]);
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