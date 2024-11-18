template <typename T>
ostream& operator<<(ostream&, vector<T>& vec) {
	if (vec.empty()) {
		cout << "[]";
		return cout;
	}
	cout << '[';
	for (int i = 0; i < vec.size() - 1; i++) {
		cout << vec[i] << ", ";
	}
	cout << vec.back() << ']';
	return cout;
}

template <typename T>
ostream& operator<<(ostream&, set<T>& s) {
	if (s.empty()) {
		cout << "{}";
		return cout;
	}
	cout << '{';
	for (auto it = s.begin(); it != s.end(); it++) {
		T ele = *it;
		cout << ele;
		if (next(it) != s.end()) {
			cout << ", ";
		}
	}
	cout << '}';
	return cout;
}

template <typename t1, typename t2>
ostream& operator<<(ostream&, pair<t1, t2>& p) {
	cout << '(' << p.first << ',' << p.second << ')';
	return cout;
}

template <typename t1, typename t2>
ostream& operator<<(ostream&, map<t1, t2>& m) {
	cout << '{' << endl;
	for (auto it = m.begin(); it != m.end(); it++) {
		pair<t1, t2> p = *it;
		cout << "  " << p << endl;
	}
	cout << '}';
	return cout;
}

template <typename t1>
ostream& operator<<(ostream&, multiset<t1>& s) {
	if (s.empty()) {
		cout << "{}";
		return cout;
	}
	cout << '{';
	for (auto it = s.begin(); it != s.end(); it++) {
		t1 ele = *it;
		cout << ele ;
		if (next(it) != s.end()) {
			cout << ", ";
		}
	}
	cout << '}';
	return cout;
}

template<typename t1, typename t2>
ostream& operator<<(ostream&, multimap<t1, t2> m) {
	cout << '{' << endl;
	for (auto it = m.begin(); it != m.end(); it++) {
		pair<t1, t2> p = *it;
		cout << " " << p << endl;
	}
	cout << '}' << endl;
	return cout;
}

void debug_out() { cout << endl; }

template  <typename  Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << H;
	debug_out(T...);
}  


#define debug(...) cout << "[" << #__VA_ARGS__ << "] =", debug_out(__VA_ARGS__)

