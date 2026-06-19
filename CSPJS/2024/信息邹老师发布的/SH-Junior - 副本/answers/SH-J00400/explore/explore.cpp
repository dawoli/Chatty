#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	char a[1005][1005]={};
	int t,n,m,k,x,y,d,sum=1;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int r=1;r<=m;r++){
				cin>>a[j][r];
			}
		}
		for(int j=1;j<=k;j++){
			if(d%4==0){
				if(a[x][y+1]=='.'&&x<=n&&x>=1&&y+1<=m&&y+1>=1){
					y=y+1;
					sum++;
				}
				else{
					d=0;
					d=d+1;
				}
			}
			else if(d%4==1){
				if(a[x+1][y]=='.'&&x+1<=n&&x+1>=1&&y>=m&&y>=1){
					x=x+1;
					sum++;
				}
				else{
					d=d+1; 
				}
			} 
			else if(d%4==2){
				if(a[x][y-1]=='.'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){
					y=y-1;
					sum++;
				}
				else{
					d=d+1;
				}
			}
			else{
				if(a[x-1][y]=='.'&&x-1<=n&&x-1>=1&&y<=m&&y>=1){
					x=x-1;
					sum++;
				}
				else{
					d=d+1;
				}
			}
		}
		cout<<sum<<endl;
		sum=1;
	}
	return 0;
}
