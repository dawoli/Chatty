#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
const int N=1e5+7;
int t,n,k,qt;
int l[N],s[N*2],r[N],cnt;
//int dp[207][107][107];
int dis[107][N],a,b,mx;
int vis[17][1007][2007];
struct zhuang{
	int a,b,c;
};
queue<zhuang> q;
void bfs(){
	memset(dis,0,sizeof dis);
	dis[0][1]=1;
	q.push((zhuang){0,0,1});
	while(!q.empty()){
		zhuang x=q.front();q.pop();
//		if(x.a>=55)cout<<x.a<<" "<<x.b<<" "<<x.c<<endl;
		if(x.a>100)continue;
		dis[x.a][s[x.c]]=1;
		if(vis[x.a][x.b][x.c])
			continue;
		vis[x.a][x.b][x.c]=1;
		for(int i=1;i<=n;i++)
			if(i!=x.b){
				int sheng=0;
				for(int j=l[i];j<=r[i];j++){
					if(sheng)
						q.push((zhuang){x.a+1,i,j}),--sheng;
					if(s[j]==s[x.c])
						sheng=k-1;
				}
			}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>qt;
		cnt=mx=0;
		for(int i=1,li;i<=n;i++){
			cin>>li,l[i]=r[i-1]+1;
			r[i]=r[i-1]+li;
			while(li--)
				cin>>s[++cnt],mx=max(mx,s[cnt]);
		}
		bfs();
		while(qt--)
			cin>>a>>b,
			cout<<dis[a][b]<<endl;
	}
} 
//dp[i][j][k]=dp[i-1][rj][rk];
//

