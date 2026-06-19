#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int z = 0;z<t;z++){
		int n,m,k,x,y,d,cnt = 1;
		cin>>n>>m>>k>>x>>y>>d;
		char a[n+1][m+1][2];
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				cin>>a[i][j][0];
				a[i][j][1]='a';
			}
		}a[x][y][1]='Y';
		for(int i = 0;i<k;i++){
			int x1 = x;
			int y1 = y;
			if(d==0){
				y1++;
			}if(d==1){
				x1++;
			}if(d==2){
				y1--;
			}if(d==3){
				x1--;
			}
			if(x1>=1&&x1<=n&&y1<=m&&y1>=1&&a[x1][y1][0]=='.'){
				x=x1;
				y=y1;
				if(a[x1][y1][1]!='Y'){
					cnt++;
					a[x1][y1][1]='Y';
				}
				continue;
			}else{
				d++;
				d%=4;
				continue;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
