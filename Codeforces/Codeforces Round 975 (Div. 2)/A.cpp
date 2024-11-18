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
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i];
	
	int ans = 0, c = 0;
	for (int i = 0; i < n; i += 2) {
		ans = max(ans, v[i]);
		c++;
	}
	ans += c;
	
	int sum = 0;
	c = 0;
	
	for (int i = 1; i < n; i += 2) {
		sum = max(sum , v[i]);
		c++;
	}
	sum += c;
	
	cout << max(ans, sum) << endl;
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