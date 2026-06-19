#include<bits/stdc++.h>
using namespace std;
const long long M=2e6+7,N=2e4+7;
long long n,m,k,c[15],a[15][N],minn=2e9;
long long fa[N];
bool isA=1;
struct edge{
	long long u,v,w;
} e[M],ne[M];
long long find(long long x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(long long x,long long y){
	fa[find(x)]=find(y);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long kruskal(long long ch){
	long long num=0,ans=0,cntf=0;
	for(long long i=1;i<=n+k;i++) fa[i]=i;
	for(long long i=1;i<=m;i++) ne[++num]=e[i];
	for(long long i=1;i<=k;i++){
		if((ch>>(i-1))&1){
			cntf++;
			ans+=c[i];
			for(long long j=1;j<=n;j++){
				ne[++num].u=n+i,ne[num].v=j,ne[num].w=a[i][j];
			}
		}
	}
	sort(ne+1,ne+1+num,cmp);
	long long cnt=0;
	for(long long i=1;i<=num;i++){
		long long p=ne[i].u,q=ne[i].v;
		if(find(p)==find(q)) continue;
		merge(p,q);
		ans+=ne[i].w;
		cnt++;
		if(cnt==n+cntf-1) break;
	}
	return ans;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) isA=0;
		int flag=0;
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) flag=1;
		}
		if(flag==0) isA=0;
	}
	if(isA){
		cout<<kruskal((1<<k)-1)<<endl;
		return 0;
	}
	for(long long i=0;i<(1<<k);i++){
		long long temp=kruskal(i);
//		cout<<i<<" "<<temp<<endl;
		minn=min(minn,temp);
	}
	cout<<minn<<endl;
	
	return 0;
}
//It should be 72pts with the time of O(2^k*mlogm).
//But why can't the 11/12th case run fast enough in my computer??? It costs over 4 second!!!
//So it is only 52pts!!!
//What's more, my computer isn't good enough to type Chinese!!!
