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
	
	vector<long long> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		
		long long ans = 0;
		
		
		if (a == v[0] || a == v[1])
			ans = 0;
		else if (a > v[0] && a < v[1]) {
			// debug(a, v[0], v[1]);
			if (a - v[0] > 2) {
				int dif = (a - v[0] - 1) / 2;
				ans += dif;
				v[0] += dif;
				v[1] -= dif;
				a -= dif;
			}
			// debug(a, v[0], v[1]);
			if (v[1] - a > 2) {
				int dif = (v[1] - a - 1) / 2;
				ans += dif;
				v[0] += dif;
				v[1] -= dif;
				a += dif;
			}
			// debug(a, v[0], v[1]);
			ans += min(a - v[0], v[1] - a);
		}
		else if (a < v[0]) {
			ans = v[0] - 1;
		}
		else {
			ans = n - v[1];
		}
		
		cout << ans << endl;
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
