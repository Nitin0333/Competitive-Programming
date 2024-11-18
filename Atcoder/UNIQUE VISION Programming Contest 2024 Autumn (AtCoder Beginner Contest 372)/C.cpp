#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	
	int ans = 0;
	string match = "ABC";
	for (int i = 1; i < n - 1; i++) {
		int mtch = 0;
		
		for (int j = 0; j < 3; j++)
			mtch += s[i + j] == match[j];
		
		if (mtch == 3)
			ans++;
	}
	
	while (q--) {
		int in;
		char ch;
		cin >> in >> ch;
		string t = "";
		if (in + 2 <= n) {
			t = s.substr(in, 3);
			if (t == match)
				ans--;
			t = "";
		}
		if (in - 1 >= 1 && in + 1 <= n) {
			t = s.substr(in - 1, 3);
			// debug(t);
			if (t == match)
				ans--;
			t = "";
		}
		if (in - 2 >= 1) {
			t = s.substr(in - 2, 3);
			if (t == match)
				ans--;
			t = "";
		}
		
		s[in] = ch;
		
		if (in + 2 <= n) {
			t = s.substr(in, 3);
			if (t == match)
				ans++;
			t = "";
		}
		if (in - 1 >= 1 && in + 1 <= n) {
			t = s.substr(in - 1, 3);
			// debug(t);
			if (t == match)
				ans++;
			t = "";
		}
		if (in - 2 >= 1) {
			t = s.substr(in - 2, 3);
			if (t == match)
				ans++;
			t = "";
		}
		
		cout << ans << endl;
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