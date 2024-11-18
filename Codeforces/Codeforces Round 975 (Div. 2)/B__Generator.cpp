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
	
	int n = rand() % 6 + 1;
	
	cout << n << " 1" << endl;
	
	set<int> s;
	for (int i = 0; i < n; i++) {
		int val = rand() % 30 + 1;
		while (s.find(val) != s.end()) {
			val = (val + 1) % 30 + 1;
		}
		s.insert(val);
	}
	
	for (auto x : s)
		cout << x << " ";
	cout << endl;
	
	cout << 1 << endl;
	
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