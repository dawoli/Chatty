#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int hsh[1010][1010];
bool fjudge(int d,int x,int y,int n,int m){
	x+=dx[d],y+=dy[d];
	if(x>n||x<1||y>m||y<1) return false;
	if(hsh[x][y]==2) return false;
	return true;
}
int f(){
	int sum=0;
	int n,m,k;
	int x,y,d;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a;
			cin>>a;
			if(a=='x') hsh[i][j]=2;
			else hsh[i][j]=0;
		}
	}
	while(k--){
		if(hsh[x][y]==0) sum++;
		hsh[x][y]=1;
		if(fjudge(d,x,y,n,m)){
			x+=dx[d],y+=dy[d];
			if(hsh[x][y]==0) sum++;
			hsh[x][y]=1;
		}
		else{
			d=(d+1)%4;
		}
	}
	return sum;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cout<<f()<<endl; 
	}
	return 0; 
}
