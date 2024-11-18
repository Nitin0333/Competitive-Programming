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
	set<int> a, b;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (y == 0)
			a.insert(x);
		else
			b.insert(x);
	}
	long long ans = 0;
	for (auto x : a) {
		if (b.find(x) != b.end())
			ans += (int)b.size() - 1;
		if (b.find(x - 1) != b.end() && b.find(x + 1) != b.end())
			ans++;
	}
	for (auto x : b) {
		if (a.find(x) != a.end())
			ans += (int)a.size() - 1;
		if (a.find(x - 1) != a.end() && a.find(x + 1) != a.end())
			ans++;
	}
	cout << ans << endl;
	debug(ans);
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