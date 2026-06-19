#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
const int N=1e5+9;
const int M=1e6+9;
const int K=19;
int n,m,k;
int u[M],v[M],w[M];
int c[K];
int a[K][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool is_A=true;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			is_A=false;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				is_A=false;
			}
		}
	}
	if(is_A){
		cout<<0<<endl;
		return 0;
	}
	return 0;
}
