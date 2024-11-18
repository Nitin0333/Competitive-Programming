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
	
	vector<int> v(26);
	
	for (int i = 0; i < 26; i++) {
		v[s[i] - 'A'] = i + 1;
	}
	
	int ans = 0;
	
	for (int i = 1; i < 26; i++)
		ans += abs(v[i] - v[i - 1]);
	
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