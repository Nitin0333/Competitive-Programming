#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void query(string s) {
	cout << "? " << s << endl;
	cout.flush();
}

void answer(string s) {
	cout << "! " << s << endl;
	cout.flush();
}

void solve() {
	int n, inp;
	cin >> n;
	
	if (n == 1) {
		query("1");
		cin >> inp;
		if (inp)
			answer("1");
		else
			answer("0");
		return;
	}
	
	vector<vector<char>> pre(2), fol(2);
	string ans = "";
	query("00");
	cin >> inp;
	if (inp) {
		pre[0].push_back('0');
		fol[0].push_back('0');
		ans = "00";
	}
	query("01");
	cin >> inp;
	if (inp) {
		pre[1].push_back('0');
		fol[0].push_back('1');
		ans = "01";
	}
	query("10");
	cin >> inp;
	if (inp) {
		pre[0].push_back('1');
		fol[1].push_back('0');
		ans = "10";
	}
	
	if (n == 2) {
		if (ans.empty())
			answer("11");
		else 
			answer(ans);
		return;
	}
	
	query("11");
	cin >> inp;
	if (inp) {
		pre[1].push_back('1');
		fol[1].push_back('1');
		ans = "11";
	}
	
	string t;
	int lst = ans.back() - '0';
	
	while (ans.size() != n) {
		int sz = fol[lst].size();
		if (sz == 0) 
			break;
		else if (sz == 1) {
			t = ans + fol[lst][0];
			query(t);
			cin >> inp;
			if (inp == 0)
				break;
			ans = t;
			lst = ans.back() - '0';
		}
		else {
			t = ans + fol[lst][0];
			query(t);
			cin >> inp;
			if (inp) {
				ans = t;
				lst = ans.back() - '0';
			}
			else {
				t = ans + fol[lst][1];
				query(t);
				cin >> inp;
				if (inp == 0)
					break;
				ans = t;
				lst = ans.back() - '0';
			}
		}
	}
	
	int fst = ans[0] - '0';
	
	while(ans.size() != n) {
		int sz = pre[fst].size();
		if (sz == 1) {
			ans = pre[fst][0] + ans;
			fst = ans[0] - '0';
		}
		else if (sz == 2) {
			t = pre[fst][0] + ans;
			query(t);
			cin >> inp;
			if (inp) {
				ans = t;
			}
			else {
				ans = pre[fst][1] + ans;
			}
			fst = ans[0] - '0';
		}
	}
	
	answer(ans);
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
