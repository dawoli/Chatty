#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t,n,m,vis[N][N],d,k,sx,sy,ans;
char mp[N][N];
string s;

int check(int x,int y){
	if(x<1 || x>n || y<1 || y>m || mp[x][y]=='x') return 0;
	else return 1;}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ans=0;
		memset(vis,0,sizeof(vis));
		scanf("%d %d %d",&n,&m,&k);
		scanf("%d %d %d",&sx,&sy,&d);
		for(int j=1;j<=n;j++){
			cin>>s;
			for(int b=0;b<m;b++){
				if(s[b]=='x') mp[j][b+1]='x';
				else mp[j][b+1]='.';}
		}
		
			
		vis[sx][sy]++,ans++;
		for(int j=1;j<=k;j++){
			if(d==0) {
				if(check(sx,sy+1)) {
					//cout<<j<<" ";
					sy++;
					vis[sx][sy]++;
					if(vis[sx][sy]==1) ans++;
					
				}
				else d=1;
				continue;
			}
			else if(d==1) {
				if(check(sx+1,sy)) {
					//cout<<1<<" ";
					sx++;
					vis[sx][sy]++;
					if(vis[sx][sy]==1) ans++;
				}
				else d=2;
				continue;
			}
			else if(d==2) {
				
				if(check(sx,sy-1)) {
					//cout<<2<<" ";
					sy--;
					vis[sx][sy]++;
					if(vis[sx][sy]==1) ans++;
				}
				else d=3;
				continue;
			}
			else if(d==3) {
				if(check(sx-1,sy)) {
				//	cout<<3<<" ";
					sx--;
					vis[sx][sy]++;
					if(vis[sx][sy]==1) ans++;
				}
				else d=0;
				continue;
			}
		//cout<<sx<<" "<<sy<<" ";
			}
	printf("%d",ans);	
	}}
