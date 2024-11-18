#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int m;
	cin >> m;
	
	vector<int> ans;
	vector<int> t;
	while (m) {
		t.push_back(m % 3);
		m /= 3;
	}
	
	for (int i = 0; i < (int)t.size(); i++) {
		while (t[i] > 0) {
			ans.push_back(i);
			t[i]--;
		}
	}
	
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << " ";
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