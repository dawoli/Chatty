#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x, long long y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<long long> v(s.size(), 0);
	long long cnt = 0;
	for(long long i = 0; i < s.size(); i ++) {
		if(s[i] >= '0' and s[i] <= '9') {
			v.push_back(s[i] - '0');
			cnt ++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	bool flag = false;
	for(long long i=0; i<v.size(); i++) {
		if(v[i] != 0) {
			flag = true;
			break;
		}
	}
	if(!flag) {
		puts("0");
		return 0;
	}
	v.resize(cnt);
	for(long long i=0; i<v.size(); i++) {
		printf("%lld", v[i]);
	}
	puts("");
	return 0;
}
