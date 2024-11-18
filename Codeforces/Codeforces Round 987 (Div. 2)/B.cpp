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
	
	bool ans = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ans &= abs(x - i) <= 1;
	}
	
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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