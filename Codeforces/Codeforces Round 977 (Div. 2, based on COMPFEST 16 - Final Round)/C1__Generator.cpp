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
	
	int n = rand() % 10 + 1, m = n + 5, q = 0;
	
	cout << n << " " << m << " " << q << endl;
	
	set<int> s;
	
	for (int i = 0; i < n; i++) {
		int val = rand() % n + 1;
		while (s.find(val) != s.end()) {
			val++;
			if (val > n)
				val -= n;
		}
		s.insert(val);
		cout << val << " ";
	}
	cout << endl;
	
	for (int i = 0; i < m; i++) {
		cout << rand() % n + 1 << " ";
	}
	cout << endl;
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