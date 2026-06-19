#include<bits/stdc++.h>//T1¿Ï¶¨100·Ö 
using namespace std;
string s;
int n[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int pn=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9') n[++pn]=s[i]-'0';
	}
	sort(n+1,n+pn+1);
	for(int i=pn;i>=1;i--) cout<<n[i];
	return 0;
}
