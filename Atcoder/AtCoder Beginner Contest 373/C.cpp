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
	
	vector<int> a(n), b(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	sort(a.begin(), a.end()), sort(b.begin(), b.end());
	
	cout << a[n - 1] + b[n - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;
	
	while (t--) {
		solve();
	}
}