#include <bits/stdc++.h>
using namespace std;
int t,n,m,num,x,y,d,n_x,n_y,cnt;
char a[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> n >> m >> num >> x >> y >> d;
		cnt=1;
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				cin >> a[j][k];
			}
		}
		a[x][y]='y';
		for (int j=1;j<=num;j++){
			n_x=x;
			n_y=y;
			if (d==0) n_y=y+1;
			else if (d==1) n_x=x+1;
			else if (d==2) n_y=y-1;
			else n_x=x-1;
			if (n_x>0 && n_x<=n && n_y>0 && n_y<=m && a[n_x][n_y]!='x'){
				x=n_x;
				y=n_y;
			}else{
				d=(d+1)%4;
				continue;
			}
			if (a[x][y]=='.'){
				cnt++;
				a[x][y]='y';
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
