#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long n, b, c;
	cin >> n >> b >> c;
	
	if (b == 0) {
		if (c >= n - 2) {
			cout << n - (c <= n - 1) << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		if (c >= n) {
			cout << n << endl;
		}
		// else if (b == 1) {
		// 	cout << c << endl;
		// }
		else {
			cout << n - 1 - (n - c - 1) / b << endl;
		}
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
// 20 18 16 14 12 10 8 6 4
// 0  1  2  3  5  7  8 6 4

// 4 -> 2
// 4 -> 2

