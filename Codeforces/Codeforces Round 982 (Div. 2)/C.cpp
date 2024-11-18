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
	
	vector<long long> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	
	vector<pair<long long, int>> len(n + 1);
	for (int i = 2; i <= n; i++) {
		len[i].first = v[i] + i - 1;
		len[i].second = i;
	}
	
	sort(len.begin(), len.end());
	queue<long long> q;
	q.push(n);

	set<long long> s;
	
	while (!q.empty()) {
		long long val = q.front();
		q.pop();

		if (s.find(val) != s.end()) 
			continue;
		s.insert(val);
		
		pair<long long, int> p = {val, 0};
		auto it = lower_bound(len.begin(), len.end(), p);
		
		while (it != len.end() && (*it).first == val) {
			long long x = val + (*it).second - 1;
			q.push(x);
			it++;
		}
	}
	
	cout << *s.rbegin() << endl;
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
