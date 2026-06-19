#include <bits/stdc++.h>
using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
}


const int MOD = 998244353, MX = 500;
int n, m;
string s;
struct Person {
	int id, c;
	bool operator < (Person& another) {
		return id < another.id;
	}
};
vector<Person> p;

bool test() {
	int rejected = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' || rejected >= p[i].c) rejected++;
	}
	return (n - rejected) >= m;
}

int main() {
    init();
    
    cin >> n >> m;
    p.reserve(n);
    cin >> s;
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		p.push_back(Person{int(p.size()+1), c});
	}
	
	long long ans = test();
	while (next_permutation(p.begin(), p.end())) {
		ans += test();
	}
	cout << ans << endl;
}
