#include<bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while (T--){
		int n,m,k,x0,y0,d0,x1,y1,d1;
		cin >> n >> m >> k >> x0 >> y0 >> d0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			vis[i][j]=0;
		}
		int ans=1;
		vis[x0][y0]=1;
		while(k--){
			//º∆À„x1,y1,d1
			x1=x0;y1=y0;
			if(d0==0)y1++;
			if(d0==1)x1++;
			if(d0==2)y1--;
			if(d0==3)x1--;
			if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&a[x1][y1]=='.'){
				x0=x1;y0=y1;
				if(!vis[x1][y1])ans++;
				vis[x1][y1]=1;
			}
			else d0=(d0+1)%4;
		}
		cout << ans << endl;
	}
	return 0;
}
