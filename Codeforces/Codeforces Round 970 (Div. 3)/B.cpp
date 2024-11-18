#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n;
	string s;
	cin >> n >> s;
	
	int st = sqrt(n);
	if (st * st != n) {
		cout << "No" << endl;
		return;
	}
	
	int f = 1;
	vector<vector<char>> v(st, vector<char> (st));
	for (int i = 0; i < n; i++) {
		int x = i / st, y = i % st;
		if (s[i] == '1') {
			if (x != 0 && x != st - 1 && y != 0 && y != st - 1)
				f = 0;
		}
		else {
			if (x == 0 || x == st - 1 || y == 0 || y == st - 1)
				f = 0;
		}
	}
	
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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