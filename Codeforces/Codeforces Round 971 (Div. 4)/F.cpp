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
	
	for (int i = 0; i < n; i++)
		v.push_back(v[i]);
	
	vector<long long> pre(2 * n + 1);
	
	for (int i = 0; i < 2 * n; i++) {
		pre[i + 1] = pre[i] + v[i];
	}
	
	debug(pre);
	
	function<long long(long long)>query =[&](long long in) {
		long long ans = 0, div = in / n;
		ans += pre[n] * div;
		ans += pre[div + in % n] - pre[div];
		return ans;
	};
	
	while (q--) {
		long long a, b;
		cin >> a >> b;
		a--;
		
		cout << query(b) - query(a) << endl;
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