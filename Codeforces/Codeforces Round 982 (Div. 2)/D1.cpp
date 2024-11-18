#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<long long> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	
	vector<long long> sol(n, - 1);

	int l = 0, r = m - 1;
	for (int i = n - 1; i > -1; i--) {
		int in = -1;
		
		int l1 = l, r1 = r;
		while (l1 <= r1) {
			int md = (l1 + r1) / 2;
			if (b[md] >= a[i]) {
				in = md;
				l1 = md + 1;
			}
			else 
				r1 = md - 1;
		}
		
		debug(i);
		
		r = min(r1, r);
		
		if (in == -1) {
			cout << -1 << endl;
			return;
		}
		
		sol[i] = in;
	}
	
	long long ans = 0, lst = 0;
	vector<long long> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i] = a[i];
		if (i)
			pre[i] += pre[i - 1];
	}
	
	int i = 0;
	debug("hi");
	while (i < n) {
		int nxt = upper_bound(pre.begin(), pre.end(), lst + b[sol[i]]) - pre.begin();
		ans += m - 1 - sol[i];
		if (nxt - 1 >= 0 && nxt < n)
			lst = pre[nxt - 1];
		i = nxt;
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