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
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
	}
	
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		p[i]--;
	}
	
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j] == i)
				Q.push(j);
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (v[p[i]] == n + 1 || (!Q.empty() && Q.front() == p[i])) {
			v[p[i]] = n + 1;
			if (!Q.empty() && Q.front() == p[i]) {
				Q.pop();
			}
		}
		else {
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