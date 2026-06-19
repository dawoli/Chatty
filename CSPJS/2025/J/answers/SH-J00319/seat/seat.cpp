#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[11][11],p[101];
signed main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&p[i]);
	}r=p[1];
	sort(p+1,p+n*m+1);
	reverse(p+1,p+n*m+1);
	int pnt=1; 
	for(int i=1;i<=m;i++){
		if(i%2==1) for(int j=1;j<=n;j++) a[j][i]=p[pnt],pnt++;
		else if(i%2==0) for(int j=n;j>=1;--j) a[j][i]=p[pnt],pnt++;
	}for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(a[i][j]==r){
			printf("%d %d\n",j,i);
			return 0;
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
