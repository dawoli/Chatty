#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T,ans=0,n,m,k,x0,y0,d0,x,y,d,x1,y1;
	cin>>T;
	for(;T!=0;T--){
    	cin>>n>>m>>k>>x0>>y0>>d0;
		ans=0;
		x=x0;
    	y=y0;
    	d=d0;
		int map [n+5][m+5]={};
		for (int i=1;i<=n;i++){
		    for (int j=1;j<=m;j++) {
	    		char a;
	    		cin>>a;
		    	if (a=='.') map[i][j]=1;
			}
		}
		for (int st=0;st<=k;st++) {
            if (map[x][y]==1) ans++;
			map[x][y]++;
			x1=x;
			y1=y;
			if (d==0) y1++;
			else if (d==1) x1++;
			else if (d==2) y1--;
			else if (d==3) x1--;
			if(map[x1][y1]==0){
				d=(d + 1) % 4;
				continue;
			}
			x=x1;
			y=y1;
		}
		cout<<ans<<endl;	
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
