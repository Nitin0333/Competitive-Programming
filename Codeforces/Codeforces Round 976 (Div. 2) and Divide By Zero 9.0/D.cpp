#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

struct dsu {
	int n;
	vector<int> p;
	
	dsu(int n) {
		this->n = n;
		p = vector<int> (n + 1);
		iota(p.begin(), p.end(), 0);
	}
	
	int parent(int a) {
		if (p[a] == a)
			return a;
		return p[a] = parent(p[a]);
	}
	
	void unite(int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return;
		p[b] = a;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> st(n + 1, vector<int> (11)), stop(n + 1, vector<int> (11));
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		st[a][b]++;
		int lst = a + c * b;
		if (lst <= n)
			stop[lst][b]++;
	}
	
	dsu d(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 11; j++) {
			if (st[i][j] == 0)
				continue;
			int val = st[i][j] - stop[i][j];
			if (i + j <= n && val) {
				d.unite(i, i + j);
				st[i + j][j] += val;
			}
		}
	}
	
	set<int> s;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int p = d.parent(i);
		
		if (s.find(p) == s.end()) {
			ans++;
			s.insert(p);
		}
	}
	
	cout << ans << endl;
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
