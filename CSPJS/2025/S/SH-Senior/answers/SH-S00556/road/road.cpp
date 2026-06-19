#include<bits/stdc++.h>
using namespace std;
const int N=10015,M=1e6+5;
typedef long long ll;
struct node{
	int x,y,z;
}e[1030][N],s[M],d[12][N];
int f[N],cnte[1030],fe[12];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){return x.z<y.z;}
int lowbit(int x){return x&(-x);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;ll ans=0;
	cin>>n>>m>>k;
	for(int o=1;o<=n+k;o++) f[o]=o;
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].z;
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=s[i].x,y=s[i].y,z=s[i].z;
		if(find(x)!=find(y)){
			ans+=z;
			cnte[0]++;
			e[0][cnte[0]]={x,y,z};
			f[f[x]]=f[y];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>fe[i];
		for(int j=1,x;j<=n;j++){
			cin>>x;
			d[i][j]={n+i,j,x};
		}
		sort(d[i]+1,d[i]+1+n,cmp);
	}
	for(int st=1;st<(1<<k);st++){
		for(int o=1;o<=n+k;o++) f[o]=o;
		ll nw=0;
		int ad=lowbit(st),pv=st^ad,num=0;
		for(int tmp=ad;tmp;tmp>>=1) num++;
		for(int i=1;i<=k;i++) if(st>>(i-1)&1) nw+=fe[i];
		int j=1;
		for(int i=1;i<=cnte[pv];i++){
			int x,y,z;
			while(j<=n && d[num][j].z<e[pv][i].z){
				x=d[num][j].x,y=d[num][j].y,z=d[num][j].z;
				if(find(x)!=find(y)){
					nw+=z;
					cnte[st]++;
					e[st][cnte[st]]={x,y,z};
					f[f[x]]=f[y];
				}
				j++;
			}
			x=e[pv][i].x,y=e[pv][i].y,z=e[pv][i].z;
			if(find(x)!=find(y)){
				nw+=z;
				cnte[st]++;
				e[st][cnte[st]]={x,y,z};
				f[f[x]]=f[y];
			}
		}
		while(j<=n){
			int x=d[num][j].x,y=d[num][j].y,z=d[num][j].z;
			if(find(x)!=find(y)){
				nw+=z;
				cnte[st]++;
				e[st][cnte[st]]={x,y,z};
				f[f[x]]=f[y];
			}
			j++;
		}
		ans=min(ans,nw);
	}
	cout<<ans;
	return 0;
}
