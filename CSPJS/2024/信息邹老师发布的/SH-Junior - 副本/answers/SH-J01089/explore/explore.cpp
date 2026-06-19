#include <bits/stdc++.h>
using namespace std;
char map1[1005][1005];
bool map2[1005][1005];
int derx[4]={0,1,0,-1},dery[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	int sum=0;
	while(t--){
		for(int i=1;i<=1005;i++){
			for(int j=1;j<=1005;j++){
				map1[i][j]='x';
				map2[i][j]=0;
			}
		}
		int n,m,k,cnt=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map1[i][j];
				if(map1[i][j]=='x') sum++;
			}
		}
		map2[x][y]=1;
		if(sum){
			while(k--){
			if((x+derx[d])>n||(y+dery[d])>m||(x+derx[d])==0||(y+dery[d])==0||map1[x+derx[d]][y+dery[d]]=='x'){
				d=(d+1)%4;
			}
			else{
				x+=derx[d];
				y+=dery[d];
				map2[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt+=map2[i][j];
			}
		}
		cout<<cnt<<endl;
		}
		else{
			while(k--){
			if((x+derx[d])>n||(y+dery[d])>m||(x+derx[d])==0||(y+dery[d])==0||map1[x+derx[d]][y+dery[d]]=='x'||map2[x+derx[d]][y+dery[d]]==1){
				d=(d+1)%4;
			}
			else{
				x+=derx[d];
				y+=dery[d];
				map2[x][y]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt+=map2[i][j];
			}
		}
		cout<<cnt<<endl;
		}
	}
	return 0;
} 
