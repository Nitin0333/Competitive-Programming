#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	string s;
	cin >> s;
	
	s = " " + s;
	
	vector<long long> v(26), cnt(26);
	
	int n = s.length();
	long long ans = 0;
	
	for (int i = 1; i < n; i++) {
		int in = s[i] - 'A';
		
		ans += cnt[in] * i - v[in] - cnt[in];
		
		v[in] += i;
		cnt[in]++;
	}
	
	cout << ans << endl;
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