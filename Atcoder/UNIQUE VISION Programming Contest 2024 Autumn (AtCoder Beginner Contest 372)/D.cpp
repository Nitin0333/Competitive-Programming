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
	
	vector<int> ans(n);
	deque<int> dq;
	
	for (int i = n - 1; i > -1; i--) {
		ans[i] = dq.size();
		while (!dq.empty() && dq.back() < v[i])
			dq.pop_back();
		dq.push_back(v[i]);
	}
	
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