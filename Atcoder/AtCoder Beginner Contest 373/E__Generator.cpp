#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	srand(time(NULL));
	
	int n = rand() % 10 + 4, m = rand() % n + 1;

	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		v[i] = rand() % 10 + 1;
	}
	
	int sum = accumulate(v.begin(), v.end(), 0), k = sum + rand() % 10 + 1;
	
	cout << n << " " << m << " " << k << endl;
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
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