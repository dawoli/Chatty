#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T;
string map1[N];
bool vst[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		for(int j=1;j<N;j++)for(int k=1;k<N;k++)vst[j][k]=0;
		int n,m,k,x,y,d,cnt=1;
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;j++){
			string s;
			cin>>s;
			s=' '+s;
			map1[j]=s;
		}
		vst[x][y]=1;
		for(int j=1;j<=k;j++){
			int x1=x,y1=y;
			bool move=false;
			if(d==0)y1++;
			if(d==1)x1++;
			if(d==2)y1--;
			if(d==3)x1--;
			if(1<=x1<=n&&1<=y1<=m)
				if(map1[x1][y1]=='.')
					move=true;
			if(move){
				x=x1;y=y1;
				if(!vst[x][y])cnt++;
				vst[x][y]=1;
				// cout<<"Move to ("<<x<<","<<y<<")"<<endl;
			}
			else d=(d+1)%4;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
