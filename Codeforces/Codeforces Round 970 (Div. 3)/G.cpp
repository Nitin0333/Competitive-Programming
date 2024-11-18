#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, k;
	cin >> n >> k;
	k--;
	
	int gcd = 0;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		gcd = __gcd(gcd, v[i]);
	}
	
	for (int i = 0; i < n; i++) {
		v[i] = i * gcd;
	}
	
	int ans = 1, num = gcd - 1;
	
	if (n == 1) {
		if (k < gcd)
			cout << k << endl;
		else 
			cout << k + 1 << endl;
		return;
	}
	
	for (int i = 0; i < n - 1; i++) {
		if (k < num) {
			ans += k;
			k = 0;
			break;
		}
		k -= num;
		ans = v[i + 1] + 1;
	}
	
	cout << ans + k << endl;
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