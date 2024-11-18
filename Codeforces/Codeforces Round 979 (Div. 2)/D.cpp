#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<int> v(n + 1), mx(n + 1), mn(n + 1);
	for (int i = 0; i < n; i++)
		cin >> v[i + 1];
	
	for (int i = 1; i <= n; i++) {
		mx[i] = max(v[i], mx[i - 1]);
	}
	
	mn[n] = v[n];
	for (int i = n - 1; i; i--) {
		mn[i] = min(mn[i + 1], v[i]);
	}
	
	string s;
	cin >> s;
	s = " " + s;
	
	int bad = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'L' && s[i + 1] == 'R' && (mx[i] > i || mn[i + 1] < i + 1))
			bad++;
	}

	for (int j = 0; j < q; j++) {
		int i;
		cin >> i;
		
		if (s[i] == 'L' && s[i + 1] == 'R' && (mx[i] > i || mn[i + 1] < i + 1)) {
			bad--;
		}
		else if (s[i] == 'R' && s[i - 1] == 'L' && (mx[i - 1] > i - 1 || mn[i] < i)) {
			bad--;
		}
		
		if (s[i] == 'R')
			s[i] = 'L';
		else
			s[i] = 'R';
		
		if (s[i] == 'L' && s[i + 1] == 'R' && (mx[i] > i || mn[i + 1] < i + 1)) {
			bad++;
		}
		else if (s[i] == 'R' && s[i - 1] == 'L' && (mx[i - 1] > i - 1 || mn[i] < i)) {
			bad++;
		}

		if (bad == 0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
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