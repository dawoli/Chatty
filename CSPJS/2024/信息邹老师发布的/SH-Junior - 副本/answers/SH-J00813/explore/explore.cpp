#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int azerty=0;azerty<T;azerty++){
	    int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		x--;y--;
		bool map[n][m];
		memset(map,false,sizeof(map));
		bool foot[n][m];
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				foot[i][j]=false;
			}
		}
		for(int i=0;i<n;i++){
			string mp;
			cin>>mp;
			for(int j=0;j<m;j++){
				if(mp[j]=='.'){
					map[i][j]=false;
				}else if(mp[j]=='x'){
					map[i][j]=true;
				}
			}
		}
		for(int q=0;q<k;q++){
			int xNova,yNova;
			foot[x][y]=true;
			if(d==0){
				xNova=x;yNova=y+1;
			}else if(d==1){
				xNova=x+1;yNova=y;
			}else if(d==2){
				xNova=x;yNova=y-1;
			}else if(d==3){
				xNova=x-1;yNova=y;
			}
			if(xNova>=0&&xNova<n&&yNova>=0&&yNova<m&&map[xNova][yNova]==false){
				x=xNova;y=yNova;
			}else{
				d=(d+1)%4;
			}
		}
		foot[x][y]=true;
		sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(foot[i][j]){
				    sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0; 
} 
