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
	
	vector<vector<int>> v(3, vector<int> (n));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
			v[i][j]--;
			mk[i][v[i][j]] = j;
		}
	}
	
	int st = 0;
	vector<pair<char, int>> ans;
	while (st < n - 1) {
		int t = st;
		
		for (int i = 0; i < 3; i++) {
			if (v[i][st] > v[i][st + 1]) {
				st++;
				if (i == 0) {
					ans.push_back({'q', st});
				}
				else if (i == 1) {
					ans.push_back({'k', st});
				}
				else {
					ans.push_back({'j', st});
				}
				break;
			}
		}
		
		if (t == st)
			break;
	}
	
	if (st == n - 1) {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x.first << " " << x.second + 1 << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
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