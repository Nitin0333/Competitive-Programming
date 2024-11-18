#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

struct dsu {
	int n;
	vector<int> p, bl;
	
	dsu(string s) {
		n = s.length();
		p = vector<int> (n);
		iota(p.begin(), p.end(), 0);
		bl = vector<int> (n);
		for (int i = 0 ; i < n; i++) 
			bl[i] = s[i] - '0' == 0;
	}
	
	int parent(int a) {
		if (p[a] == a)
			return a;
		return p[a] = parent(p[a]);
	}
	bool unite(int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return false;
		p[b] = a;
		bl[a] += bl[b];
		return true;
	}
};

void solve() {
	int n;
	cin >> n;
	
	vector<int> prm(n);
	for (int i = 0; i < n; i++) {
		cin >> prm[i];
		prm[i]--;
	}
	
	string s;
	cin >> s;
	
	vector<int> ans(n);
	dsu d(s);

	for (int i = 0; i < n; i++) {
		int j = i;
		
		while (d.unite(j, prm[j])) {
			j = prm[j];
		}

		j = d.parent(j);
		
		ans[i] = d.bl[j];
	}

	for (auto x : ans)
		cout << x << " ";
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