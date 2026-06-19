#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int T,ans,n,m,k,x,y,d;
char tu[N][N];
bool wh[N][N];
void calculate(int x,int y,int d,int k){
	if(wh[x][y]==0){
		ans++;
		wh[x][y]=1;
	}
	if(k==0) return;
	while(true&&k>0){
		if(d==0&&tu[x][y+1]!='x'&&y+1<=m){
			k--;
			calculate(x,y+1,d,k);
			break;
		}
		if(d==1&&tu[x+1][y]!='x'&&x+1<=n){
			k--;
			calculate(x+1,y,d,k);
			break;
		}
		if(d==2&&tu[x][y-1]!='x'&&y-1>0){
			k--;
			calculate(x,y-1,d,k);
			break;
		}
		if(d==3&&tu[x-1][y]!='x'&&x-1>0){
			k--;
			calculate(x-1,y,d,k);
			break;
		}
		d=(d+1)%4;
		k--;
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>tu[i][j];
				wh[i][j]=0;
			}
		ans=0;
		calculate(x,y,d,k);
		cout<<ans<<endl;
	}
	return 0;
}
