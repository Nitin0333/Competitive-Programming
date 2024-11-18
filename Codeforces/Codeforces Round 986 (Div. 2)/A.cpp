#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	
	string s;
	cin >> s;
	
	int x = 0, y = 0;
	int dis = 1e4;
	
	while (dis > 0) {
		for (int i = 0; i < n; i++) {
			if (s[i] == 'N')
				y++;
			else if (s[i] == 'S')
				y--;
			else if (s[i] == 'E')
				x++;
			else
				x--;
			
			if (x == a && y == b) {
				cout << "YES" << endl;
				return;
			}
		}
		dis--;
	}
	
	cout << "NO" << endl;
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