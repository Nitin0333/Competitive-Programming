#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long x, y;
	cin >> x >> y;
	
	long long mx = max(x, y), bs = mx * mx;
	
	if (mx % 2) {
		cout << bs - x + 1 - mx + y << endl;
	}
	else {
		cout << bs - y + 1 - mx + x << endl;
	}
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