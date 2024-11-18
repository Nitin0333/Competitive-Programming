#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int x, y;
	cin >> x >> y;
	
	if (x < y)
		swap(x, y);
	
	if ((x + y) % 3 == 0 && x <= y * 2)
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