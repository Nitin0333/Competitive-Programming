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

Mint two = 2;

void solve() {
	int n;
	cin >> n;
	
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i + 1];
	}
	vector<int> lft(n + 1), p2(n + 1);
	for (int i = 1; i <= n; i++) {
		int val = v[i];
		while (val % 2 == 0) {
			p2[i]++;
			val /= 2;
		}
		lft[i] = val;
	}

	vector<long long> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + lft[i];
	}
	
	vector<Mint> ans(n + 1);

	int sum = 0;
	deque<pair<int, int>> dq;
	for (int i = 1; i <= n; i++) {
		while (!dq.empty()) {
			auto x = dq.back();
			int dif = sum - x.second;
			long long val = v[i];
			while (dif > 0 && val < v[x.first]) {
				val *= 2;
				dif--;
			}
			
			if (val >= v[x.first])
				dq.pop_back();
			else
				break;
		}
		
		if (dq.empty()) {
			ans[i] = pre[i - 1];
			Mint pw = pow(two, sum), mul = v[i];
			pw *= mul;
			ans[i] += pw;
		}
		else {
			int dif = sum - dq.back().second;
			ans[i] = pre[i - 1] - pre[dq.back().first];
			Mint pw = pow(two, sum - dq.back().second - p2[dq.back().first]), mul = v[i];
			pw *= mul;
			ans[i] += pw;
			ans[i] += ans[dq.back().first];
		}
		
		dq.push_back({i, sum});
		sum += p2[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
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