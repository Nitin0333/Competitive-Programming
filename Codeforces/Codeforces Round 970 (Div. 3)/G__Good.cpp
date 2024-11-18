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
	
	int gcd = 0;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		gcd = __gcd(gcd, v[i]);
	}
	
	set<int> s;
	
	for (int i = 0; i < n; i++) {
		s.insert(i * gcd);
	}
	
	if (n == 1) {
		s.clear();
		s.insert(gcd);
	}
	
	int ans = -1;
	
	while (k > 0) {
		ans++;
		if (s.find(ans) == s.end()) {
			k--;
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