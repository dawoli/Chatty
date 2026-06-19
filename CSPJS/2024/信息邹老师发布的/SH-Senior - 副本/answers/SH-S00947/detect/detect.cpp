#include<bits/stdc++.h>
using namespace std;
int T,n[21],m[21],L[21],V[21];
int d[21][100005],v[21][100005],a[21][100005],p[21][100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n[i]>>m[i]>>L[i]>>V[i];
		for(int j=1;j<=n[i];j++){
			cin>>d[i][j]>>v[i][j]>>a[i][j];
		}
		for(int j=1;j<=m[i];j++){
			cin>>p[i][j];
		}
	}
	return 0;
}
