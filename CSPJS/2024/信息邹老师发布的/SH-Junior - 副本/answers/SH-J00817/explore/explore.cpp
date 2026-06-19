#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,ans=1,x,y,z,d,r[1001][1001];
char mp[1001][1001];
void check(){
	int a=x,b=y;
	switch(d){
		case 0:{
			y++;
			break;
		}
		case 1:{
			x++;
			break;
		}
		case 2:{
			y--;
			break;
		}
		case 3:{
			x--;
			break;
		}
	}
	if(x<1){
		x++;d=(d+1)%4;
	}
	else if(y<1){
		y++;d=(d+1)%4;
	}
	else if(x>n){
		x--;d=(d+1)%4;
	}
	else if(y>m){
		y--;d=(d+1)%4;
	}
	else if(mp[x][y]=='x'){
		x=a,y=b;d=(d+1)%4;
	}
	else{
		if(r[x][y]==0){
			ans++;r[x][y]=1;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;for(int i=1;i<=t;i++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		r[x][y]=1;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cin>>mp[j][l];
			}
		}
		for(int j=1;j<=k;j++){
			check();
		}
		cout<<ans<<endl;
		ans=1;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				r[j][l]=0;mp[j][l]=0;
			}
		}
	}
	
	return 0;
}

