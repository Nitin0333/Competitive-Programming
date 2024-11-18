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
	
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		m[x]++;
	}
	
	int ans = n;
	for (auto x : m) {
		ans = min(ans, n - x.second);
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