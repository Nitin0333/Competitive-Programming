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
	vector<double> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	if (n <= 2) {
		cout << - 1 << endl;
		return;
	}
	int ans = 0;
	sort(v.begin(), v.end());
	
	long long sum = accumulate(v.begin(), v.end(), 0ll);
	
	for (int i = 0; ; i++) {
		long double div = (sum + i * 1.0) / (2 * n);
		// debug(div, i);
		if (div > v[n / 2]) {
			ans = i;
			break;
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