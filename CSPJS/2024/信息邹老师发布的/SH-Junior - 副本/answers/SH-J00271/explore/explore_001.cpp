#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,step,ans;
string line;
int map1[1050][1050];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int a=0;a<T;a++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1;
		step=0;
		//建图 
		for(int i=1;i<=n;i++){
			cin>>line;
//			cout<<line<<endl;
			for(int j=1;j<=m;j++){
				int a=int(line[j-1]);
//				cout<<a<<" ";
				if(a==120)map1[i][j]=1;
				else map1[i][j]=0;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)cout<<map1[i][j];
//			cout<<endl;
//		}
		//运动
		ans=1;
		step=0;
		map1[x][y]=2;
		while(step<k){
			step++;
			int a1,b1;
			//判断方向 
			if(d==0){
				a1=x;
				b1=y+1;
			}
			else if(d==1){
				a1=x+1;
				b1=y;
			}
			else if(d==2){
				a1=x;
				b1=y-1;
			}
			else if(d==3){
				a1=x-1;
				b1=y;
			}
			//判断能否行动 
			if(1<=a1&&a1<=n&&1<=b1&&b1<=m&&map1[a1][b1]!=1){
				x=a1;
				y=b1;
				if(map1[x][y]!=2){
					map1[x][y]=2;
					ans++;
				}
			}
			else{
				d=(d+1)%4;
			}
//			cout<<x<<" "<<y<<" "<<d<<" "<<ans<<endl;
		}
		cout<<ans<<endl; 
	}
	return 0;
}
