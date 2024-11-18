#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m;
	long long k, sum = 0;
	cin >> n >> m >> k;
	
	vector<pair<long long, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
		sum += v[i].first;
	}
	
	k -= sum;
	
	if (n == m) {
		for (int i = 0; i < n; i++) {
			cout << "0 ";
		}
		return;
	}
	
	sort(v.begin(), v.end());
	
	vector<long long> g(m + 1);
	for (int i = n - m - 1; i < n; i++) {
		g[i - n + m + 1] = v[i].first;
	}
	for (int i = 0; i < m ; i++) {
		g.push_back(g[i]);
	}
	
	int sz = g.size();
	vector<long long> pre(sz);
	for (int i = 0; i < sz; i++) {
		pre[i] = g[i];
		if (i)
			pre[i] += pre[i - 1];
	}
	
	vector<long long> ans(n);

	for (int i = 0; i < n; i++) {
		int l = 1, h = m;
		
		if (i > n - m - 1) {
			swap(g[i - n + m + 1], g[0]);
		}

		long long l1 = 0, h1 = k, a = -1;
		
		function<bool(long long)>chk =[&](long long val) {
			long long lft = k - val, tot = 0;
			
			int in = upper_bound(g.begin() + l, g.begin() + h + 1, v[i].first + val) - g.begin();
			in--;
			
			if (in < l)
				return false;
			
			int num = in - l + 1;
			if (i <= n - m - 1) {
				tot = pre[in] - pre[l - 1];
			}
			else {
				int dif = i - n + m + 1;
				if (dif > num)
					tot = pre[num - 1];
				else
					tot = pre[num] - v[i].first;
			}

			long long t = (v[i].first + val + 1) * num;
			tot = t - tot;
			
			return tot > lft;
		};
		
		while (l1 <= h1) {
			long long md = (l1 + h1) / 2;
			if (chk(md)) {
				a = md;
				h1 = md - 1;
			}
			else {
				l1 = md + 1;
			}
		}
		
		ans[v[i].second] = a;
	}
	
	for (auto x : ans)
		cout << x << " ";
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