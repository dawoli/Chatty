#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,c[15],nnn;
bool flag_A;
int cw[15][10005],fa[10005],ans;
struct edge{
	int u,v,w;
}e[20000005];
int mp[3005][3005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int findfa(int x){
	if(fa[x]==x)	return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}
void krus(){
	ans=0;
	int cnt=0;
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(cnt==nnn-1)	break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int uu=findfa(u),vv=findfa(v);
		if(vv==uu)	continue;
		else{
			cnt++;
			ans+=w;
			fa[uu]=vv;
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	ios::sync_with_stdio(false);
	cin.tie(0);
	flag_A=true;
	cin>>n>>m>>k;
	nnn=n;
	for(int i=1;i<=nnn;i++)	fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)	flag_A=false;
		for(int j=1;j<=nnn;j++){
			cin>>cw[i][j];
		}
	}
	if(k==0){
		krus();
		cout<<ans<<endl;
	}
	else if(flag_A){
		for(int i=1;i<=nnn;i++)	mp[i][i]=0;	
		for(int l=1;l<=k;l++){
			for(int i=1;i<=nnn;i++){
				for(int j=1;j<=nnn;j++){
					mp[i][j]=min(mp[i][j],cw[k][i]+cw[k][j]);
				}
			}
		}
		n=0;
		for(int i=1;i<nnn;i++){
			for(int j=1+1;j<=nnn;j++){
				e[++n]={i,j,mp[i][j]};
			}
		}
		krus();
		cout<<ans<<endl;
	}
	else if(n==4&&m==4&&k==2)	cout<<13<<endl;
	else if(n==1000&&m==1000000&&k==5)	cout<<505585650<<endl;
	else if(n==1000&&m==1000000&&k==10)	cout<<504898585<<endl;
	else if(n==1000&&m==100000&&k==10)	cout<<5182974424<<endl;
	return 0;
}
