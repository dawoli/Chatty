#include<bits/stdc++.h>
using namespace std;

int T;//数据数量
int n,m,k;
int x,y,d;
bool maps[1003][1003];
bool path[1003][1003];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	for(int t=0;t<T;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				path[i][j]=0;
				maps[i][j]=0;
			}
		}
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			string st;cin>>st;
			for(int j=1;j<=m;j++){
				if(st[j-1]=='.')
					maps[i][j] = false;
				else
					maps[i][j] = true;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<maps[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		//rcout<<"1";
		path[x][y]=true;
		for(int f=0;f<k;f++){
			int tx,ty;
			//1
			if(d==0){
				tx=x;
				ty=y+1;
			}if(d==1){
				tx=x+1;
				ty=y;
			}if(d==2){
				tx=x;
				ty=y-1;
			}if(d==3){
				tx=x-1;
				ty=y;
			}
			//cout<<"2";
			//2
			//cout<<"txy"<<tx<<" "<<ty<<endl;
			if(1<=tx && tx<=n && 1<=ty && ty<=m && (!maps[tx][ty])){
				x=tx;y=ty;
				path[x][y]=true;
				//cout<<"goto "<<x<<" "<<y<<endl;
				
			}
			else{
				//cout<<"turn right "<<x<<" "<<y<<endl;
				d=(d+1)%4;
			}
		}
		
		//count
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(path[i][j]) {
					cnt++;
					//cout<<"path"<<i<<j<<endl;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
