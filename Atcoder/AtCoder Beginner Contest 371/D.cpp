#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, q;
	cin >> n;
	
	vector<int> v(n + 1, INT_MIN);
	vector<long long> pre(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	
	cin >> q;
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		int in1 = lower_bound(v.begin(), v.end(), l) - v.begin() - 1;
		int in2 = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
		cout << pre[in2] - pre[in1] << endl;
	}
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