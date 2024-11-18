#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	vector<int> pre(n), suf(n);
	vector<long long> pres(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		pres[i] = v[i];
		if (sum >= k) {
			pre[i]++;
			sum = 0;
		}
		
		if (i) {
			pre[i] += pre[i - 1];
			pres[i] += pres[i - 1];
		}
	}
	sum = 0;
	for (int i = n - 1; i > -1; i--) {
		sum += v[i];
		if (sum >= k) {
			suf[i]++;
			sum = 0;
		}
		
		if (i < n - 1) {
			suf[i] += suf[i + 1];
		}
	}
	
	long long ans = -1;
	
	for (int i = 0; i < n; i++) {
		if (pre[i] == m) {
			ans = max(ans, pres[n - 1] - pres[i]);
			break;
		}
		int l = i + 1, r = n - 1, in = -1;
		while (l <= r) {
			int md = (l + r) / 2;
			if (pre[i] + suf[md] >= m) {
				in = md;
				l = md + 1;
			}
			else {
				r = md - 1;
			}
		}
		
		if (in != -1)
			ans = max(ans, pres[in - 1] - pres[i]);
	}
	
	for (int i = n - 1; i > 0; i--) {
		if (suf[i] == m) {
			ans = max(ans, pres[i - 1]);
		}
	}
	
	debug(pre);
	debug(suf);
	
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