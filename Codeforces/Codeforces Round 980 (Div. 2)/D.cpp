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
    
    vector<int> a(n), b(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        if (b[i] > i) {
            g[i].push_back({b[i], a[i]});
        }
        if (i)
            g[i].push_back({i -1, 0});
    }
    
    long long inf = 1e15;
    vector<long long> dis(n, inf);
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    dis[0] = 0;
    
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        
        if (dis[x.second] < x.first)
            continue;
            
        for (auto y : g[x.second]) {
            if (dis[y.first] > y.second + x.first) {
                dis[y.first] = y.second + x.first;
                pq.push({dis[y.first], y.first});
            }
        }
    }
    
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum - dis[i]);
    }
    
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