#include<bits/stdc++.h>
using namespace std; 
int t,n,m,k,x,y,d,f[1005][1005],sum; 
char e[1005][1005]; 
int main(){
	freopen("explore.in","r",stdin); 
	freopen("explore.out","w",stdout); 
	cin>>t; 
	for(int i=1; i<=t; i++){
		cin>>n>>m>>k; 
		cin>>x>>y>>d; 
		for(int j=1; j<=n; j++){
			for(int z=1; z<=m; z++){
				cin>>e[j][z]; 
			}
		}
		f[x][y]=1; 
		for(int j=1; j<=k; j++){
			if(d==0){
				if(y+1<=m && e[x][y+1]=='.') y+=1; 
				else d=1; 
				f[x][y]=1; 
				continue; 
			}
			if(d==1){
				if(x+1<=n && e[x+1][y]=='.') x+=1; 
				else d=2; 
				f[x][y]=1; 
				continue; 
			}
			if(d==2){
				if(y-1!=0 && e[x][y-1]=='.') y-=1; 
				else d=3; 
				f[x][y]=1; 
				continue; 
			}
			if(d==3){
				if(x-1!=0 && e[x-1][y]=='.') x-=1; 
				else d=0; 
				f[x][y]=1; 
				continue; 
			}
		}
		for(int j=1; j<=n; j++){
			for(int z=1; z<=m; z++){
				if(f[j][z]==1) sum+=1,f[j][z]=0; 
			}
		}
		cout<<sum<<endl; 
		sum=0; 
	}
	fclose(stdin); 
	fclose(stdout); 
}
