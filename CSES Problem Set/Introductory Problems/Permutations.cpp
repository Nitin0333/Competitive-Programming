#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, st = 1;
	cin >> n;
	
	if (n < 5) {
		if (n == 1)
			cout << 1 << endl;
		else if (n == 4)
			cout << "2 4 1 3" << endl;
		else
			cout << "NO SOLUTION" << endl;
		return;
	}
	
	vector<int> v(n);
	for (int i = 0; i < n; i += 2) {
		v[i] = st++;
	}

	st = n;
	
	for (int i = n - 1 - n % 2; i >= 0; i -= 2) {
		v[i] = st--;
	}
	
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
		if (i)
			assert(abs(v[i] - v[i - 1]) != 1);
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