#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	long long K;
	cin >> K;
	
	unsigned long long l = 1, r = 1e9, ans = 0;

	while (l <= r) {
		unsigned long long md = (l + r) / 2;
		unsigned long long sum = md * (md + 1);
		
		if (sum >= K) {
			ans = md;
			r = md - 1;
		}
		else
			l = md + 1;
	}
	
	unsigned long long op = ans + K;
	
	cout << op << endl;
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