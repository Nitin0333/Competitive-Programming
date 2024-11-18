#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	cout << 1 << endl;
	
	srand(time(NULL));
	
	int n = rand() % 10 + 1, k = rand() % 10 + 1;
	cout << n << " " << k << endl;
	
	for (int i = 0; i < n; i++) {
		cout << rand() % 20 + 1 << " ";
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