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
	
	string s;
	cin >> s;
	
	int ans = 0;
	
	for (int i = 1; i < n - 1; i++) {
		ans += (s[i] == '.' && s[i - 1] == '#' && s[i + 1] == '#');
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