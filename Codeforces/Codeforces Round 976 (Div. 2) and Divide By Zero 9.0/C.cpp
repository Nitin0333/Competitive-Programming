#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long b, c, d;
	cin >> b >> c >> d;
	
	long long a = 0;
	
	for (int i = 0; i <= 60; i++) {
		long long b1 = (b >> i) & 1, c1 = (c >> i) & 1, d1 = (d >> i) & 1;

		if (b1 == 0 && c1 == 1 && d1 == 1) {
			cout << - 1 << endl;
			return;
		}
		else if (b1 == 1 && c1 == 0 && d1 == 0) {
			cout << -1 << endl;
			return;
		}
		else if (b1 == 0 && c1 == 0 && d1 == 1) {
			a |= (1ll << i);
		}
		else if(b1 == 1 && c1 == 1 && d1 == 0) {
			a |= (1ll << i);
		}
	}
	
	long long res = (a | b) - (a & c);
	
	assert(res == d);
	
	cout << a << endl;
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
