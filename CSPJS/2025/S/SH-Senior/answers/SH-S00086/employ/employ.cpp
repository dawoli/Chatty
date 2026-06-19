#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=511;
int n,m,b[N],c[N],cnt[N],num[N];
int p[N];
char ch[N];
ll f[N],g[N],ans;
ll jc[N],C[N][N];
void init(){
	n=505;
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%mod;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	return;
}
ll dp1[N],dp2[N];
ll calc(int t){
	memset(dp1,0,sizeof(dp1));
	dp1[0]=1;
	for(int i=1;i<=n;i++){
		if(!b[i]) continue;
		memset(dp2,0,sizeof(dp2));
		dp2[0]=dp1[0];
		for(int j=1;j<=cnt[i];j++)
			dp2[j]=(dp1[j]+dp1[j-1]*(num[i-j]-t+j))%mod;
		swap(dp1,dp2);
	}
	return (dp1[t]*jc[n-t]%mod+mod)%mod;
}
int fh[2]={1,-1};
void solve1(){
	if(cnt[n]==n&&num[0]==n) cout<<jc[n];
	else cout<<0;
	return;
}
void solve2(){
	ans=jc[n];
	memset(num,0,sizeof(num)); 
	for(int i=1;i<=n;i++)
		num[c[i]]++;
	for(int i=1;i<=n;i++)
		num[i]+=num[i-1]; 
	ll res=1,ct=0;
	for(int i=1;i<=n;i++){
		if(b[i]){
			res=res*(num[i-1]-ct)%mod;
			ct++;
		}
	}
	res=res*jc[n-ct]%mod;
	ans=(ans+mod-res)%mod;
	cout<<ans;
	return;
}
void judge(){
	int e=0;
	for(int i=1;i<=n;i++){
		if(!b[i]) e++;
		else{
			if(e>=c[p[i]]) e++; 
		} 
	}
	if(n-e>=m) ans++;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>n>>m>>(ch+1);
	for(int i=1;i<=n;i++)
		b[i]=(ch[i]=='1'),cnt[i]=cnt[i-1]+b[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) num[c[i]-1]++;
	}
	if(m==n){
		solve1();
		return 0;
	}
	if(m==1){
		solve2();
		return 0;
	}
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		judge();
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}





/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=511;
int n,m,b[N],cnt[N],num[N];
char ch[N];
ll f[N],g[N];
ll jc[N],C[N][N];
void init(){
	n=505;
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=jc[i-1]*i%mod;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	return;
}
ll dp1[N],dp2[N];
ll calc(int t){
	memset(dp1,0,sizeof(dp1));
	dp1[0]=1;
	for(int i=1;i<=n;i++){
		if(!b[i]) continue;
		memset(dp2,0,sizeof(dp2));
		dp2[0]=dp1[0];
		for(int j=1;j<=cnt[i];j++)
			dp2[j]=(dp1[j]+dp1[j-1]*(num[i-j]-t+j))%mod;
		swap(dp1,dp2);
	}
	return (dp1[t]*jc[n-t]%mod+mod)%mod;
}
int fh[2]={1,-1};
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ3.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin>>n>>m>>(ch+1);
	for(int i=1;i<=n;i++)
		b[i]=(ch[i]=='1'),cnt[i]=cnt[i-1]+b[i];
	// if(cnt[n]==n){
	// 	cout<<jc[n];
	// 	cerr<<jc[n]<<endl;
	// 	return 0;
	// }
	int c;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c) num[c-1]++;
	}
	for(int i=n;i;i--)
		num[i-1]+=num[i];
	for(int i=m;i<=cnt[n];i++)
		g[i]=calc(i);
	ll ans=0;
	for(int i=m;i<=n;i++){
		for(int j=i;j<=n;j++)
			f[i]+=C[j][i]*g[j]%mod*fh[(j-i)&1];
		ans+=f[i];
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans;
	cerr<<ans<<endl;
	return 0;
}*/
