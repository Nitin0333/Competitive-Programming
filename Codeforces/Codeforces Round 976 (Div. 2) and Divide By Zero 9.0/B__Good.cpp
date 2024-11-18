
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int K;
	cin >> K;

	for (int i = K; ; i++) {
		vector<int> v(i + 1, 1);
		v[0] = 0;
		
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k * j <= i; k++) {
				v[j * k] ^= 1;
			}
		}

		int s = accumulate(v.begin(), v.end(), 0);
		if (s == K) {
			cout << i << endl;
			return;
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