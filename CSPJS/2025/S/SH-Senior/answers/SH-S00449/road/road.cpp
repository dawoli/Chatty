#include<bits/stdc++.h>
#define int long long
#define N 3000009
using namespace std;
struct road{
	int u,v,w;
}a[N],aa[N];
int mmin(int x,int y){return x<y?x:y;}
bool cmp(road a,road b){
	return a.w<b.w;
}
int n,m,cnt,k,fa[N],x[19][N],p[N];
int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
void merge(int x,int y){
	x=findfa(x),y=findfa(y);
	fa[x]=y;
}
bool tog(int x,int y){
//	if(x==1002)cout<<x<<' '<<y<<' '<<findfa(x)<<' '<<findfa(y)<<endl;
	return (findfa(x)==findfa(y));
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>p[i];
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
		}
	}
	int fans=998244353;
	fans=fans*fans*4;
//	cout<<fans<<endl;
//	cout<<"ok"<<endl;
	sort(a+1,a+1+m,cmp);
	for(int ii=0;ii<pow(2,k);ii++){
//		cout<<ii<<endl;
		int i=ii;
		cnt=0;
		int ans=0;
		int lfu=0;
		for(int j=1;j<=k;j++){
			if(i%2==1){
				lfu++;
				ans+=p[j];
				for(int k=1;k<=n;k++){
//					if(ii==5)cout<<j<<endl;
					aa[++cnt].u=n+j,aa[cnt].v=k,aa[cnt].w=x[j][k];
				}
			}
			i/=2;
		}
		sort(aa+1,aa+1+cnt,cmp);
		for(int j=1;j<=n*2;j++)fa[j]=j;
//		for(int j=1;j<=cnt;j++){
//			if(ii==5)cout<<j<<' '<<a[j].u<<' '<<a[j].v<<' '<<a[j].w<<endl;
//		}
//		cout<<n+lfu<<endl;
		int now=0,nowa=1;
		i=1;
		while(now<n+lfu-1){
			if(nowa<=cnt&&aa[nowa].w<a[i].w){
				int u=aa[i].u,v=aa[i].v;
				if(!tog(u,v)){merge(u,v);now++;ans+=aa[i].w;}
//				cout<<u<<' '<<v<<endl;
				nowa++;
			}
			else{
				if(i>m)break;
//				if(ii==5)cout<<now<<' '<<i<<"\n";
				int u=a[i].u,v=a[i].v;
				if(!tog(u,v)){merge(u,v);now++;ans+=a[i].w;}
//				cout<<u<<' '<<v<<endl;
				i++;
			}
		}
//		for(int i=1;i<=n+lfu;i++)if(fa[i]==i&&ii==5)cout<<i<<endl;
		fans=mmin(ans,fans);
	}
	cout<<fans<<"\n"<<endl;
	return 0;
}

