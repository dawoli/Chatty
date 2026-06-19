#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[1000010], cnt[20];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int tot = 0;
	for(int i=0; i<s.size(); ++i){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++tot] = (s[i]-'0');
			cnt[a[tot]]++;
		}
	}
	for(int i=9; i+1; --i){
		for(int j=1; j<=cnt[i]; ++j){
			cout << i;
		}
	}
	return 0;
} 
