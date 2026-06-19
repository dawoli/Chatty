#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define Rep(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
const int N=2e5+5;
int n,m,k,S,aa[N],a[N],c[N],d[20][N],T;
int X[4];
int dep[N],f[N][20],g[N][21],sum[N];
int res[20][N];
//f 何时开始一定<=k
//g 何时开始一定>k 
void dfs(int u,int l,int r){
	if(l==r){
		dep[u]=1;
		if(l<=n){
			rep(k,0,19)f[u][k]=(a[l]<=k?l:S),g[u][k]=(a[l]>k?l:S);
		}else rep(k,0,19)f[u][k]=g[u][k]=S;
		return;
	}
	int mid=l+r>>1;
	int lc=u<<1,rc=u<<1|1;
	dfs(lc,l,mid);
	dfs(rc,mid+1,r);
	dep[u]=dep[u<<1]+1;
	rep(k,0,19){
		if(d[dep[u]][l>>dep[u]]==0){//左重 
	    	if(g[lc][dep[u]-1]<S)f[u][k]=max(g[lc][dep[u]],f[lc][k]),g[u][k]=max(g[lc][dep[u]],g[lc][k]);//左侧最终必胜 
    		else f[u][k]=f[rc][k],g[u][k]=g[rc][k];//可以让右侧赢 
    	}else{
    		if(g[lc][k]<S)f[u][k]=max(g[rc][dep[u]-1],f[rc][k]);//左侧最终>k 
    		else f[u][k]=f[rc][k];//左侧最终<=k 让左侧赢没有意义 
    		if(f[lc][k]<S)g[u][k]=max(g[rc][dep[u]-1],g[rc][k]);//左侧最终<=k 
    		else g[u][k]=g[rc][k];//左侧最终>k 让左侧赢没有意义 
		}
	}
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	rep(i,0,n-1)cin>>aa[i];
	rep(i,1,m){int x;cin>>x;c[x]=i;}
	while((1<<k)<n)++k;S=(1<<k);
	rep(i,1,k){
		string s;
		cin>>s;
		rep(j,0,((1<<(k-i))-1))d[i][j]=s[j]-'0';
	}
	for(cin>>T;T--;){
		rep(k,0,3)cin>>X[k];
		rep(i,0,n-1)a[i]=aa[i]^X[i%4];
		memset(f,0,sizeof f);
		memset(g,0,sizeof g); 
		memset(sum,0,sizeof sum);
		memset(res,0,sizeof res);
		dfs(1,0,(1<<k)-1);
		rep(i,0,(1<<k)-1){
			//看i何时赢
			//前
			int t=__lg(i);
			int l=(1<<t),r=-2,u=1;
			Rep(j,t-1,0){
				int ch=(i>>j)&1;
				if(ch==0||d[j+1][i>>(j+1)]==1)continue;
				int v=u<<1|(ch^1);
				if(g[v][j]<S){r=g[v][j]-1;break;}
				u=u<<1|ch; 
			}
			if(r!=-2){
				sum[l]++;sum[r+1]--;
				continue;
			}
			//后
			rep(j,0,t-1){//看i打的+更新 
				int ch=(i>>j)&1;
				if(ch==1){//更新 
					int p=res[j][(i>>j)^1];
					if(d[j+1][i>>(j+1)]==0&&a[p]>=j+1||d[j+1][i>>(j+1)]==1&&a[i]<=j){
						r=i-1;
						break;
					}else{
						res[j+1][i>>(j+1)]=i;
					}
				}else{
					int v=u^1;
					if(g[v][j]<S){r=g[v][j]-1;break;}
					else res[j+1][i>>(j+1)]=i;
				}
				u>>=1;
			}
			sum[l]++,sum[r+1]--;
		}
		rep(i,1,(1<<k)-1)sum[i]+=sum[i-1];
		int ans=0;
		rep(i,1,n)ans^=(i*sum[i]);
		cout<<ans<<endl;
	}
	return 0;
}
