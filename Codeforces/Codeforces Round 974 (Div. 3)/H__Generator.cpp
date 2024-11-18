#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	cout << 1 << endl;
	
	srand(time(NULL));
	
	int n = rand() % 20 + 5, q = rand() % 20 + 10;
	
	cout << n << " " << q << endl;
	
	for (int i = 0; i < n; i++) {
		cout << rand() % 20 + 1 << " ";
	}
	cout << endl;
	
	while (q--) {
		int l = rand() % n + 1, r = rand() % n + 1;
		
		cout << min(l, r) << " " << max(l, r) << endl;
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