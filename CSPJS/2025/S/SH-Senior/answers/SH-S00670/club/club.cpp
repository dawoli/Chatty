#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans[10];
int offset[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
int a00[100020][5];
int solve(int n){
	/*cout<<"============\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
		cout<<a00[i][j]<<' ';}
		
		cout<<'\n';
	}
	cout<<"============\n";*/
	int manyi[n+2][n+2][n+2];//各有若干人时的满意度 按顺序加入
	memset(manyi,0,sizeof(manyi)); 
	for(int i=0;i<n;i++){//人数递进 
		for(int a=0;a<=i;a++)for(int b=0;b<=i-a;b++){
			
			int c = i-a-b;//遍历分配情况
			if(manyi[a][b][c]<0)continue;
			//cout<<a<<' '<<b<<' '<<c<<'\n';
			//放入第i+1人  index=i
			int current = manyi[a][b][c];
			for(int ofs=0;ofs<3;ofs++){
				//cout<<a+offset[ofs][0]<<' '<<b+offset[ofs][1]<<' '<<c+offset[ofs][2]<<"->"<<manyi[a+offset[ofs][0]][b+offset[ofs][1]][c+offset[ofs][2]];
				if(a+offset[ofs][0]>n/2 || b+offset[ofs][1]>n/2 || c+offset[ofs][2]>n/2)manyi[a+offset[ofs][0]][b+offset[ofs][1]][c+offset[ofs][2]]=-1;
				else manyi[a+offset[ofs][0]][b+offset[ofs][1]][c+offset[ofs][2]] = max(manyi[a+offset[ofs][0]][b+offset[ofs][1]][c+offset[ofs][2]],current+a00[i][ofs]);
				//cout<<"->"<<manyi[a+offset[ofs][0]][b+offset[ofs][1]][c+offset[ofs][2]]<<'\n';
			}
		}
	}
	//cout<<"===\n";
	int rt = 0;
	for(int a=0;a<=n;a++)for(int b=0;b<=n-a;b++){
		
		int c = n-a-b;
		//cout<<a<<' '<<b<<' '<<c<<'\n';
		rt = max(rt,manyi[a][b][c]);
	}
	return rt;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ix=0;ix<t;ix++){
		cin>>n;
		for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a00[i][j];
		ans[ix]=solve(n);
	}
	for(int ix=0;ix<t;ix++)cout<<ans[ix]<<'\n';
	return 0;
}
