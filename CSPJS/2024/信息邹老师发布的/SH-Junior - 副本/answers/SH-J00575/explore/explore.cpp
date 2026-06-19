#include<bits/stdc++.h>
using namespace std;
int main(){
	char map[101][101];
	int map1[101][101]={};
	int n,m,k,x,y,d,x1,y1,sum=0;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	map1[x][y]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<k;i++){
		if(d==0){
			x1=x;
			y1=y+1;
		}else if(d==1){
			x1=x+1;
			y1=y;
		}else if(d==2){
			x1=x;
			y1=y-1;
		}else if(d==3){
			x1=x-1;
			y1=y;
		}
		if(x1<1||x1>n||y1<1||y1>m||map[x1][y1]=='x'){
			d=(d+1)%4;
			continue;
		}else{
			x=x1;
			y=y1;
			map1[x][y]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map1[i][j]==1){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

