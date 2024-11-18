#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long n;
	cin >> n;
	
	while (n != 1) {
		cout << n << " ";
		if (n % 2)
			n = n * 3 + 1;
		else
			n /= 2;
	}
	
	cout << 1;
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