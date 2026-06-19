#include<bits/stdc++.h>
using namespace std;
bool vst[1009][1009];
char ma[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	cin>>t;
	for(long long aaa=1;aaa<=t;aaa++){
		memset(vst,0,sizeof(vst));
		long long n,m,k;
		cin>>n>>m>>k;
		long long x,y,d;
		cin>>x>>y>>d;vst[x][y]=1;		
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>ma[i][j];
			}
		}
		for(long long i=1;i<=k;i++){
			long long tx=x,ty=y;
			if(d==0) y++;
			else if(d==1) x++;
			else if(d==2) y--;
			else if(d==3) x--;
			if(x>=1 and x<=n and y>=1 and y<=m and ma[x][y]=='.'){
				vst[x][y]=1;
			}
			else x=tx,y=ty,d=(d+1)%4;
			//cout<<x<<" "<<y<<endl;
		}		
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				if(vst[i][j]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
