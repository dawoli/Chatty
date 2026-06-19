#include<bits/stdc++.h>
using namespace std;
struct item{
	long long pointa,pointb,money;
	friend bool operator<(const item x,const item y){
		return x.money>y.money;
	}
};
long long n,m,k,u,v,w,a[15][10005],c[15],f[10005],vis[15];
long long ss,ll;
priority_queue <item> q;
int find(int t){
	if(f[t]!=t){
		f[t]=find(f[t]);
	}
	return f[t];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		q.push(item{u,v,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		item p=q.top();
		q.pop();
		int xx=find(p.pointa);
		int yy=find(p.pointb);
		if(xx!=yy){
			ll=p.money;
			long long flag=0;
			for(int j=1;j<=k;j++){
				if(ll>=c[j]*(1-vis[j])+a[j][p.pointa]+a[j][p.pointb]){
					ll=c[j]*(1-vis[j])+a[j][p.pointa]+a[j][p.pointb];
					flag=j;
				}
			}
			if(flag!=0){
				vis[flag]=1;
			}
			ss+=ll;
			f[yy]=xx;
		}
	}
	cout<<ss;
	return 0;
}
