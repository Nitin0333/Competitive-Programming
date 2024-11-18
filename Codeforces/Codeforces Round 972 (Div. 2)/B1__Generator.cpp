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
	int n = rand() % 100 + 1;
	cout << n << " 2 1" << endl;
	cout << rand() % n + 1 << " " << rand() % n + 1 << endl;
	cout << rand() % n + 1 << endl;
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