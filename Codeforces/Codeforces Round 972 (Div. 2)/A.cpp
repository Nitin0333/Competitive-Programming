#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	vector<char> v = {'a', 'e', 'i', 'o', 'u'};
	string ans = "";
	int n;
	cin >> n;
	int t = n / 5, ad = n % 5;
	debug(t, ad);
	for (int i = 0; i < 5; i++) {
		int c = t + (ad != 0);
		if (ad > 0)
			ad--;
		debug(c);
		while (c > 0) {
			c--;
			ans += v[i];
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