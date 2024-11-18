#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

class Compare {
public:
	bool operator()(vector<long long> a, vector<long long> b) {
		if (a[1] == b[1]) {
			if (a[2] == b[2])
				return a[0] < b[0];
			return a[2] < b[2];
		}
		return a[1] > b[1];
	}
};

void solve() {
	int n, m, h;
	cin >> n >> m >> h;
	
	vector<int> hr(n);
	for (int i = 0; i < h; i++) {
		int a;
		cin >> a;
		hr[a - 1]++;
	}
	
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	long long inf = 1e15;
	
	function<void(int, vector<long long>&)>bfs =[&](int s, vector<long long>& dis) {
		priority_queue<vector<long long >, vector<vector<long long>>, Compare> pq;
		vector<long long> hdis(n + 1, inf);
		
		dis[s] = 0;
		if (hr[s])
			hdis[s] = 0;
		pq.push({s, 0ll, hr[s]});
		
		while (!pq.empty()) {
			auto j = pq.top();
			pq.pop();

			if (j[2]) {
				if (hdis[j[0]] < j[1])
					continue;
			}
			else {
				if (dis[j[0]] < j[1])
					continue;
			}
			
			for (auto x : g[j[0]]) {
				if (j[2]) {
					if (hdis[x.first] > x.second / 2 + j[1]) {
						hdis[x.first] = x.second / 2 + j[1];
						pq.push({x.first, hdis[x.first], j[2]});
					}
				}
				else {
					if (dis[x.first] > x.second + j[1]) {
						dis[x.first] = x.second + j[1];
						pq.push({x.first, dis[x.first], hr[x.first]});
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++)
			dis[i] = min(dis[i], hdis[i]);
	};
	
	vector<long long> dis1(n, inf), dis2(n, inf);
	long long ans = inf;
	
	bfs(0, dis1);
	bfs(n - 1, dis2);

	for (int i = 0; i < n; i++) {
		ans = min(ans, max(dis1[i], dis2[i]));
	}
	
	if (ans == inf)
		ans = -1;
	
	cout << ans << endl;
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