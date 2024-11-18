#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	char a, b, c;
	cin >> a >> b >> c;
	if (a == '>') {
		if (b == '>') {
			if (c == '>')
				cout << 'B';
			else
				cout << 'C';
		}
		else
			cout << 'A';
	}
	else {
		if (c == '>') {
			if (b == '>')
				cout << 'A';
			else
				cout << 'C';
		}
		else
			cout << 'B';
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