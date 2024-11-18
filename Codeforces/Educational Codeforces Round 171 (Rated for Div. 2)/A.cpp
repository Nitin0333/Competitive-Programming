#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	
	cout << "0 0 " << min(x, y) << " " << min(x, y) << endl;
	cout << "0 " << min(x, y) << " " << min(y, x) << " 0" << endl;
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