#include<bits/stdc++.h>
using namespace std;
char f[1009][1009];
bool vst[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,d;
	cin>>x>>y>>d;
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		cin>>f[i][j];
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
			vst[i][j]=0;
		}
	vst[x][y]=1;
	for(int i=1;i<=k;i++){
		if(d==0){
			if(y+1>m||f[x][y+1]=='x')
			d=(d+1)%4;
			else{
				if(!vst[x][y+1])
				cnt++;
				y++;
			}
			vst[x][y]=1;
		}
		else if(d==1){
			if(x+1>n||f[x+1][y]=='x')
			d=(d+1)%4;
			else{
				if(!vst[x+1][y])
				cnt++;
				x++;
			}
			vst[x][y]=1;
		}
		else if(d==2){
			if(y-1<1||f[x][y-1]=='x')
			d=(d+1)%4;
			else{
				if(!vst[x][y-1])
				cnt++;
				y--;
			}
			vst[x][y]=1;
		}
		else if(d==3){
			if(x-1<1||f[x-1][y]=='x')
			d=(d+1)%4;
			else{
				if(!vst[x-1][y])
				cnt++;
				x--;;
			}
			vst[x][y]=1;
		}
	}
	cout<<cnt<<endl;}
	return 0;
}
