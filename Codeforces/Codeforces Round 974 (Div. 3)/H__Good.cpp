#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		int a = 0, b = 0;
		
		vector<int> t;
		for (int i = l; i <= r; i++)
			t.push_back(v[i]);
		
		sort(t.begin(), t.end(), greater<int>());
		
		for (int i = 0; i < t.size(); i++) {
			if (i & 1)
				b += t[i];
			else
				a += t[i];
		}
		
		if (a <= b)
			cout << "YES" << endl;
		else 
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