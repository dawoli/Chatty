#include<bits/stdc++.h>
using namespace std;

#define int long long

const int Maxn=2e6,Maxn1=1e4;
struct line{
	int a,b,c;
} d[Maxn+5];
int n,m,k,f[Maxn1+5],size[Maxn1+5],cnt,ans;

bool cmp(line a,line b){
	return a.c<b.c;
}

int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i,size[i]=1;
	int p=m;
	for(int i=1;i<=m;i++){
		cin>>d[i].a>>d[i].b>>d[i].c;
	}
	for(int i=1;i<=k;i++){
		int y;
		cin>>y;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			p++,d[p].a=i,d[p].b=j,d[p].c=x+y;
		}
	}
	sort(d+1,d+p+1,cmp);
	for(int i=1;i<=p;i++){
		int xx=d[i].a,yy=d[i].b,z=d[i].c;
		xx=find(xx),yy=find(yy);
		if(xx==yy) continue;
		cnt++,ans+=z;
		if(size[xx]<size[yy]) swap(xx,yy);
		f[yy]=xx,size[xx]+=size[yy];
		if(cnt==n-1){
			break;
		} 
	}
	cout<<ans<<endl;
	return 0;
}
