#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100015],v[100015],w[100015],g[100015],l[15][10015],sum,ans,p,q,aaa;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if (u[i]>v[i]) swap(u[i],v[i]);
	}
	for (int i=1;i<=k;i++){
		cin>>g[i];
		for (int j=1;j<=n;j++){
			cin>>l[i][j];
			for (int o=j+1;o<=n;o++){
				sum++;
				u[m+sum]=j,v[m+sum]=o;
//				cout<<l[j][o];
			}
		}
	}
	for (int i=1;i<=k;i++){
		for (int j=1;j<=n;j++){
			for (int o=j+1;o<=n;o++){
				aaa++;
				w[m+aaa]=g[i]+l[i][j]+l[i][o];
				
			}
		}
	}
	for (int i=1;i<=m+sum;i++){
		for (int j=1;j<=m+sum;j++){
			if (u[i]==u[j]&&v[i]==v[j]) w[i]=min(w[i],w[j]);
		}
	}
	sort (w+m+sum/2,w+m+sum);
	for (int i=m+sum/2;i<m+sum/2+m-1;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
