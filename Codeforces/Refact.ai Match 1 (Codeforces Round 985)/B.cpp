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
	
	string s, t;
	cin >> s >> t;
	
	stack<char> st;
	int i = 0, j = 0;
	
	while (i < n - 1 && j < n) {
		char ch = s[j];
		while (!st.empty() && i < n -1 && ch != st.top()) {
			st.pop();
			ch = t[i];
			i++;
		}
		st.push(ch);
		j++;
	}
	
	if (i == n - 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
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