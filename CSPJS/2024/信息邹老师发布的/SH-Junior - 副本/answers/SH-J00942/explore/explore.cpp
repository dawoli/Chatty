#include<iostream>
using namespace std;
const int MAXN=1e3+5;
int n,m,k;
int nowx,nowy,nowd;
int ne[4][2]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
bool mp[MAXN][MAXN],book[MAXN][MAXN];
string s;
int ans;
void solve(){
	cin>>n>>m>>k;
	cin>>nowx>>nowy>>nowd;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='x'){
				mp[i][j+1]=true;
			}else{
				mp[i][j+1]=false;
			}
			book[i][j+1]=false;
		}
	}
	int nex,ney;
	book[nowx][nowy]=true;
	ans=1;
	while(k--){
		nex=nowx+ne[nowd][0];
		ney=nowy+ne[nowd][1];
		if(nex<1||nex>n||ney<1||ney>m||mp[nex][ney]){
			nowd=(nowd+1)%4;
		}else{
			nowx=nex;
			nowy=ney;
			if(!book[nowx][nowy]){
				ans++;
				book[nowx][nowy]=true;
			}
//			printf("%d %d %d %d %d\n",nowx,nowy,nowd,mp[nowy][nowy],book[nowx][nowy]);
		}
//		printf("%d %d %d\n",nowx,nowy,nowd);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
