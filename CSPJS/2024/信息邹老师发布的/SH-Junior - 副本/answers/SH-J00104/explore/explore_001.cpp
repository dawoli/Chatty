#include<iostream>
#include<cstring>
using namespace std;
int T;
int vis[1005][1005]={};
pair<int,int> nxt(int x,int y,int d){
	pair<int,int> pr;
	if(d==0){
		y++;
	}else if(d==1){
		x++;
	}else if(d==2){
		y--;
	}else{
		x--;
	}
	pr.first=x;
	pr.second=y;
	return pr;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		int n,m,k,x,y,d,cnt=1;
		memset(vis,0,sizeof(vis));
		string str[1005]={};
		cin>>n>>m>>k>>x>>y>>d;
		x--;y--;
		for(int i=0;i<n;i++){
			cin>>str[i];
		}
		for(int i=0;i<k;i++){
			int nx=nxt(x,y,d).first;
			int ny=nxt(x,y,d).second;
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&str[nx][ny]=='.'){
				x=nx;
				y=ny;
				if(vis[x][y]==0){
					cnt++;
					vis[x][y]=1;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
