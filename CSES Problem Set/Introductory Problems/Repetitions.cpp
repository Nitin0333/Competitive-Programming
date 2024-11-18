#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	string s;
	cin >> s;
	
	s = " " + s + " ";
	
	int ans = 0, c = 0, n = s.length();
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			ans = max(ans, c);
			c = 0;
		}
		c++;
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