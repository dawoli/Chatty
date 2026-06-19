#include<iostream>
using namespace std;
int dic[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vic[1002][1002];
int main(){
	freopen("explore3.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,k,ans=1;
		int sx,sy,nx,ny,d;
		char map[1002][1002];
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			string l;
			cin>>l;
			for(int j=1;j<=m;j++){
				map[i][j]=l[j-1];
			}
		}
		vic[sx][sy]=1;
		while(k--){
			nx=sx+dic[d][0];
			ny=sy+dic[d][1];
			if((nx<=n&&nx>=1)&&(ny<=m&&ny>=1)&&map[nx][ny]!='x'){
				sx=nx;
				sy=ny;
				if(vic[nx][ny]==0){
					ans+=1;
					vic[nx][ny]=1;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
