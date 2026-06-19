#include<bits/stdc++.h>
using namespace std;
//最小生成树+2^n枚举城市化
//T2
struct lk{
	int u,v,w;
}arr[2000005],aa[2000005];
long long n,m,k,c[15],pr[15][10005]; 
bool cmp(lk a,lk b){
	return a.w<b.w;
}
int fa[2000005];
inline int getfa(int x){
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
inline void merge(int a,int b){
	fa[getfa(a)]=b;
}
long long krsk(int nn,int mm){
	for(int i=1;i<=nn;i++){
		fa[i]=i;
	}
	for(int i=1;i<=mm;i++){
		aa[i]=arr[i];
	}
	sort(aa+1,aa+1+mm,cmp);
	long long cnt=0,ans=0;
	for(int i=1;i<=mm;i++){
		if(getfa(aa[i].u)==getfa(aa[i].v)){
			continue;
		}
		merge(aa[i].u,aa[i].v);
		cnt++;
		ans+=aa[i].w;
		if(cnt==nn-1){
			return ans;
		}
	}
//	cerr<<1;
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1,u,v,w;i<=m;i++){
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>pr[i][j];
		}
	}
//	cerr<<clock();
	long long ans=100000000000000ll;
	for(long long st=0;st<=(1<<k)-1;st++){
		if(clock()>950) break;
		long long nn=n,mm=m,dv=0;
		for(int q=0;q<k;q++){
			int p=(1<<q);
			if(st&p){
				nn++;
				dv+=c[q+1];
				for(int i=1;i<=n;i++){
					arr[++mm].u=nn;
					arr[mm].v=i;
					arr[mm].w=pr[q+1][i];
				}
			}
		}
		ans=min(ans,krsk(nn,mm)+dv);
	}
	cout<<ans;
	return 0;
}

