#include<bits/stdc++.h>
using namespace std;
bool mp[1005][1005]={false};
bool vis[1005][1005]={false};
int T,n,m,t,asw,x,y,d;
int dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char c;
string s;
int main(){
	freopen("explore5.in","r",stdin);
	freopen("explore5.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++){
		asw=0;
		cin>>n>>m>>t;
		cin>>x>>y>>d;
		for(int a=1;a<=n;a++){
			cin>>s;
			for(int b=1;b<=m;b++){
				c=s[b-1];
				if(c=='.') mp[a][b]=true;
				else mp[a][b]=false;
			}
		}
		vis[x][y]=true;
		asw++;
		while(t>0){
			while(mp[x+dxy[d][0]][y+dxy[d][1]]&&t>0){
				x+=dxy[d][0];y+=dxy[d][1];t--;
				if(!vis[x][y]){
					vis[x][y]=true;
					asw++;
				}
			}
			if(!mp[x+dxy[d][0]][y+dxy[d][1]]&&t>0){
				d=(d+1)%4;
				t--;
			}
		}
		cout<<asw<<endl;
		for(int a=1;a<=n;a++){
			for(int b=1;b<=m;b++){
				mp[a][b]=false;
				vis[a][b]=false;
			}
		}
	}
	return 0;
}
