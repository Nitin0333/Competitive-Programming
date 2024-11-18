#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

void query(int r) {
    cout << "? 1 " << r << endl;
    cout.flush();
}

void answer(string s) {
    cout << "! " << s << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    
    string s = "";
    int i = 1, prev = 0;
    while (i < n) {
        query(i + 1);
        int cur;
        cin >> cur;
        
        if (prev == 0 && cur > 0) {
            int j = i - cur;
            while (j > 0) {
                s += "1";
                j--;
            }
            j = 0;
            while (j < cur) {
                s += "0";
                j++;
            }
            s += "1";
        }
        else if (cur > prev)
            s += "1";
        else if (prev > 0 && prev == cur)
            s += "0";
        
        prev = cur;
        i++;
    }

    if (s.length() != n) {
        answer("IMPOSSIBLE");
    }
    else {
        answer(s);
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