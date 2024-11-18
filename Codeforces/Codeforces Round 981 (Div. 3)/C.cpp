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
	
	function<bool(int , vector<int>)>chk =[&](int val, vector<int> v) {
		int ch = 0;
		
		return ch <= val;
	};
	
	int l = 0, r = n - 1, ans = n;
	while (l <= r) {
		int md = (l + r) / 2;
		if (chk(md, v)) {
			ans = md;
			l = md - 1;
		}
		else {
			r = md + 1;
		}
	}
	cout << ans << endl;
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