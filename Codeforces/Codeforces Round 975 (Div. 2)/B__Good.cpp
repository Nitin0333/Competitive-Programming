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
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int mx = v.back() + 1;
	
	vector<int> Q(q);
	for (int i = 0; i < q; i++)
		cin >> Q[i];
	
	if (mx > 50) {
		cout << "NO" << endl;
		return;
	}
	
	vector<int> mk(mx + 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int c = v[i];
			while (c <= v[j]) {
				mk[c]++;
				c++;
			}
		}
	}
	
	debug(mk);
	
	cout << "NO" << endl;
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