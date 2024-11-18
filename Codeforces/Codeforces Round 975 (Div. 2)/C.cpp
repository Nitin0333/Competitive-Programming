#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n;
	long long k;
	cin >> n >> k;
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end(), greater<long long>());
	
	long long sum = accumulate(v.begin(), v.end(), 0ll);

	for (int i = n; i; i--) {
	    long long req = max(v[0], (sum + i - 1) / i);
	    req *= i;
	    if (req - sum <= k) {
	        cout << i << endl;
	        return;
	    }
	}
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