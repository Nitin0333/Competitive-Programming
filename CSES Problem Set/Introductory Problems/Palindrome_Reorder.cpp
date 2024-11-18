#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	string s;
	cin >> s;
	
	int n = s.length(), od = 0;
	vector<char> ans(n);
	vector<int> mk(26);
	
	for (int i = 0; i < n; i++) {
		mk[s[i] - 'A']++;
	}
	
	int j = 0;
	
	for (int i = 0; i < 26; i++) {
		od += mk[i] % 2;
		
		if (od > 1)
			break;
		
		char ch = 'A' + i;
		
		if (mk[i] & 1) {
			ans[n / 2] = ch;
			mk[i]--;
		}
		
		while (mk[i] > 0) {
			ans[j] = ans[n - 1 - j] = ch;
			j++;
			mk[i] -= 2;
		}
	}
	
	if (od > 1) {
		cout << "NO SOLUTION" << endl;
	}
	else {
		for (auto x : ans)
			cout << x;
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