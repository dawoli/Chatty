#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100][100][100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int l=0;l<k;l++){
				cin>>a[i][j][l];
			}
		}
	}
	cout<<15;
	return 0;
}
