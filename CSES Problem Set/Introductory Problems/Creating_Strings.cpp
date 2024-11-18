#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

string s;

set<string> prm;

void generate(int msk, int& n, string t) {
	if (msk == (1 << n) - 1)
		prm.insert(t);
	
	for (int i = 0; i < n; i++) {
		if ((msk >> i) & 1)
			continue;
		generate(msk | (1 << i), n, t + s[i]);
	}
}

void solve() {
	cin >> s;
	
	int n = s.length();

	string t = "";
	
	generate(0, n, t);
	
	cout << prm.size() << endl;
	for (auto x : prm)
		cout << x << endl;
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