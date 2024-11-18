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
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	vector<pair<long long, int>> st;
	
	for (int i = 0; i < n; i++) {
		long long sum = v[i];
		int cnt = 1;
		
		while (!st.empty()) {
			long long x = st.back().first;
			int y = st.back().second;
			if (x / y < sum / cnt)
				break;
			st.pop_back();
			sum += x;
			cnt += y;
		}
		st.push_back({sum, cnt});
	}
	
	int y = st.back().second;
	long long x = st.back().first, mx = (x + y - 1) / y;
	long long mn = st[0].first / st[0].second;
	
	cout << mx - mn << endl;
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