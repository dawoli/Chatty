#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005];
int t, n, m, k, x, y, d, sum=0; 
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin >> n >> m >> k >> x >> y >> d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k+1;i++){
			b[x][y]=1;
			if(d==0){
				if( x == 0 || y==0 || y+1 > m || x>n || a[x][y+1]=='x' || y+1==0){
					d+=1;
					continue;
				}
				else{
					y+=1;
					continue;
				}	
			}
			else if(d==1){
				if( x == 0 || y==0 || y > m || x+1 > n || a[x+1][y]=='x' || x+1==0){
					d+=1;
					continue;
				}
				else{
					x+=1;
					continue;
				}	
			}
			else if(d==2){
				if( x == 0 || y-1==0 || y-1 > m || x > n || a[x][y-1]=='x' || y==0){
					d+=1;
					continue;
				}
				else{
					y-=1;
					continue;
				}	
			}
			else if(d==3){
				if( x-1 == 0 || y==0 || y > m || x-1 > n || a[x-1][y]=='x' || x == 0){
					d=0;
					continue;
				}
				else{
					x-=1;
					continue;
				}	
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]!=0){
					sum++;
				}	
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
