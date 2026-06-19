#include<bits/stdc++.h>
#define rep(i,a,b)	for(ll i=(a);i<=(b);i++)
#define per(i,a,b)	for(ll i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef double ld;
const ll maxn=2e5+9;
const ld esp=1e-4;
ll n,ans,a[maxn];
bool c[maxn];
void dfs(ll x){
	if(x>n){
		ll res=0,lst0=0,lst1=0;
		rep(i,1,n){
			if(c[i]==0){
				if(lst0>0&&a[lst0]==a[i])	res+=a[i];
				lst0=i;
			}
			if(c[i]==1){
				if(lst1>0&&a[lst1]==a[i])	res+=a[i];
				lst1=i;
			}
		}
		ans=max(ans,res);
		return;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=0;
	dfs(x+1);
}
void solveBF(){
	ans=0;
	dfs(1);
	cout<<ans<<'\n';
}
ll f[2009][2009];
void solveDP(){
	a[0]=-1;
	memset(f,-0x3f,sizeof f);
	f[1][0]=0;
	rep(i,2,n)	rep(j,0,i-1){
		if(i-j>1){
			f[i][j]=f[i-1][j]+(a[i]==a[i-1]?a[i]:0);
		}
		else{
			rep(k,0,j-1)
				f[i][j]=max(f[i][j],
							f[i-1][k]+(a[i]==a[k]?a[i]:0));
		}
	}
	ll ans=0;
	rep(i,0,n-1)	ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
}
void mymain(){
	scanf("%lld",&n);
	rep(i,1,n)	scanf("%lld",a+i);
	if(n<=15)	solveBF();
	else
		if(n<=2000)
			solveDP();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	cin>>T;
	while(T-->0)	mymain();
	return 0;
}
