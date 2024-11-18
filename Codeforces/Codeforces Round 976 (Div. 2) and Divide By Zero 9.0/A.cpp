#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

template <typename t>
t power(t a, long long b) {
	t res = 1;
	while (b > 0) {
		if (1 & b)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void solve() {
	long long x, y;
	cin >> x >> y;
	
	long long ans = 0;
	
	if (y == 1 || x < y) {
		cout << x << endl;
		return;
	}
	
	while (x > 0) {
		int i = 0;
		while (power(y, i) <= x) {
			i++;
		}
		i--;
		long long res = power(y, i);
		ans += x / res;
		x %= res;
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