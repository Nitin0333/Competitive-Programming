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
	
	if (n <= 2) {
		cout << -1 << endl;
		return;
	}
	
	sort(v.begin(), v.end());
	
	long long sum = accumulate(v.begin(), v.end(), 0ll);
	long long t = v[n / 2] * 2ll * n;
	
	cout << max(0ll, t - sum + 1) << endl;
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