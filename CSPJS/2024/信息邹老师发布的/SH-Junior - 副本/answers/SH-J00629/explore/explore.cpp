#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,k,x,y,x1,y1,d,cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		x1=x;
		y1=y;
		char c[n+1][m+1];
		bool book[n+1][m+1];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			cin>>c[i][j];
			book[i][j]=0;
		}
		book[x][y]=1;
		for(int i=0;i<k;i++){
			switch(d){
				case 0:y1+=1;break;
				case 1:x1+=1;break;
				case 2:y1-=1;break;
				case 3:x1-=1;break;
			}
			if(1<=x1&&x1<=n&&1<=y1&&y1<=m&&c[x1][y1]=='.'){
				x=x1;
				y=y1;
				if(book[x1][y1]==0){
					cnt+=1;
					book[x1][y1]=1;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
	}
}
