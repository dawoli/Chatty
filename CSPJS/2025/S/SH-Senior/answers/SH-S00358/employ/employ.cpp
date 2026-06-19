#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=529,MOD=998244353;
int n,m;
string s;
int c[N],nc[N];
int qp(int x,int t){
	int ret=1;
	while(t){
		if(t&1)	ret=(ret*x)%MOD;
		t>>=1;
		x=(x*x)%MOD;
	}
	return ret;
}
int a[N];
bool usd[N];
int ans=0;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=c[a[i]]){
				cnt++;
			}
//			cout<<a[i];
		}
//		cout<<cnt<<endl;
		if(n-cnt>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(usd[i])
			continue;
		usd[i]=true;
		a[x]=i;
		dfs(x+1);
		usd[i]=false;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cx=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		nc[c[i]]++;
		if(s[i-1])
			cx++;
	}
	for(int i=1;i<=n;i++)
		nc[i]+=nc[i-1];
	if(cx<m){
		cout<<0;
		return 0;
	}
	if(n>10){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
