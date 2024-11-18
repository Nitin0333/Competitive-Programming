#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 0; i < m; i++) {
		int a;
		char ch;
		cin >> a >> ch;
		if (ch == 'F' || v[a])
			cout << "No" << endl;
		else {
			cout << "Yes" << endl;
			v[a] = 1;
		}
	}	
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