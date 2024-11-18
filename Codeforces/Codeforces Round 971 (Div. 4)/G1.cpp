#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] -= i;
	}
	
	vector<int> ans(n + 1);
	map<int, int> m;
	multiset<int> s;

	for (int i = 1; i <= n; i++) {
		int val = 0;
		
		if (m.find(v[i]) != m.end() && m[v[i]] != 0) {
			val = m[v[i]];
			s.erase(s.find(val));
		}
		m[v[i]]++;
		s.insert(val + 1);
		
		if (i > k) {
			val = m[v[i - k]];
			s.erase(s.find(val));
			if (val - 1 > 0)
				s.insert(val - 1);
			m[v[i - k]]--;
		}

		if (i >= k)
			ans[i] = *s.rbegin();
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		cout << k - ans[r] << endl;
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