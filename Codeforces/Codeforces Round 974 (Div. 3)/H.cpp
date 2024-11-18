#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int N = 1e6 + 1;
vector<unsigned long long> val(N);

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<unsigned long long> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[i] = v[i - 1] ^ val[a];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		
		if (v[l] == v[r])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 1; i < N; i++) 
		val[i] = rng();
	
	int t = 1;
	cin >> t;
	
	while (t--) {
		solve();
	}
}

