#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edge(m, vector<int> (3));
	vector<vector<pair<int, int>>> g(n);
	
	for (int i = 0; i < m; i++) {
		cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
		edge[i][0]--, edge[i][1]--;
		
		int a = edge[i][0], b = edge[i][1], c = edge[i][2];
		
		g[a].push_back({b, c});
		g[b].push_back({a, -c});
	}
	
	long long inf = 1e15;
	
	vector<long long> val(n, inf);
	
	function<void(int)>bfs =[&](int s) {
		val[s] = 0;
		queue<int> q;
		q.push(s);
		
		while (!q.empty()) {
			int j = q.front();
			q.pop();
			
			for (auto x : g[j]) {
				if (val[x.first] == inf) {
					val[x.first] = x.second + val[j];
					q.push(x.first);
				}
			}
		}
	};
	
	for (int i = 0; i < n; i++) {
		if (val[i] == inf) {
			bfs(i);
		}
	}

	for (auto x : edge) {
		assert(val[x[1]] - val[x[0]] == x[2]);
	}
	
	for (auto x : val)
		cout << x << " ";
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