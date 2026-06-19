#include <bits/stdc++.h>

using namespace std;
int T;
int n,m,k;
char mapRobot[1001][1001];
int x,y,d,tx,ty;
int Addx[4]={0,1,0,-1};
int Addy[4]={1,0,-1,0};
int ans=1;
bool CheckWent[1001][1001];

bool Checkcango(){
	if(tx>=1 && tx<=n && ty>=1 && ty<=m){
		if(mapRobot[tx][ty] == '.'){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>T;
	for(int p=1;p<=T;p++){
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=m;j++){
				scanf(" %c",&mapRobot[i][j]);
				CheckWent[i][j]=true;
			}
		}
		
		ans=1;
		CheckWent[x][y]=false;
		for(register int i=1;i<=k;i++){
			tx=x+Addx[d];
			ty=y+Addy[d];
			if(Checkcango()){
				x=tx;
				y=ty;
				if(CheckWent[x][y]){
					ans++;
					CheckWent[x][y]=false;
				}
			} else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
