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
	
	if (n == 1 || n == 3) {
		cout << -1 << endl;
		return;
	}
	
	for (int i = 0; i < (n - 2); i++) {
		if (i == n - 4 && n % 2)
			cout << 6;
		else
			cout << 3;
	}
	
	cout << 66 << endl;
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