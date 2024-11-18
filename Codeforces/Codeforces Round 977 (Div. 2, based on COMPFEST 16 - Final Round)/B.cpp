#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, x;
	cin >> n >> x;
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	multiset<int> s;
	
	sort(v.begin(), v.end());
	int mex = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == mex) {
			mex++;
		}
		else if (v[i] < mex) {
			s.insert(v[i] % x);
		}
		else {
			auto it = s.find(mex % x);
			if (it == s.end()) {
				break;
			}
			mex++;
			s.erase(it);
			i--;
		}
	}
	
	while (!s.empty()) {
		auto it = s.find(mex % x);
		if (it == s.end())
			break;
		mex++;
		s.erase(it);
	}
	
	cout << mex << endl;
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