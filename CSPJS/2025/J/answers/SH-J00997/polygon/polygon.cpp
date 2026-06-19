/*\
n=5
a[]=1 2 3 4 5

i=  0 1 2 3 4 5
j=0 0 0 0 0 0 0
j=1 0 0 0 0 0 0
j=2 0 0 0 0 0 0
j=3 0 0 0/0 1 3
j=4 0 0 0 0/1 5
j=5 0 0 0 0 0/1
f[i][j]代表前i根木棍组成j边形的方案数
f[i][j]=f[i-1][j]+f[

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009,MOD=998244353;
ll n,a[N],ans=0,C[N],C2[N][N],g[N][N];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
void dfs(ll last,ll maxn,ll cnt,ll sum){
	if(cnt>=3){
		if(sum>2*a[maxn]){
//			ll cans=0;
//			for(ll 
			ans++;
		}
	}
	for(ll i=last+1;i<=n;i++){
		dfs(i,max(maxn,a[i]),cnt+1,sum+a[i]);
	}
} 
void solve1(){
//	buildC2();
//	sort(a+1,a+1+n,cmp);
	dfs(0,0,0,0);
	cout<<ans<<endl;
}
void dfs2(ll last,ll maxn,ll cnt,ll sum){
	if(cnt==3){
		if(sum>2*a[maxn]){
			ans+=g[n-last][n-last];
			
		}return ;
	}
	for(ll i=last+1;i<=n;i++){
		dfs(i,max(maxn,a[i]),cnt+1,sum+a[i]);
	}
} 
void buildC2(){
	C2[0][1]=C2[1][1]=1;
	for(ll i=2;i<=n;i++){
		for(ll j=i;j>=1;j--)
			C2[j][i]=(C2[j][i]+C2[j-1][i])%MOD;
	}
}
void solve(){
	buildC2();
	sort(a+1,a+1+n,cmp);
	for(ll j=1;j<=n;j++)
		for(ll i=1;i<=j;i++)
			g[i][j]=(g[i-1][j]+C2[i][j])%MOD;
	dfs2(0,0,0,0);
	cout<<ans<<endl;
}
void buildC(ll x){
	C[0]=C[1]=1;
//	cout<<C[2]<<endl;
	for(ll i=2;i<=x;i++){
		for(ll j=i;j>=1;j--)
			C[j]=(C[j]+C[j-1])%MOD;
//		cout<<i<<"    ";
//		for(ll j=1;j<=i;j++) cout<<C[j]<<' ';
//		cout<<endl;
	}
}

void solve2(){ 
	buildC(n);
//	for(ll i=1;i<=n;i++) cout<<C[i]<<endl;
	for(ll i=3;i<=n;i++) (ans+=C[i])%=MOD;
	cout<<ans<<endl;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<=10){
		solve1();
		return 0;
	}
	ll maxa=-1;
	for(ll i=1;i<=n;i++) maxa=max(maxa,a[i]);
	if(maxa==1){
		solve2();
		return 0;
	}
	bool allthesame=1;
	for(ll i=2;i<=n;i++) if(a[i]!=a[i-1]) {
		allthesame=0;
		break;
	}
	if(allthesame){
		solve2();
		return 0;
	}
	solve();
	return 0;
}
