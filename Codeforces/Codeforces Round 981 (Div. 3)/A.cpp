#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, ch = 1, pos = 0;
	cin >> n;
	
	while (abs(pos) <= n) {
		int val = 2 * ch - 1;
		if (ch % 2)
			pos -= val;
		else
			pos += val;
		ch++;
	}
	
	if (ch % 2)
		cout << "Kosuke" << endl;
	else 
		cout << "Sakurako" << endl;
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