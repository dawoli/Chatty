#include<bits/stdc++.h>
#define N 200009
#define Ns 2009
using namespace std;
typedef long long ll;
ll n,a[N],c_ost[Ns][Ns],f[Ns][Ns],mxf[Ns][Ns],g[N][2],mx=0,col[N],pr[2],ans=0,pre[N],c_s[N];
map<ll,ll> pd;
map<ll,ll>::iterator it;
ll cal(){
	pr[0]=pr[1]=0;
	ll res=0;
	for(ll i=1;i<=n;i++){
		if(pr[col[i]]&&a[i]==a[pr[col[i]]]) res+=a[i];
		pr[col[i]]=i;
	}
	return res;
}
void dfs(ll x){
	if(x>n){
		ans=max(ans,cal());
		return;
	}
	col[x]=1;
	dfs(x+1);
	col[x]=0;
	dfs(x+1);
}
void input(){
	mx=0; ans=0; pd.clear();
	scanf("%lld",&n);
	for(ll i=0;i<=n;i++) g[i][0]=g[i][1]=0,pre[i]=0,c_s[i]=0;
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]);
}
void solveBF(){
	for(ll i=1;i<=n;i++) col[i]=0;
	dfs(1);
	printf("%lld\n",ans);
}
void solveDP(){
	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++) c_ost[i][j]=f[i][j]=mxf[i][j]=0;
	for(ll i=1;i<=n;i++){
		c_ost[i][i]=0;
		for(ll j=i+1;j<=n;j++){
			c_ost[i][j]=c_ost[i][j-1];
			if(a[j]==a[j-1]) c_ost[i][j]+=a[j];
		}
	}
	for(ll i=1;i<=n;i++){
		mxf[i][0]=f[i][0]=c_ost[1][i-1];
		for(ll j=1;j<i-1;j++){
			f[i][j]=(a[i]==a[j])*a[i]+c_ost[j+1][i-1]+mxf[j+1][j-1];
			mxf[i][j]=max(mxf[i][j-1],f[i][j]);
		}
		f[i][i-1]=(a[i]==a[i-1])*a[i]+mxf[i-1][i-2];
		mxf[i][i-1]=max(mxf[i][i-2],f[i][i-1]);
	}
	printf("%lld\n",mxf[n][n-1]);
}
void solveDPR(){
	for(ll i=1;i<=n;i++){
		it=pd.find(a[i]);
		if(it!=pd.end()) pre[i]=it->second;
		pd[a[i]]=i; 
	}
	for(ll i=2;i<=n;i++) c_s[i]=c_s[i-1]+(a[i]==a[i-1])*a[i];
	for(ll i=2;i<=n;i++){
		g[i][0]=max(g[i-1][0],g[i-1][1]);
		if(!pre[i]) continue;
		if(pre[i]==i-1) g[i][1]=a[i]+max(g[i-1][0],g[i-1][1]);
		else g[i][1]=a[i]+c_s[i-1]-c_s[pre[i]+1]+max(g[pre[i]+1][0],g[pre[i]+1][1]); 
	}
	printf("%lld\n",max(g[n][0],g[n][1]));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	for(ll i=1;i<=T;i++){	
		input();
		if(n<=15&&mx<=15)
			solveBF();
		else if(n<=2000)
			solveDP();
		else
			solveDPR();
	}
	return 0;
}


