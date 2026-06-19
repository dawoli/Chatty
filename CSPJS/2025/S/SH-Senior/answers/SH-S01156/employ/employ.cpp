#include<bits/stdc++.h>
using namespace std;
int d[501],c[501],s[501];
long long mod=998244353;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	long long cnt=1;
	for(int i=2;i<=n;i++) cnt=(cnt*i)%mod;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
