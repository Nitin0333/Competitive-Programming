#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int a, b, ans = 0;
	cin >> a >> b;
	
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			int sum = a - 2 * i + 2 * b - 4 * j;
			if (sum == 0)
				ans = 1;
		}
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