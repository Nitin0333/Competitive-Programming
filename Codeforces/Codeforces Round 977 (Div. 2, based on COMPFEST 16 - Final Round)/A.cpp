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
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	
	long long avg = (v[0] + v[1]) / 2;
	for (int i = 2; i < n; i++) {
		avg = (avg + v[i]) / 2;
	}
	
	cout << avg << endl;
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