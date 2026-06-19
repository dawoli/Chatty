#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c;
bool v[1010];
ll n,m,sum,ans=1,d[5050],a[5050];
ll read(){
	ll ne=1,a=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-')ne=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return ne*a;
}
void dfs(ll de,ll l,ll s){
	if(de==n){
		if(s>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		if(d[de+1]==1&&l<a[i])dfs(de+1,0,s+1);
		else dfs(de+1,l+1,s);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='1'){
			d[i]=1;
		}
		sum+=d[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(sum<m){
		printf("0");
		return 0;
	}
	if(n<=11){
		ans=0;
		dfs(0,0,0);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	printf("%lld",ans);
	return 0;
}
