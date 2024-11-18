#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	long long ans = 1e11, sum = 0;
	
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	
	priority_queue<int> pq;
	for (auto i : ord) {
		sum += b[i];
		pq.push(b[i]);
		
		if (pq.size() > k) {
			sum -= pq.top();
			pq.pop();
		}
		if (pq.size() == k) {
			ans = min(ans, sum * a[i]);
		}
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