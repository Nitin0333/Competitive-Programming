#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, n1;
	cin >> n;
	n1 = log2(n);
	
	long long ans = 0;
	
	vector<int> v;

	if ((n & (n - 1)) == 0) {
		ans = (1ll << (n1 + 1)) - 1;
		v.push_back(2);
		v.push_back(1);
		for (int i = 3; i <= n; i++)
			v.push_back(i);
	}
	else if (((n - 1) & (n - 2)) == 0) {
		ans = n;
		v.push_back(2);
		v.push_back(1);
		for (int i = 3; i <= n; i++)
			v.push_back(i);
	}
	else {
		if (n % 2 == 0) {
			ans = (1ll << (n1 + 1)) - 1;
			
			long long lst = (1 << n1) - 1, sclst = n, thlst = n - 1;
			for (int i = 1; i <= n; i++) {
				if (i != lst && i != sclst && i != thlst)
					v.push_back(i);
			}
			v.push_back(thlst);
			v.push_back(sclst);
			v.push_back(lst);
		}
		else {
			ans = n;
			long long lst = (1 << n1) - 1, sclst = n - 1, thlst = n - 2;
			for (int i = 1; i < n; i++) {
				if (i != lst && i != sclst && i != thlst)
					v.push_back(i);
			}
			v.push_back(thlst);
			v.push_back(sclst);
			v.push_back(lst);
			v.push_back(n);
		}
	}
	
	cout << ans << endl;
	
	long long val = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i & 1)
			val |= v[i];
		else
			val &= v[i];
		cout << v[i] << " ";
	}
	cout << endl;
	
	assert(val == ans);
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


