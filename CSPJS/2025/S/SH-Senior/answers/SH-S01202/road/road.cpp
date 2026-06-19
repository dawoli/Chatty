#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+200,M=2e6+200;
int n,m,k,tot;
struct dat{
	int u,v,w;
}e[M],ans[M],now[N];
inline bool cmp(dat xx,dat yy){
	return xx.w<yy.w;
}
int c[N],a[15][N],fa[N],minn,cnt;
int find(int x){
//	cout<<x<<endl;
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n<<" "<<m<<" "<<k<<endl;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
//		ans.push_back(e[i]);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	
//	cout<<"now="<<cnt<<endl;
//	int tttot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
	//	if(c[i]==0) cout<<i<<endl;
		for(int j=1;j<=n;j++){	
			cin>>a[i][j];
		//	if(i!=1)e[++tttot]=(dat){n+i-1,j,a[i][j]};
		}
	}
//	cout<<tttot<<endl;
	for(int i=n+1;i<=n+9;i++) fa[i]=i;
//	n+=9;
	sort(e+1,e+m+1,cmp);
	int ednum=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		ednum++;
		cnt+=e[i].w;
		ans[++tot]=e[i];
		if(ednum==n-1) break;
		fa[find(e[i].u)]=find(e[i].v);
	}
//	n-=9;
	minn=cnt;
	//cout<<ednum<<" "<<cnt<<endl;
	//return 0;
	for(int i=1;i<(1<<k);i++){
		int nowtot=tot;
		
		for(int j=1;j<=tot;j++) now[j]=ans[j];
		cnt=0;
		int lvnum=n;
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				cnt+=c[j+1];
//	if(i==2)			cout<<i<<" "<<j<<endl;
				lvnum++;
				for(int l=1;l<=n;l++){
					now[++nowtot]=(dat){lvnum,l,a[j+1][l]};
				}
			}
		}
		for(int j=1;j<=lvnum;j++) fa[j]=j;
		sort(now+1,now+nowtot+1,cmp);
		ednum=0;
		for(int j=1;j<=nowtot;j++){
			int u=now[j].u,v=now[j].v,w=now[j].w;
			if(u>lvnum||v>lvnum){
//				cout<<i<<" "<<u<<" "<<v<<" "<<lvnum<<"SHIT"<<endl;
				return 0;
			}
			if(find(u)==find(v)) continue;
			ednum++;
			cnt+=w;
		//	if(i==1022)cout<<w<<endl;
			if(ednum+1==lvnum) break;
			fa[find(u)]=find(v);
		}	
//	if(i==1022)	cout<<i<<" "<<cnt<<endl; 
		minn=min(minn,cnt);
	}
	cout<<minn<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 3 1
1 2 100
2 3 100
3 4 100

*/
