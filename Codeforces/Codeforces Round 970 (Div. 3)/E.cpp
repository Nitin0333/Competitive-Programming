#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void solve() {
	int n;
	string s;
	cin >> n >> s;
	
	s = " " + s;
	
	int ans = 0;
	
	vector<vector<int>> cnt(2, vector<int> (26));
	
	if (n % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			cnt[i & 1][s[i] - 'a']++;
		}
		
		for (int i = 0; i < 2; i++) {
			ans += n / 2 - *max_element(cnt[i].begin(), cnt[i].end());
		}
	}
	else {
		vector<vector<vector<int>>> freq(n + 1, vector<vector<int>> (2, vector<int> (26)));
		
		ans = 1e7;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				freq[i][1][j] += freq[i - 1][1][j];
				freq[i][0][j] += freq[i - 1][0][j];
			}
			freq[i][i & 1][s[i] - 'a']++;
		}

		for (int i = n; i ; i--) {
			vector<int> o = freq[i - 1][1], e = freq[i - 1][0];
			for (int j = 0; j < 26; j++) {
				o[j] += cnt[1][j];
				e[j] += cnt[0][j];
			}
			
			int sum = 0;
			
			sum += n - *max_element(o.begin(), o.end()) - *max_element(e.begin(), e.end());
			
			ans = min(ans, sum);
			
			int c = i & 1;
			cnt[c ^ 1][s[i] - 'a']++;
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