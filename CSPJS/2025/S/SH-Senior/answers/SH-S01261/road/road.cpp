#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,K,sett[10015];
pair<int,pair<int,int> >edg[1000005],uedg[110005];int pt1;
int E[110005][3],cst[15],ans=842460842460842460ll;

int Find(int x){return sett[x]=sett[x]==x?x:Find(sett[x]);}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie()->sync_with_stdio(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int x,y,v;cin>>x>>y>>v;
		edg[i]=make_pair(v,make_pair(x,y));
	}
	for(int i=1;i<=n+K;i++)sett[i]=i;
	sort(edg+1,edg+m+1);
	for(int i=1;i<=m;i++){
		int x=Find(edg[i].second.first),y=Find(edg[i].second.second);if(x==y)continue;
		uedg[++pt1]=edg[i];sett[x]=y;
	}
	for(int i=1;i<=n;i++)sett[i]=i;
	for(int i=1;i<=K;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++){
			int v;cin>>v;uedg[++pt1]=make_pair(v,make_pair(i+n,j));
		}
	}
	sort(uedg+1,uedg+pt1+1);
	for(int i=1;i<=pt1;i++){
		E[i][0]=uedg[i].second.first;E[i][1]=uedg[i].second.second;E[i][2]=uedg[i].first;
	}
	for(int z=0;z<(1<<K);z++){
		int ca=0;
		for(int i=1;i<=K;i++)if((z>>i-1)&1)ca+=cst[i];
		for(int i=1;i<=pt1;i++)if(E[i][0]<=n||((z>>E[i][0]-n-1)&1)){
			int x=Find(E[i][0]),y=Find(E[i][1]);if(x!=y){sett[x]=y;ca+=E[i][2];}
		}
		ans=min(ans,ca);
		for(int i=1;i<=n+K;i++)sett[i]=i;
	}
	cout<<ans;
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

liuzhuyuan pray for me /kel
shaonan pray for me /kel
gongmaohan pray for me /kel
chenhongyi pray for me /kel
wanghoupu pray for me /kel
zhangleyuan pray for me /kel
zhuziruo pray for me /kel
*/
