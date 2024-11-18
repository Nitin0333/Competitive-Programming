#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int l, n, m;
	cin >> l >> n >> m;
	vector<int> v(l);
	for (int i = 0; i < l; i++)
		cin >> v[i];
	vector<vector<int>> mat(n, vector<int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
		
	set<int> s;
	vector<int> t = v;
	v.clear();
	for (int i = 0; i < l; i++) {
		if (s.find(t[i]) == s.end()) {
			v.push_back(t[i]);
			s.insert(t[i]);
		}
		else
			break;
	} 
	l = v.size();
	
	vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (l, -1)));
	
	function<int(int, int, int)>fun =[&](int i, int j, int k) {
		// debug(i, j, k);
		if (i >= n || j >= m || k >= l) {
			return 1 ^ (k % 2);
		}
		if (dp[i][j][k] == -1) {
			int a = k % 2;
			dp[i][j][k] = 1 ^ a;
			for (int i1 = i; i1 < n; i1++) {
				int f = 0;
				for (int j1 = j; j1 < m; j1++) {
					if (v[k] == mat[i1][j1]) {
						int val = fun(i1 + 1, j1 + 1, k + 1);
						if (val == a) {
							dp[i][j][k] = val;
							f = 1;
							break;
						}
					}
				}
				if (f)
					break;
			}
		}
		return dp[i][j][k];
	};
	
	cout << (fun(0, 0, 0) == 0 ? 'T' : 'N') << endl;
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