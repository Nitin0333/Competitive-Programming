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
	
	vector<int> ans(n + 1);
	
	if (n % 2) {
		if (n < 27) {
			cout << -1 << endl;
			return;
		}
		ans[0] = ans[9] = ans[25] = 1;
		ans[22] = ans[26] = 2;
		int num = 3;
		for (int i = 0; i < n; i++) {
			if (ans[i] != 0)
				continue;
			ans[i] = ans[i + 1] = num;
			num++;
		}
	}
	else {
		int num = 1;
		for (int i = 0; i < n; i += 2) {
			ans[i] = ans[i + 1] = num;
			num++;
		}
	}
	// map<int, vector<int>> m;
	// for (int i = 0 ; i < n; i++) {
	// 	m[ans[i]].push_back(i);
	// }
	
	// for (auto x : m) {
	// 	vector<int> t = x.second;
	// 	int sz = t.size();
	// 	assert(sz > 1);
		
	// 	for (int i = 0; i < sz; i++) {
	// 		for (int j = i + 1; j < sz; j++) {
	// 			int dis = t[j] - t[i], sq = sqrt(dis);
	// 			assert(dis == sq * sq);
	// 		}
	// 	}
	// }
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
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
