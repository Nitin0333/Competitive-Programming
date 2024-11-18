#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<int> ord(n);
	for (int i = 0; i < n; i++) {
		cin >> ord[i];
	}
	
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	
	vector<int> ord1, mk(n + 1);
	for (int i = 0; i < m; i++) {
		if (mk[p[i]] == 0) {
			ord1.push_back(p[i]);
			mk[p[i]] = 1;
		}
	}
	
	int sz = ord1.size();
	
	for (int i = 0; i < sz; i++) {
		if (ord1[i] != ord[i]) {
			cout << "TIDAK" << endl;
			return;
		}
	}
	
	cout << "YA" << endl;
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