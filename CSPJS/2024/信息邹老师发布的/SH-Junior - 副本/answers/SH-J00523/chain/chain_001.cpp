#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,l,f[210][200010],r,c,p,cnt[200010],d;
vector<pair<int,int>>e[200010];
vector<int>a[100010],g;
map<int,bool>h[200010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&k,&q),memset(f,0,sizeof(f)),memset(cnt,0,sizeof(cnt));
		for(int w=1;w<=n;w++)h[w].clear();
		for(int w=0;w<g.size();w++)e[g[w]].clear();
		g.clear();
		for(int w=1;w<=n;w++){
			scanf("%d",&l);
			for(int x=1;x<=l;x++){
				scanf("%d",&c),e[c].push_back({w,x-1}),a[w].push_back(c);
				if(!cnt[c])cnt[c]=1,p++,g.push_back(c);
			}
		}
		for(int w=1;w<=n;w++)for(int x=1;x<a[w].size();x++){
			int g=a[w][x];
			for(int y=0;y<e[g].size();y++)if(e[g][y].first!=w)for(int z=e[g][y].second+1,p=2;p<=k&&z<a[e[g][y].first].size();p++,z++)h[a[e[g][y].first][z]][g]=1;
		}
		f[0][1]=1;
		for(int w=1;w<=200;w++)for(int x=0;x<g.size();x++)for(int y=0;y<g.size();y++)if(h[g[x]][g[y]]&&f[w-1][g[y]]){f[w][g[x]]=1;break;}
		while(q--)scanf("%d%d",&c,&d),printf("%d\n",f[c][d]);
	}
	return 0;
}
