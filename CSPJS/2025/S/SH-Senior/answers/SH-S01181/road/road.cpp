#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
const int N=5020025;
struct road{
	long long u,v;
	long long w;
}r[N];
long long ml[1005][1005];
long long kr[10005];
bool cmp(road x,road y){
	return x.w<y.w;
}
int f[10005];
int find(int t){
	if(f[t]==t) return t;
	return find(f[t]);
}
long long ans=0,cnt1;
bool check(){
	for(int i=2;i<=n;i++){
		if(find(1)!=find(i)) return false;
	}
	return true;
}
void K(){
	int cnt=0;
	for(int i=1;i<=cnt1;i++){
		int p=r[i].u,q=r[i].v;
		if(p==0||q==0) continue;
		if(find(p)==find(q)) continue;
		if(p>q) swap(p,q);
		f[p]=f[q];
		ans+=r[i].w;
		cnt++;
		//cout<<p<<" "<<q<<" "<<r[i].w<<endl;
		if(cnt==n-1) return;
	}
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	if(k==0){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&r[i].u,&r[i].v);
			scanf("%ld",&r[i].w);
		}
		sort(r+1,r+m+1,cmp);
		cnt1=m+1;
		K();
		cout<<ans;
	}
	else{
		long long x,y,z;
		memset(ml,0x3f,sizeof(ml));
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x>y) swap(x,y);
			cin>>z;
			ml[x][y]=min(ml[x][y],z);
		}
		long long wi;
		for(int i=1;i<=k;i++){
			cin>>wi;
			for(int j=1;j<=n;j++) cin>>kr[j];
			for(int j=1;j<=n;j++){
				for(int k1=j+1;k1<=n;k1++){
					ml[j][k1]=min(ml[j][k1],kr[j]+kr[k1]+wi);
				}
			}
		}
		cnt1=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				r[cnt1].u=i;
				r[cnt1].v=j;
				r[cnt1++].w=ml[i][j];
			}
		}
		cnt1--;
		sort(r+1,r+cnt1+1,cmp);
		K();
		cout<<ans;
	}
	return 0;
}
