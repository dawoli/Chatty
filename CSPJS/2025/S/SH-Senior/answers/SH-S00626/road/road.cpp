#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int f[N];
int cnt;
int n,m,k;
int a[N],b[N],c[N],x[N],y[N];
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			cin>>y[j];
		}
	}
	for(int i=1;i<=n;i++){
		int r1=find(a[i]);
		int r2=find(b[i]);
		if(r1!=r2){
			f[r2]=r1;
			int h=y[i]+x[i];
			cnt+=min(c[i],h);
		}
	}
	cout<<cnt;
	return 0;
}
