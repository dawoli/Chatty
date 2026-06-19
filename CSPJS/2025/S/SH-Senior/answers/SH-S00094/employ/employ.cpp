#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define N 509
ll n,m,c[N],f[N][N],t[N],ok[N],p[N],ans;
string s;
void calc(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(c[p[i]]<=res||s[i]=='0')res++;
	}
	ans+=(n-res>=m);
}
void dfs(int i){
	if(i==n+1){
		calc();
		return;
	}
	for(int j=1;j<=n;j++){
		if(!ok[j]){
			p[i]=j,ok[j]=1;
			dfs(i+1);
			ok[j]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
//		t[c[i]]++;
	}
	dfs(1);
	cout<<ans;
//	for(int i=n;i>=0;i--)
//		t[i]+=t[i+1];
//	for(int i=1;i<=n;i++)
//		for(int j=i;j>=0;j--)
//			for(int k=1;k<=n;k++)
//				if(s[i]=="1")
////					f[j][k]=(f[j-1][k]*(t[i-j+1]-(c[k]>i-j))%mod+f[j][k]*(n-t[i-j+1]-(c[k]<=i-j))%mod)%mod;
//				else;
	return 0;
} 
