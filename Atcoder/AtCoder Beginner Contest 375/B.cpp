#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long double ans = 0;
	
	int n;
	cin >> n;
	long double x = 0, y = 0;
	
	for (int i = 0; i <= n; i++) {
		long double nx = 0, ny = 0;
		if (i < n)
			cin >> nx >> ny;
		
		long double x1 = nx - x, y1 = ny - y;
		
		ans += hypot(x1, y1);
		
		x = nx, y = ny;
	}
	
	cout << fixed << setprecision(20) << ans;
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