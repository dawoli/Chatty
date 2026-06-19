#include<bits/stdc++.h>
using namespace std;
int t;
char a[1010][1010];
int b[1010][1010];
bool check(int x,int y,int n,int m){
	if(x<=0||y<=0)  return true;
	if(x>n||y>m)  return true;
	return false;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k,x0,y0,d,cnt=0;
		cin>>n>>m>>k>>x0>>y0>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)  b[i][j]=0;
		}
		b[x0][y0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)  cin>>a[i][j];
		}
		while(k--){
			if(d==0){
				y0++;
				if(a[x0][y0]=='x'||check(x0,y0,n,m))  y0--,d=1;
				else b[x0][y0]=1;
			}
			else if(d==1){
				x0++;
				if(a[x0][y0]=='x'||check(x0,y0,n,m))  x0--,d=2;
				else  b[x0][y0]=1;
			}
			else if(d==2){
				y0--;
				if(a[x0][y0]=='x'||check(x0,y0,n,m))  y0++,d=3;
				else  b[x0][y0]=1;
			}
			else if(d==3){
				x0--;
				if(a[x0][y0]=='x'||check(x0,y0,n,m))  x0++,d=0;
				else  b[x0][y0]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]==1)  cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
