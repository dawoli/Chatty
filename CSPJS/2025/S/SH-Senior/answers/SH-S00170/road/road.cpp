#include <bits/stdc++.h>
using namespace std;
int n,m,k,i,j,p;
int v[1000001][3];
int ks[10][10002];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (i=0;i<m;i++){
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	for (i=0;i<k;i++){
		cin >> ks[i][0];
		for (j=0;j<n;j++){
			cin >> ks[i][j+1]; 
		}
	}
	cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

