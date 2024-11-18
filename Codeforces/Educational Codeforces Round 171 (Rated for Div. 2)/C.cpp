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
	
	string s;
	cin >> s;
	s = " " + s;
	
	vector<long long> pre(n + 1);
	iota(pre.begin(), pre.end(), 0);
	for (int i = 1; i <= n; i++)
		pre[i] += pre[i - 1];
	
	vector<int> v;
	for (int i = n; i; i--) {
		if (s[i] == '1')
			v.push_back(i);
	}
	vector<long long> rm((int)v.size() + 1);
	for (int i = 0; i < v.size(); i++) {
		rm[i + 1] = rm[i] + v[i];
	}

	long long ans = 1e15, sum = 0, sk = 0, on = 0;
	queue<int> q;
	for (int i = n; i; i--) {
		sum += i;
		if (s[i] == '0') {
			if (on > sk)
				sk++;
		}
		on += s[i] == '1';
		int in = min(on, sk + i - 1);
		ans = min(ans, pre[i - 1] + sum - rm[in]);
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

