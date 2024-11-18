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
	
	vector<vector<int>> v(n, vector<int> (n)), prop(n, vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	
	long long ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] += prop[i][j];
			if (v[i][j] < 0) {
				ans += abs(v[i][j]);
				prop[i][j] += abs(v[i][j]);
			}
			
			if (i + 1 < n && j + 1 < n)
				prop[i + 1][j + 1] += prop[i][j];
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