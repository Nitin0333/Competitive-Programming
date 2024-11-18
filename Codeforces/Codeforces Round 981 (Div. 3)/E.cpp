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
	
	vector<int> v(n), pos(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		pos[--v[i]] = i;
	}
	
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		if (v[i] != i && v[v[i]] != i) {
			int loc = pos[pos[i]];
			swap(v[i], v[loc]);
			pos[v[loc]] = loc, pos[v[i]] = i;
			ans++;
		}
	}
	
	debug(v);
	
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
// 2 3 4 5 1
// 1 2 3 4 5
// 5 3 4 2 1
