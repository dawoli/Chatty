#include<iostream>
using namespace std;
string mp[1005];
int delta[4][2]={0,1,1,0,0,-1,-1,0};
int T,n,m,k,x,y,d,num;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		num=0;
		for(int j=0;j<=1000;j++)mp[j]="";
		cin>>n>>m>>k>>x>>y>>d; 
		for(int a=1;a<=n;a++){
			cin>>mp[a];
			mp[a]="#"+mp[a];
		}
		mp[x][y]='&';num++;
		for(int j=1;j<=k;j++){
			int nx=x+delta[d][0];
			int ny=y+delta[d][1];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&(mp[nx][ny]=='.'||mp[nx][ny]=='&')){
				if(mp[nx][ny]=='.'){
					mp[nx][ny]='&';
					num++;
				}
				x=nx;y=ny;
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<num<<endl;
	}
	return 0;
} 
