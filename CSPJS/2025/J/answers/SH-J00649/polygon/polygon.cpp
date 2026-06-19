#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,a[5050],q[5050],ans;
bool vis[5050];
int c(int u,int v){
	if(v==0)return 1;
	int y=1;
	for(int i=v;i>=v-u+1;i--)y*=i,y%=mod;
	for(int i=2;i<=u;i++)y/=i,y%=mod;
	return y%mod;
}
int kuaisumi(int u,int v){
	int sum=1;
	while(v){
		if(v%2==1)sum*=u,sum%=mod;
		v/=2;
		u*=u;
		u%=mod;
	}
	return sum%mod;
}
void dfs(int dep,int s,int zui){
	if(dep>3){
		if(s>zui+zui)ans++;
		if(dep==n+1)return;
	}
	if(dep==1&&!q[dep])zui=a[q[dep]],s=a[q[dep]];
	
	for(int i=q[dep-1]+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			q[dep]=i;
			dfs(dep+1,s+a[i],max(zui,a[i]));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=26){
		dfs(1,a[1],a[1]);
		cout<<ans;
	}else{
		int tmp=kuaisumi(2,n);
		int r=c(0,n)+c(1,n)+c(2,n);
		r%=mod;
		cout<<(tmp+mod-r)%mod;
	}		
}
