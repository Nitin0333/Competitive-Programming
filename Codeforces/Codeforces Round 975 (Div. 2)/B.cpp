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
	
	map<long long, int> m;

	vector<long long> str(n);
	iota(str.begin(), str.end(), 1);
	reverse(str.begin(), str.end());

	int ad = n - 1;
	
	for (int i = 0; i < n; i++) {
		str[i] *= i;
		if (i)
			m[str[i]] += v[i] - v[i - 1] - 1;
		str[i] += ad;
		ad--;
		m[str[i]]++;
	}

	for (int i = 0; i < q; i++) {
		long long a;
		cin >> a;
		if (m.find(a) == m.end())
			cout << 0 << " ";
		else 
			cout << m[a] << " ";
	}
	cout << endl;
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