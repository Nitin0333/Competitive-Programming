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
	vector<int> ans;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == '#')
			ans.push_back(1);
		else if (s[1] == '#')
			ans.push_back(2);
		else if (s[2] == '#')
			ans.push_back(3);
		else
			ans.push_back(4);
	}
	for (int i = n - 1; i > -1; i--)
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