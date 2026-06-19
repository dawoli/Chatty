#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long ans;
char jungle[1005][1005];
bool visp[1005][1005],visd[1005][1005][4];
void dfs(int a, int b, int c){
	if(k==0)return;
	else k--;
	if(!visd[a][b][c]){
		visd[a][b][c]=1;
	}
	else return;
	int na,nb;
	na=a+direction[c][0];
	nb=b+direction[c][1];
	if((1<=na&&na<=n)&&(1<=nb&&nb<=m)&&jungle[na][nb]=='.'){
		if(!visp[na][nb]){
			visp[na][nb]=1;
			ans++;
		}
		dfs(na,nb,c);
		return;
	}
	c=(c+1)%4;
	dfs(a,b,c);
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=1;
		memset(jungle,0,sizeof(jungle));
		memset(visp,0,sizeof(visp));
		memset(visd,0,sizeof(visd));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>jungle[i][j];
			}
		}
		visp[x][y]=1;
		dfs(x,y,d);
		cout<<ans<<endl;
	}
	return 0;
}

