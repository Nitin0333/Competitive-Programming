#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

struct dsu {
    int n;
    vector<int> p, rnk;
    
    dsu(vector<int>& v) {
        rnk = v;
        n = v.size();
        p = vector<int> (n);
        iota(p.begin(), p.end(), 0);
    }
    int parent(int a) {
        if (p[a] == a)
            return a;
        return p[a] = parent(p[a]);
    }
    int rank(int a) {
        return rnk[parent(a)];
    }
    void unite(int a, int b) {
        a = parent(a), b = parent(b);
        if (a == b)
            return;
        if (rank(a) < rank(b))
            swap(a, b);
        p[b] = a;
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    struct dsu d(v);
    
    vector<int> smn(n);
    for (int i = n - 1; i > -1; i--) {
        smn[i] = v[i];
        if (i + 1 < n)
            smn[i] = min(smn[i], smn[i + 1]);
    }
    int mxi = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= v[mxi])
            mxi = i;
            
        d.unite(i, mxi);
        
        while (j < n && smn[j] < v[mxi])
            j++;
        if (j > i)
            j--;
        
        d.unite(i, j);
    }
    
    for (int i = 0; i < n; i++) {
        cout << d.rank(i) << " ";
    }
    cout << endl;
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