#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d;
char mp[1010][1010];
int book[1010][1010];
bool check(int s,int z){
	if(s>=1&&s<=n&&z>=1&&z<=m) return true;
	else return false;
}
int oper(){
	int cnt=0;
	int nx=x,ny=y;
	book[x][y]=1;
	for(int i=1;i<=k;i++){
		if(d==0) {
			ny=y+1;
		}
		else if(d==1){
			nx=x+1;
		}
		else if(d==2){
			ny=y-1;
		}
		else{
			nx=x-1;
		}
		if(mp[nx][ny]=='x'||!(nx>=1&&nx<=n&&ny>=1&&ny<=m)){
			nx=x,ny=y;
			d=(d+1)%4;
			continue;
		}
		else{
			book[nx][ny]=1;
		}
		x=nx,y=ny;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(book[i][j]==1) cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		cout<<oper()<<endl;
	}
	return 0;
}
/*
....x


*/
