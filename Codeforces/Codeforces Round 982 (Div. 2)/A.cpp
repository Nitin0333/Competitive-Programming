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
	
	int a = 0, b = 0;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a = max(a, x);
		b = max(b, y);
	}
	
	cout << 2 * (a + b) << endl;
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