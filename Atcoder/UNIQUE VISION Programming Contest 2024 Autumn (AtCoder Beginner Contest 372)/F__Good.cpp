#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 
#endif

template <typename t>
t pow(t a, long long b) {
	t res = 1;
	while (b > 0) {
		if (1 & b)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

constexpr long long mod = 998244353;

struct Mint {
	long long x;
	Mint() {
		x = 0;
	}
	Mint(long long x) {
		x %= mod;
		if (x < 0)
			x += mod;
		if (x >= mod)
			x -= mod;
		this->x = x;
	}
	Mint operator=(Mint& rhs) {
		this->x = rhs.x;
		return *this;
	}
	void operator=(long long x) {
		this->x = x;
	}
	long long val() {
		return x;
	}
	Mint inv() {
		long long g = __gcd(mod, this->x);
		assert(g == 1);
		return pow(*this, mod - 2);
	}
	Mint &operator*=(Mint& rhs) {
		this->x = this->x * rhs.x;
		this->x %= mod;
		return *this;
	}
	Mint &operator-=(Mint& rhs) {
		this->x = this->x - rhs.x;
		if (this->x < 0)
			this->x += mod;
		return *this;
	}
	Mint &operator+=(Mint& rhs) {
		this->x = this->x + rhs.x;
		if (this->x >= mod)
			this->x -= mod;
		return *this;
	}
	Mint &operator/=(Mint& rhs) {
		Mint inv = rhs.inv();
		*this *= inv;
		return *this;
	}
	friend Mint operator+(Mint& lhs, Mint& rhs) {
		Mint res = lhs;
		res += rhs;
		return res;
	}
	friend Mint operator-(Mint& lhs, Mint& rhs) {
		Mint res = lhs;
		res -= rhs;
		return res;
	}
	friend Mint operator*(Mint& lhs, Mint& rhs) {
		Mint res = lhs;
		res *= rhs;
		return res;
	}
	friend Mint operator/(Mint& lhs, Mint& rhs) {
		Mint res = lhs;
		res /= rhs;
		return res;
	}
	friend bool operator==(Mint& lhs, Mint& rhs) {
		return lhs.val() == rhs.val();
	}
	friend bool operator!=(Mint& lhs, Mint& rhs) {
		return lhs.val() != rhs.val();
	}
	friend bool operator<(Mint& lhs, Mint& rhs) {
		return lhs.val() < rhs.val();
	}
	friend bool operator>(Mint& lhs, Mint& rhs) {
		return lhs.val() > rhs.val();
	}
	friend bool operator<=(Mint &lhs, Mint& rhs) {
		return lhs.val() <= rhs.val();
	}
	friend bool operator>=(Mint &lhs, Mint& rhs) {
		return lhs.val() >= rhs.val();
	}
	friend ostream& operator<<(ostream&, Mint a) {
		cout << a.x ;
		return cout;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> edge(m, vector<int> (2));
	
	for (int i = 0; i < m; i++) {
		cin >> edge[i][0] >> edge[i][1];
		edge[i][0]--, edge[i][1]--;
	}

	vector<long long> dp(n, 1);
	vector<long long> prev(n);
	
	for (int i = 0; i < k; i++) {				
		for (auto x : edge) {
			prev[x[1]] = dp[x[1]];
		}
		
		long long t = dp[0];
		dp.erase(dp.begin());
		dp.push_back(t);
		
		for (auto x : edge) {
			Mint res = dp[x[0]];
			Mint res1 = prev[x[1]];
			res += res1;
			dp[x[0]] = res.val();
		}
	}

	cout << dp[0];
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