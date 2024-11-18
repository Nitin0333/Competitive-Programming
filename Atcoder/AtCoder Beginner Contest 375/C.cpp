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
	
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	int shft = 1, u = 0, d = n - 1;
	
	while (u < d) {
		queue<int> ord;
		if (shft == 1) {
			for (int j = d; j >= u; j--)
				ord.push(v[j][u]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[u][j]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[j][d]);
			
			for (int j = d; j >= u; j--) 
				ord.push(v[d][j]);
		}
		else if (shft == 2) {						
			for (int j = d; j >= u; j--) 
				ord.push(v[d][j]);
			
			for (int j = d; j >= u; j--)
				ord.push(v[j][u]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[u][j]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[j][d]);
		}
		else if (shft == 3) {			
			for (int j = u; j <= d; j++)
				ord.push(v[j][d]);
			
			for (int j = d; j >= u; j--) 
				ord.push(v[d][j]);
			
			for (int j = d; j >= u; j--)
				ord.push(v[j][u]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[u][j]);
		}
		else {		
			for (int j = u; j <= d; j++)
				ord.push(v[u][j]);
			
			for (int j = u; j <= d; j++)
				ord.push(v[j][d]);
			
			for (int j = d; j >= u; j--) 
				ord.push(v[d][j]);
			
			for (int j = d; j >= u; j--)
				ord.push(v[j][u]);
		}
		
		for (int j = u; j <= d; j++) {
			v[u][j] = ord.front();
			ord.pop();
		}
			
		for (int j = u; j <= d; j++) {
			v[j][d] = ord.front();
			ord.pop();
		}
		
		for (int j = d; j >= u; j--) {
			v[d][j] = ord.front();
			ord.pop();
		} 
		
		for (int j = d; j >= u; j--) {
			v[j][u] = ord.front();
			ord.pop();
		}
		
		shft = (shft + 1) % 4;
		u++, d--;
	}
	
	for (auto x : v)
		cout << x << endl;
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