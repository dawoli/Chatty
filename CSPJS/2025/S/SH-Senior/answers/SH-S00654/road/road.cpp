#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[11],f[10011],np;
long long ans=1e14,c[11],a[11][10001];
struct EDGE{
	int u,v;
	long long w;
	bool operator<(const EDGE &a)const{
		return w>a.w;
	}
}e[1000001];
priority_queue<EDGE>q;
int ff(int a){
	if(f[a]==a)return a;
	return f[a]=ff(f[a]);
}
int s(int a,int b){
	a=ff(a),b=ff(b);
	f[a]=b;
}
long long kr(){
	for(int i=1;i<=n+k;i++)f[i]=i;
	long long re=0;
	int cnt=0;
	while(cnt<np-1){
		int u=q.top().u,v=q.top().v;
		long long w=q.top().w;
		q.pop();
		if(ff(u)!=ff(v)){
			s(u,v);
			re+=w;
			cnt++;
		}
	}
	return re;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	np=n;
	for(int i=0;i<=k;i++){
		while(!q.empty())q.pop();
		for(int j=1;j<=m;j++)
			q.push(e[j]);
		for(int j=1;j<i;j++){
			if(v[j]){
				for(int r=1;r<=n;r++)
					q.push(EDGE{n+j,r,a[j][r]});
			}
		}
		if(i!=0){
			np++;
			for(int j=1;j<=n;j++)
				q.push(EDGE{n+i,j,a[i][j]});
		}
		long long co=kr();
		if(i==0)ans=co;
		else if(co+c[i]<ans)v[i]=1,ans=c[i]+co;
		else np--;
	}
	cout<<ans<<endl;
	return 0;
}

