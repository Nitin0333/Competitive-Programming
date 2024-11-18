#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	srand(time(NULL));
	int n = rand() % 20 + 1, m = rand() % 20 + 1, k = rand() % 20 + 1;
	
	cout << n << " " << m << " " << k << endl;
	
	for (int i = 0; i < m; i++) {
		int a = rand() % n + 1, b = rand() % n + 1;
		if (a == b)
			b = (b + 5) % n + 1;
		cout << a << " " << b << endl;
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