#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define fi first
#define se second
const int N=1e4+30,M=4e6+30,K=15;
int n,m,k,ans=0x3f3f3f3f3f3f;
int tot=1,hd[N],ver[M];
void add(int x,int y,int z){
	ver[++tot]=y,hd[x]=tot;
}
int a[K][N],c[K];
pair<int,int>e[M],ee[K][N];
int fa[N<<1];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
pair<int,int> b[N];
pair<int,int>tp[N],rec[K][N];
void fun(int now,int add,int hs){
	if(now<=k){
		for(int i=1;i<=n+hs-1;i++)rec[now][i]=rec[now-1][i];
		fun(now+1,add,hs);
		int p1=1,p2=1;
//		for(int i=1;i<n;i++)cout<<rec[now-1][i].fi<<" ";
//		cout<<endl;
//		for(int i=1;i<=n;i++)cout<<ee[now][i].fi<<" ";
//		cout<<endl;
		int nd=n+hs+1,ed=n+hs-1+n;
		for(int i=1;i<=ed;i++){
			if(p1==n+hs-1+1){
				tp[i]=ee[now][p2++];
			}else if(p2==n+1){
				tp[i]=rec[now-1][p1++];
			}else if(rec[now-1][p1].fi>ee[now][p2].fi){
				tp[i]=ee[now][p2++];
			}else{
				tp[i]=rec[now-1][p1++];
			}
		}
		for(int i=1;i<=nd;i++){
			fa[i]=i;
		//	cout<<ver[tp[i].se^1]<<ver[tp[i].se]<<" ";
		}
	//	cout<<endl;
		int cnt=0,sum=0;
		for(int i=1;i<=ed;i++){
			int x=ver[tp[i].se],y=ver[tp[i].se^1];
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				fa[fy]=fx;
				rec[now][++cnt]=tp[i];
				sum+=tp[i].fi;
				if(cnt==nd-1)break;
			}
	//		cout<<cnt<<endl;
		}
		ans=min(ans,sum+add+c[now]);
	//	cout<<"aa"<<now<<" "<<ans<<endl;
		fun(now+1,add+c[now],hs+1);	
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		e[i]=make_pair(z,tot);
	} 
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++){
		int x=ver[e[i].se],y=ver[e[i].se^1];
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fy]=fx;
			b[++cnt]=e[i];
			sum+=e[i].fi;
			if(cnt==n-1)break;
		}
	}
	ans=min(ans,sum);
//	cout<<ans<<endl;
	for(int i=1;i<=n-1;i++)rec[0][i]=b[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		//	add(n+i,j,a[i][j]);
		//	add(j,n+i,a[i][j]);
			ee[i][j]=make_pair(a[i][j],tot);
		}
		sort(ee[i]+1,ee[i]+n+1);
	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ee[i][j].fi<<" ";
//		}
//		cout<<endl;
//	}
	fun(1,0,0);
	cout<<ans;
	return 0;
} 
