#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int fa(int l,int r){
	int mid=(l+r)>>1;
	return lowbit(mid);
}
struct nd{
	int x,y,z;
}a[100001];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<vector<int> > g;
	int a[100001],b[1000010],c[100001];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	} 
	int d[19][10010];
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n+1;++j){
			cin>>d[i][j];
			if(d[i][j]>g.size()){
				d[i][j]=max(a[i]-b[i],b[i]-a[i]);
				g[b[i]].push_back(d[i][j]);
				d[i][j]=max(a[i]-b[i],b[i]-a[i]);
				g[a[i]].push_back(d[j][i]);
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n+1;++j){
			d[i][j]=max(d[i][j],max(d[i-1][j],a[i]));
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			int cnt=g.size();
			for(int k=1;k<=cnt;++k){
				d[i][k]=max(d[i-cnt][k],d[i][cnt-k]);
			}
		}
	} 
	cout<<d[1][n]<<endl;
	return 0;
}

