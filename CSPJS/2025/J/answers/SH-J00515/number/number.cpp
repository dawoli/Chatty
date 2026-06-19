#include<bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b){
	if(a > b)return true;
	else return false;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> num(s.size(),0);
	int cnt = 0;
	for(int i = 0; i < s.size(); i ++) {
		if(s[i] <= '9' && s[i] >= '0'){
		num[cnt] = s[i] - '0';
		++cnt;
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i = 0;i < cnt;i ++){
		cout << num[i];
	}
	return 0;
}

