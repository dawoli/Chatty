#include<bits/stdc++.h>
using namespace std;
char c[1009][1009];
int v[1009][1009];
int a[1009][1009];
bool b(int x,int y,int n,int m){
	if(1<=x&&x<=n&&1<=y&&y<=m){
		return true;
	}
	return false;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int n,m,x,y,d,k,ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		if(k==1){
			if(d==0&&c[x][y+1]=='.'||d==1&&c[x+1][y]=='.'||d==2&&c[x][y-1]=='.'||d==3&&c[x-1][y]=='.'){
				cout<<2<<endl;
			}
			else
				cout<<1<<endl;
		}
		else if(n==1){
			while(d){
				d=(d+1)/4;
				k--;
			}
			cout<<min(k,n)<<endl;
		}
		else{
			a[x][y]=1;
//			d=(d+4-1)%4;
//			v[x][y]=1;
//				cout<<d<<endl;
			while(k--){
				if(d==0&&b(x,y+1,n,m)&&c[x][y+1]=='.'){
//					v[x][y+1]=1;
					y=y+1;
					a[x][y]=1;
//					cout<<x<<' '<<y<<endl;
				}
				else if(d==1&&b(x+1,y,n,m)&&c[x+1][y]=='.'){
//					v[x+1][y]=1;
					x=x+1;
					a[x][y]=1;
//					cout<<x<<' '<<y<<endl;
				}
				else if(d==2&&b(x,y-1,n,m)&&c[x][y-1]=='.'){
//					v[x][y-1]=1;
					y=y-1;
	 				a[x][y]=1;
//					cout<<x<<' '<<y<<endl;
				}
				else if(d==3&&b(x-1,y,n,m)&&c[x-1][y]=='.'){
//					v[x-1][y]=1;
					x=x-1;
					a[x][y]=1;
//					cout<<x<<' '<<y<<endl;
				}
				else{
					d=(d+1)%4;
//					cout<<d<<endl;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(a[i][j]){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
