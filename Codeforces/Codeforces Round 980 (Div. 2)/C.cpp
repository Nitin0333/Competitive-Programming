#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n;
	cin >> n;
	
	vector<vector<int>> g, b;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x <= y)
			g.push_back({x, y});
		else
			b.push_back({x, y});
	}
	
	sort(g.begin(), g.end(), [&](vector<int> a, vector<int> b) {
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] < b[0];
	});
	
	sort(b.begin(), b.end(), [&](vector<int> a, vector<int> b) {
		if (a[1] == b[1]) 
			return a[0] < b[0];
		return a[1] < b[1];
	});
	
	vector<int> ans;
	int i = 0, j = 0, sz1 = g.size(), sz2 = b.size();
	
	while (i < sz1 && j < sz2) {
		if (g[i][0] < b[j][1]) {
			ans.push_back(g[i][0]);
			ans.push_back(g[i][1]);
			i++;
		}
		else if (g[i][0] > b[j][1]){
			ans.push_back(b[j][0]);
			ans.push_back(b[j][1]);
			j++;

		}
		else {
			if (b[j][0] > g[i][1]) {
				ans.push_back(g[i][0]);
				ans.push_back(g[i][1]);
				i++;
			}
			else {
				ans.push_back(b[j][0]);
				ans.push_back(b[j][1]);
				j++;
			}
		}
	}
	
	while (i < sz1) {
		ans.push_back(g[i][0]);
		ans.push_back(g[i][1]);
		i++;
	}
	
	while (j < sz2) {
		ans.push_back(b[j][0]);
		ans.push_back(b[j][1]);
		j++;
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



