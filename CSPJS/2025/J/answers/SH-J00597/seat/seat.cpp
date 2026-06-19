#include<bits/stdc++.h>
using namespace std;
int n,m,rk,a[11][11],f[101],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int w=1;w<=m;w++)
		if(w%2)for(int x=1;x<=n;x++)a[w][x]=++t;
		else for(int x=n;x;x--)a[w][x]=++t;
	for(int w=1;w<=n*m;w++)scanf("%d",&f[w]),rk+=(f[w]>=f[1]);
	for(int w=1;w<=m;w++)for(int x=1;x<=n;x++)if(a[w][x]==rk)printf("%d %d",w,x);
	return 0;
}
