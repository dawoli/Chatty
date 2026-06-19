#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,k,q;
int ans[N][105];
int c[N],r[N];
struct node{
	int hang,lie;
};
struct Node{
	int hang,lie,x;
};
vector<int>a[2*N];
//int a[1005][1005];
int l[1005];
vector<node>g[2*N];
queue<Node>Q;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(l,0,sizeof(l));
		memset(c,0,sizeof(c));
		memset(r,0,sizeof(r));
		while(!Q.empty())Q.pop();
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				int o;
				scanf("%d",&o);
				a[i].push_back(o);
				//a[i][j]=o;
				g[o].push_back({i,j});
				if(o==1&&j==1){
					Q.push({i,j,1});
				}
			}
		}
		int Max=-1;
		for(int i=1;i<=q;i++){
			scanf("%d%d",&r[i],&c[i]);
			Max=max(Max,r[i]);
		}
		while(!Q.empty()){
			int Hang=Q.front().hang,Lie=Q.front().lie,X=Q.front().x;
			if(X>Max)break;
			Q.pop();
//			for(int i=0;i<min(a[Hang].size(),k);i++){
//				ans[a[Hang][i]][X]=1;
//				for(int j=0;j<g[a[Hang][i]].size();j++){
//					q.push({g[a[Hang][i]][j],Lie,X+1});
//				}
//			}
			for(int i=Lie+1;i<=min(Lie+k-1,l[Hang]);i++){
				ans[a[Hang][i-1]][X]=1;
				for(int j=0;j<g[a[Hang][i-1]].size();j++){
					if(g[a[Hang][i-1]][j].hang!=Hang) 
					Q.push({g[a[Hang][i-1]][j].hang,g[a[Hang][i-1]][j].lie,X+1});
				}
			}
		}
		for(int i=1;i<=q;i++){
			printf("%d\n",ans[c[i]][r[i]]);
		}
	}
	return 0;
}
