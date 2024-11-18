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
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	vector<long long> pre(n + 1), ppre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + v[i];
		ppre[i + 1] = pre[i + 1] + ppre[i];
	}
	
	vector<long long> in(n + 1);
	for (int i = 0; i < n; i++) {
		in[i + 1] += n - i;
		if (i + 2 <= n)
			in[i + 2] += in[i + 1];
	}
	
	debug(in);
	debug(pre);
	debug(ppre);
	
	vector<long long> scpre(n + 1);
	long long sum = 0, sc = 0;
	for (int i = 2; i <= n; i++) {
		sum += (in[i] - in[i - 1]) * v[i - 2];
		sum -= sc;
		sc += v[i - 2];
		debug(i, sum, sc);
		scpre[i] = scpre[i - 1] + sum;
	}
	
	debug(scpre);
	
	function<long long(long long)>query =[&](long long ind) {
		long long s  = ind / n + ind % n;
		if (ind % n == 0)
			s = 0;
		long long res = ppre[n] * (ind / n) + pre[s];
		int i = upper_bound(in.begin(), in.end(), ind) - in.begin() - 1;
		debug(ind, i, res);
		res -= pre[i] * (ind - in[i]);
		res -= scpre[i];
		return res;
	};
	
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		cout << query(r) - query(l - 1) << endl;
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
