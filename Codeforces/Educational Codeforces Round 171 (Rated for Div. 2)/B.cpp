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
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	long long ans = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		long long dif = 1;
		for (int j = 0; j < n - 1; j += 2) {
			if (j == i) {
				j--;
			}
			else if (j + 1 == i) {
				dif = max(dif, v[j + 2] - v[j]);
			}
			else {
				dif = max(dif, v[j + 1] - v[j]);
			}
		}
		ans = min(ans, dif);
	}
	
	if (n % 2 == 0) {
		ans = 0;
		for (int i = 0; i < n - 1; i += 2) {
			ans = max(ans, v[i + 1] - v[i]);
		}
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
