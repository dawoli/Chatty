#include<bits/stdc++.h>
using namespace std;
char f[1005][1005];
int s[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,x,y,d,k,sum=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		cin>>n>>m>>k>>x>>y>>d;
		s[x][y]=1;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>f[j][l];
			}
		}
		while(k>0){
			if(d==0){
				if(f[x][y+1]=='x'||y==m) d=(d+1)%4;
				else{
					y++;s[x][y]=1;
				}
			}
			else if(d==1){
				if(f[x+1][y]=='x'||x==n) d=(d+1)%4;
				else{
					x++;s[x][y]=1;
				}
			}
			else if(d==2){
				if(f[x][y-1]=='x'||y==1) d=(d+1)%4;
				else{
					y--;s[x][y]=1;
				}
			}
			else if(d==3){
				if(f[x-1][y]=='x'||x==1) d=(d+1)%4;
				else{
					x--;s[x][y]=1;
				}
			}
			k--;
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				sum+=s[j][l];
			}
		}
		cout<<sum<<endl;
		for(int j=1;j<=n;j++)
			for(int l=1;l<=m;l++)
				s[j][l]=0;
	}
	return 0;
}
