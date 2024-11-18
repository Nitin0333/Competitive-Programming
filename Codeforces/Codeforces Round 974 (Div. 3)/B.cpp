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
	
	int l = n - k + 1;
	int od = (n - l) / 2;
	
	if (n % 2 != 0 || l % 2 != 0)
		od++;
	
	if (od & 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
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