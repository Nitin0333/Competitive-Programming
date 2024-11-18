#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	string s;
	
	int ans = 0;
	
	for (int i = 1; i <= 12; i++) {
		cin >> s;
		
		int sz = s.length();
		ans += sz == i;
	}
	
	cout << ans;
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