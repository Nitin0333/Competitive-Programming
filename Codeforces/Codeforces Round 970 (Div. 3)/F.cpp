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
		
constexpr long long mod = 1e9 + 7;

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
	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	Mint sum = 0, ans = 0;
	
	for (int i = n - 1; i > -1; i--) {
		Mint val = v[i];
		Mint res = val * sum;
		ans += res;
		sum += val;
	}

	Mint N = (n * (n - 1ll)) / 2;

	ans /= N;
	
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