#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"
ll mod=998244353;
int a[5005];
int maxx,ans1;
bool st[15];
void dfs(int n,int m,int z,int g){
	//cout<<n<<' '<<m<<' '<<z<<' '<<g<<endl;
	if(g>2){
		if(z>2*a[n])ans1++;
		if(g==m)return;
	}
	for(int i=n+1;i<=m;i++){
		if(st[i]==1)continue;
		//if(z<=a[i])continue;
		st[i]=1;
		dfs(i,m,z+a[i],g+1);
		st[i]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=3){
		cout<<n/3;
		return 0;
	}
	if(n<=10){
		sort(a+1,a+n+1);
		dfs(0,n,0,0);
		cout<<ans1;
	}
	if(maxx==1){
		ll ans=1;
		ll t;
		for(int i=1;i<=n;i++){
			ans=ans*2%mod;
		}
		ans=ans-1-n-n*(n-1)/2;
		cout<<ans;
	}
	return 0;
} 
