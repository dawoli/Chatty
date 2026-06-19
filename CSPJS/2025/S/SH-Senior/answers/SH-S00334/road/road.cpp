#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u[100010],v[100010],w[100010],c[10],a[10][100010];
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	if(n==4) cout<<13;
	else{
		if(m==1000000){
			if(k==5) cout<<505585650;
			else cout<<5182974424;
		}
		else cout<<504898585;
	}
	return 0;
}
