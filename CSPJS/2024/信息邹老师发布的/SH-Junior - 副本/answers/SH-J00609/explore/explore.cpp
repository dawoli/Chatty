#include<bits/stdc++.h>
using namespace std;
const int N=1009;
bool cango[N][N],vst[N][N];
int n,m,k,x0,y0,d0;
void solve(){
	cin>>n>>m>>k>>x0>>y0>>d0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			if(ch=='.')cango[i][j]=1;
			else cango[i][j]=0;
		}
	}
	int cnt=1;
	vst[x0][y0]=1;
	for(int i=1;i<=k;i++){
		int nx=x0,ny=y0;
		if(d0==0)ny++;
		else if(d0==1)nx++;
		else if(d0==2)ny--;
		else nx--;
		if(nx<1||nx>n||ny<1||ny>m||!cango[nx][ny])d0=(d0+1)%4;
		else{
			x0=nx,y0=ny;
			if(!vst[nx][ny]){
				cnt++;
				vst[nx][ny]=1;
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cango[i][j]=0;
			vst[i][j]=0;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)solve();
	return 0;
}
