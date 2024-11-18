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
	for (int i = 1; i < n; i++) {
		int a;
		cin >> a;
		v[a]++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (v[i] == 0)
			cout << i;
	}
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