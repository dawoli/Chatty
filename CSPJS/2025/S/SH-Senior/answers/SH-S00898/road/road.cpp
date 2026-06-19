#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,k;
int g[N][N];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,b,v,maxx=0,cimax=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>v;
		g[a][b]=v;g[b][a]=v;
	}
}
