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
	
	long long sum = n * (n + 1ll);
	
	if (sum % 4) {
		cout << "NO" << endl;
	}
	else {
		long long sum1 = 0, sum2 = 0;
		vector<int> a1, a2;
		
		while (n > 0) {
			if (sum1 <= sum2) {
				sum1 += n;
				a1.push_back(n);
			}
			else {
				sum2 += n;
				a2.push_back(n);
			}
			n--;
		}
		
		if (sum1 == sum2) {
			cout << "YES" << endl;
			
			cout << a1.size() << endl;
			for (auto x : a1)
				cout << x << " ";
			cout << endl;
			
			cout << a2.size() << endl;
			for (auto x : a2)
				cout << x << " ";
			cout << endl;
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
	// cin >> t;
	
	while (t--) {
		solve();
	}
}