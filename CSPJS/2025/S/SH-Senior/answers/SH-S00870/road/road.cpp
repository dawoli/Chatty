#include<bits/stdc++.h>
using namespace std;
int N[10005][10005],n,m,k,l,s,Min[3],c[10005],C[10005],x[10005][15];
long long M;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)N[i][j]=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>l>>s;
		cin>>N[l][s];
		N[s][l]=N[l][s];
	}
	for(int i=1;i<=k;i++){cin>>l;for(int j=1;j<=n;j++)cin>>x[j][i];
	}
	c[1]=1;C[1]=1;
	for(int i=1;i<n;i++){
		Min[2]=INT_MAX;
		for(int j=1;j<=i;j++){
			for(int q=1;q<=n;q++)if(N[c[j]][q]<Min[2]&&!C[q]){
				Min[0]=c[j];
				Min[1]=q;
				Min[2]=N[c[j]][q];}
		}
		M+=Min[2];
		c[i+1]=Min[1];C[Min[1]]=1;
	}
	cout<<M;
	return 0;
}
