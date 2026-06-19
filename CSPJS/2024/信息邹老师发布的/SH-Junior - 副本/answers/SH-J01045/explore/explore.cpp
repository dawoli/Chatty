#include<bits/stdc++.h>
using namespace std;
const int N=1009;
char f[N][N];
int	T,n,m,k,x,y,d,cnt,t;
bool q[N][N][4],vis[N][N];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
bool finder(){
	if (x+fx[d]>=1 and x+fx[d]<=n and y+fy[d]>=1 and y+fy[d]<=m and f[x+fx[d]][y+fy[d]]=='.') return 1;
	return 0;
}
void cir(){
	while(k>0 and t>0){
		if (finder()){
			x=x+fx[d];
			y=y+fy[d];
			if (q[x][y][d]==1){
				t=0;
				break;
			}
			else{
				q[x][y][d]=1;
				if (vis[x][y]==0){
					cnt++;
					vis[x][y]=1;
				}			
			}
			k--;
		}
		else{
			d=(d+1)%4;
			if (q[x][y][d]==1){
				t=0;
				break;
			}
			else{
				q[x][y][d]=1;
			}
			k--;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++){
		t=1,cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int j=1;j<=n;j++){
			for (int l=1;l<=m;l++){
				cin>>f[j][l];
				for (int r=0;r<=3;r++) q[j][l][r]=0;
				vis[j][l]=0;
			}
		}
		vis[x][y]=1;
		q[x][y][d]=0; 
		cir();	
	}
	return 0;
}
