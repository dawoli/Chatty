#include<bits/stdc++.h>
using namespace std;

int t,n,m,k,sx,sy,sd,cnt;
int a[1005][1005];
bool vis[1005][1005];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(vis,false,sizeof(vis));
		cnt=0;
		cin>>n>>m>>k;
		cin>>sx>>sy>>sd;
		vis[sx][sy]=true;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++){
				char c=s[j];
				if(c=='.')a[i][j+1]=1;
				if(c=='x')a[i][j+1]=-1;
			}
		}
		for(int i=1;i<=k;i++){
			
			if(sd==0){
				if(a[sx][sy+1]==1){
					sy++;
					vis[sx][sy]=true;
				}
				else sd=(sd+1)%4;
			}
			else if(sd==1){
				if(a[sx+1][sy]==1){
					sx++;
					vis[sx][sy]=true;
				}
				else sd=(sd+1)%4;
			}
			else if(sd==2){
				if(a[sx][sy-1]==1){
					sy--;
					vis[sx][sy]=true;
				}
				else sd=(sd+1)%4;
			}
			else if(sd==3){
				if(a[sx-1][sy]==1){
					sx--;
					vis[sx][sy]=true;
				}
				else sd=(sd+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]==true)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
