#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},dir,t,n,m,k,mp[1010][1010],x,y;
set<pair<int,int> > s;
char st[1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&dir);
		s.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",st);
			for(int j=0;j<m;j++)
				if(st[j]=='x')
					mp[i][j+1]=1;
				else
					mp[i][j+1]=0;
		}
		s.insert(make_pair(x,y));
		while(k--){
			int xx=x+dx[dir],yy=y+dy[dir];
			if(xx&&xx<=n&&yy&&yy<=m&&!mp[xx][yy]){
				x=xx;
				y=yy;
				s.insert(make_pair(x,y));
			}
			else
				dir=(dir+1)%4;
		}
		cout<<s.size()<<endl;
	}
	return 0;
}
