#include<bits/stdc++.h>
using namespace std;
int n,T,m,L,V,p[100005],d[100005],v[100005],a[100005],vis[100005][2],ans,ass,fa[100005],k,clo[100005];
void insert(int x,int y){
	if(x>0&&y>0){
		fa[x]++;
		fa[y+1]--;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		ass=0;
		k=0;
		memset(vis,0,sizeof(vis));
		memset(fa,0,sizeof(fa));
		memset(clo,0,sizeof(clo));
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>p[i];
		} 
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				if(v[i]>V){
					vis[i][0]=upper_bound(p+1,p+1+m,d[i])-p-1;
					vis[i][1]=m;
					continue;
				}
				int k=(V*V-v[i]*v[i])/2/a[i]+d[i];
				if(k>p[n])continue;
				int x=upper_bound(p+1,p+1+m,k)-p;
				vis[i][0]=x;
				vis[i][1]=m;
			}else if(a[i]<0){
				if(v[i]<V){
					vis[i][0]=0;
					vis[i][1]=0;
					continue;
				}
				int k=(V*V-v[i]*v[i])/2/a[i]+d[i];
				if(k>p[n]){
					vis[i][0]=upper_bound(p+1,p+1+m,d[i])-p;
					vis[i][1]=m;
					continue;
				}
				int x=lower_bound(p+1,p+1+m,k)-p-1;
				vis[i][0]=upper_bound(p+1,p+1+m,d[i])-p;
				vis[i][1]=x;
			}else{
				if(v[i]>V){
					int x=upper_bound(p+1,p+1+m,d[i])-p;
					vis[i][0]=x;
					vis[i][1]=m;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i][0]<=vis[i][1]&&vis[i][0]!=0)insert(vis[i][0],vis[i][1]);
		}
		for(int i=1;i<=m;i++){
			fa[i]+=fa[i-1];
		}
		for(int i=1;i<=n;i++){
			if(fa[i]==0){
				++ass;
				continue;
			}
			int maxx=-1,ii=0;
			for(int j=vis[i][0];j<=vis[i][1];j++){
				if(fa[j]>maxx)maxx=fa[j],ii=j;
			}
			clo[ii]=1;
		}
		for(int i=1;i<=n;i++){
			if(clo[i]==1)++ass;
		}
		for(int i=1;i<=m;i++){
			if(vis[i][0]!=0&&vis[i][1]!=0&&vis[i][0]<=vis[i][1])++ans;
		}
		cout<<ans<<" "<<ass<<"\n";
	}
	return 0;
}
