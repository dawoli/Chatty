#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define cll const ll
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
cll N=200009;
ll n,a[N];
namespace BF{
	ll ans=0;
	bool r[100];
	void dfs(ll x,ll num,ll lR,ll lB){
		if(x==n+1){
			ans=max(ans,num);
			return;
		}
		r[x]=1;
		dfs(x+1,num+(a[x]==lR)*a[x],a[x],lB);
		r[x]=0;
		dfs(x+1,num+(a[x]==lB)*a[x],lR,a[x]);
	}
	void solve(){ans=0; dfs(0,0,-1,-1); cout<<ans<<endl;}
}
ll f[2009][2009];
void solveDP(){
	Set(f,0xcf);
	f[1][0]=0;
	rep(i,1,n){
		ll clr1=a[i];
		rep(j,0,i-1){
			ll clr2=a[j];
			f[i+1][j]=max(f[i+1][j],f[i][j]+(a[i+1]==clr1)*clr1);
			f[i+1][i]=max(f[i+1][i],f[i][j]+(a[i+1]==clr2)*clr2);
		}
	}
	ll ans=0;
	rep(i,0,n-1)ans=max(ans,f[n][i]);
	cout<<ans<<endl;
} 
ll g[N][11];
void solveDP2(){
	Set(g,0xcf);
	g[1][0]=0;
	rep(i,1,n){
		ll clr1=a[i];
		rep(clr2,0,10){
			g[i+1][clr2]=max(g[i+1][clr2],g[i][clr2]+(a[i+1]==clr1)*clr1);
			g[i+1][clr1]=max(g[i+1][clr1],g[i][clr2]+(a[i+1]==clr2)*clr2);
		}
	}
	ll ans=0;
	rep(i,0,10)ans=max(ans,g[n][i]);
	cout<<ans<<endl;
}
ll b[N],h[N],bit[N],lst[N],tng[N];
void add(ll x,ll y){for(;x<=n;x+=x&-x)bit[x]+=y;}
ll psq(ll x){ll s=0;for(;x;x-=x&-x)s+=bit[x]; return s;}
void solve(){
	ll dta=0; ll m=0;
	rep(i,1,n){
		if(a[i]==a[i-1])dta+=a[i];
		else b[++m]=a[i];
		bit[i]=0;
	}
	Set(tng,0);Set(lst,0);
	rep(i,1,m){
		lst[i]=tng[b[i]];
		tng[b[i]]=i;
	}ll sum=0;
	rep(i,1,m){
		h[i]=sum-psq(i)+psq(lst[i]-1);
		if(lst[i]!=0)sum+=b[i],add(lst[i],b[i]);
	}
	cout<<*max_element(h+1,h+1+m)<<endl;
}
void work(){
	cin>>n;rep(i,1,n)cin>>a[i];
	ll mx=*max_element(a+1,a+1+n);
	if(n<=15)BF::solve();
	else if(n<=2000&&mx<=2000)solveDP();
	else if(mx<=10)solveDP2();
	else solve(); 
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;cin>>T;while(T--)work();
	return 0;
}

