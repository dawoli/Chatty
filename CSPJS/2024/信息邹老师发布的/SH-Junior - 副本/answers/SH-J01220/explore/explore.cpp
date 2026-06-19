#include<bits/stdc++.h>
using namespace std;
const int maxn=1500500;
int t,n,m,x,y,d,mapp[1505][1505],used[1505][1505],ans=0;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
long long int k;
char s[1525];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		ans=0;
		memset(used,0,sizeof(used));
		memset(mapp,0,sizeof(mapp));
		for(int j=1;j<=n;j++){
			cin>>s;
		for(int p=0;p<m;p++){
			if(s[p]=='.') mapp[j][p+1]=0;
			if(s[p]=='x') mapp[j][p+1]=1;
		}
		}
		while(k>=0){
			if(used[x][y]==0){
			used[x][y]=1;
			ans++;
			}
			if(mapp[x+dx[d]][y+dy[d]]==0&&(x+dx[d]<=n&&(x+dx[d]>=1&&(y+dy[d]<=m&&y+dy[d]>=1)))) x+=dx[d],y+=dy[d];
			else{
				d=(d+1)%4;
			}
 			k--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
