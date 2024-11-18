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
		long long a;
		cin >> a;
		
		long long ans = 0;
		
		auto it = lower_bound(v.begin(), v.end(), a);
		auto it1= upper_bound(v.begin(), v.end(), a);
		
		if (it1 == v.end())
			ans = n - v.back();
		else if (a < v[0]) 
			ans = v[0] - 1;
		else {
			it = prev(it);
			int b = *it, c = *it1;
			if (a - b > 2) {
				int dif = (a - b - 1) / 2;
				ans += dif;
				b += dif;
				c -= dif;
				a -= dif;
			}
			// debug(a, v[0], v[1]);
			if (c - a > 2) {
				int dif = (c - a - 1) / 2;
				ans += dif;
				b += dif;
				c -= dif;
				a += dif;
			}
			// debug(a, v[0], v[1]);
			ans += min(a - b, c - a);
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

