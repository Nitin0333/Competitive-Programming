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
	
	int gm;
	cin >> gm;
	vector<vector<int>> ge(gm, vector<int> (2));
	for (int i = 0; i < gm; i++) {
		cin >> ge[i][0] >> ge[i][1];
		ge[i][0]--, ge[i][1]--;
	}
	
	vector<int> prm(n);
	iota(prm.begin(), prm.end(), 0);
	
	int he;
	vector<vector<int>> g(n);
	cin >> he;
	for (int i = 0; i < he; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int ans = INT_MAX;
	
	vector<vector<int>> cst(n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cin >> cst[i][j];
			cst[j][i] = cst[i][j];
		}
	}
	
	debug(ge);
	debug(g);
	
	vector<int> t = prm;
	do {
		vector<vector<int>> g1(n);
		for (auto x : ge) {
			g1[t[x[0]]].push_back(t[x[1]]);
			g1[t[x[1]]].push_back(t[x[0]]);
		}
		int ct = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				int f = 0;
				for (auto x : g1[i]) {
					if (g[i][j] == x) {
						f = 1;
						break;
					}
				}
				if (f == 0)
					ct += cst[g[i][j]][i];
			}
			for (int j = 0; j < g1[i].size(); j++) {
				int f = 0;
				for (auto x : g[i]) {
					if (g1[i][j] == x) {
						f = 1;
						break;
					}
				}
				if (f == 0)
					ct += cst[g1[i][j]][i];
			}
		}
		ans = min(ans, ct / 2);
		next_permutation(t.begin(), t.end());
	}while(t != prm);
	
	cout << ans;
	
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