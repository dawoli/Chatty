#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>>P;
int n,m,k,c[11],f[11][10010],p[10020];
long long ans=1e18;
set<P>q,q2;
int find(int i){return (p[i]==i)?i:p[i]=find(p[i]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int w=1,a,b,c;w<=m;w++)scanf("%d%d%d",&a,&b,&c),q.insert({c,{a,b}});
	for(int w=1;w<=k;w++){
		scanf("%d",&c[w]);
		for(int x=1;x<=n;x++)scanf("%d",&f[w][x]);
	}
	for(int w=0;w<(1<<k);w++){
		for(int x=1;x<=n+k;x++)p[x]=x;
		long long s=0;int t=0,cnt=n;
		for(int x=0;w>>x;x++)if(w>>x&1){
			s+=c[x+1],cnt++;
			for(int y=1;y<=n;y++)q.insert({f[x+1][y],{y,n+x+1}});
		}
		while(t!=cnt-1&&q.size()){
			int d=(*q.begin()).first,i=(*q.begin()).second.first,j=(*q.begin()).second.second;q2.insert({d,{i,j}}),q.erase({d,{i,j}}),i=find(i),j=find(j);
			if(i!=j)t++,s+=d,p[i]=j;
		}
		if(w==0)q.clear();
		while(q2.size()){
			int d=(*q2.begin()).first,i=(*q2.begin()).second.first,j=(*q2.begin()).second.second;q2.erase({d,{i,j}}),q.insert({d,{i,j}});
		}
		q2.clear();
		for(int x=0;w>>x;x++)if(w>>x&1)for(int y=1;y<=n;y++)q.erase({f[x+1][y],{y,n+x+1}});
		ans=min(ans,s);
	}
	printf("%lld",ans);
	return 0;
}
