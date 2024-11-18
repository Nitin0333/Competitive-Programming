#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

struct dsu {
	vector<int> p;
	vector<vector<int>> gt;
	int n;
	
	dsu (int n) {
		this->n = n;
		p = vector<int> (n + 1);
		iota(p.begin(), p.end(), 0);
		gt = vector<vector<int>> (n + 1);
		for (int i = 1; i <= n; i++) 
			gt[i].push_back(i);
	}
	int parent(int a) {
		if (p[a] == a)
			return a;
		return p[a] = parent(p[a]);
	}
	void unite(int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return;
		p[b] = a;
		while (gt[a].size() < 10 && !gt[b].empty()) {
			gt[a].push_back(*gt[b].begin());
			gt[b].erase(gt[b].begin());
		}
		sort(gt[a].begin(), gt[a].end(), greater<int>());
		while (!gt[b].empty()) {
			if (gt[a].back() >= gt[b][0])
				break;
			gt[a][(int)gt[a].size() - 1] = gt[b][0];
			gt[b].erase(gt[b].begin());
			sort(gt[a].begin(), gt[a].end(), greater<int>());
		}
	}
	int query(int a, int k) {
		a = parent(a);
		if (gt[a].size() < k)
			return -1;
		return gt[a][k - 1];
	}
};

void solve() {
	int n, q;
	cin >> n >> q;
	
	dsu d(n + 1);
	
	for (int i = 1; i <= q; i++) {
		// cout << "query " << i << endl;
		
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			d.unite(b, c);
		}
		else {
			cout << d.query(b, c) << endl;
		}
		// debug(d.gt);
		// debug(d.p);
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