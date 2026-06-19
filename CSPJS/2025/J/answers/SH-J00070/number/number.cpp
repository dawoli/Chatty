#include <bits/stdc++.h>
using namespace std;

const int maxn(1e6 + 5);
int a[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a_(0);
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[a_] = s[i] - '0';
			a_++;
		}
	}
	sort(a, a + a_, cmp);
	for(int i = 0; i < a_; i++){
		cout << a[i];
	}
	return 0;
}
