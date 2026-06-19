#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=2e6+5;
int n,m,k;
int bcj[N];
int fid(int x){
	return bcj[x]==x?x:bcj[x]=fid(bcj[x]);
}
struct edge{
	int u,v;
	long long w;
}e[M];
bool cmp(edge l,edge r){
	return l.w<r.w;
}
long long a[20];
long long ans=4e18;
int can[20];
int lowbit(int x){
	return x&-x;
}
int get1(int x){
	int ret=0;
	while(x){
		x-=lowbit(x);
		ret++;
	}
	return ret;
}
void get2(int x){
	int tot=0;
	for(int i=0;i<k;i++){
		if(x&(1<<i)){
			tot++;
			can[tot]=i+1;
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			m++;
			e[m].u=j;
			e[m].v=n+i;
			cin>>e[m].w;
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int x=0;x<(1<<k);x++){
		for(int i=1;i<=n+k;i++){
			bcj[i]=i;
		}
		long long now=0;
		int mx=get1(x);
		get2(x);
		for(int i=1;i<=mx;i++){
			now+=a[can[i]];
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(cnt==n+mx-1) break;
			int u=e[i].u;
			int v=e[i].v;
			long long w=e[i].w;
			if(v>n&&(!(x&(1<<(v-n-1))))) continue;
			if(fid(u)==fid(v)) continue;
			bcj[fid(u)]=bcj[fid(v)];
			now+=w;
			cnt++;
		}
		ans=min(ans,now);
	}
	cout<<ans;
	return 0;
} 
