#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000009],v[1000009],w[1000009],c[19],a[19][10009];
queue<int> q;
bool b[1000009];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	while(q.size()){
//		int x=q.front();
//		b[0]=true;
//		for(int y=0;y<l[x].size();y++){
//			int z=l[x][y].to;
//			if(!b[y]&&l[x][y].nxt+f[y]<l[y][z]){
//				l[y][z]=l[x][y].nxt+f[y];
//				q.pop();
//			}
//		}
//	}
//	cout<<f[m];
	sort(w+1,w+m+1);
	for(int i=1;i<m;i++){
		sum+=w[i];
	}
	cout<<sum;
	return 0;
}
