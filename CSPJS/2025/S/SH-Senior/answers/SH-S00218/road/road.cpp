#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u[100005],v[100005],w[100005],c[100005];
	int a[15][100005];
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= m;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for (int i = 1;i <= k;i++){
		scanf("%d",&c[i]);
		for (int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	return 0;
} 
