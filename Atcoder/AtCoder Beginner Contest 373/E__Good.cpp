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
	
	vector<int> ans(n, -1);
	
	int sum = accumulate(v.begin(), v.end(), 0);
	
	k -= sum;
	
	if (n == m) {
		for (int i = 0; i < n; i++)
			cout << "0 " ;
		return;
	}

	for (int i = 0; i < n; i++) {
		vector<int> t;
		
		for (int j = 0; j < n; j++)
			if (j == i)
				continue;
			else 
				t.push_back(v[j]);
			
			sort(t.begin(), t.end(), greater<int>());

			function<bool(int, int)>chk =[&](int val, int lft) {
				int req = 0;
				for (int i = 0; i < m; i++) {
					req += max(0, val + 1 - t[i]);
				}

				return req > lft;
			};
			
		for (int j = 0; j <= k; j++) {
			if (chk(v[i] + j, k - j)) {
				ans[i] = j;
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
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