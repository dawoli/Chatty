#include<bits/stdc++.h>
using namespace std;
char ju[1001][1001];

bool ifin(int x,int y,int n,int m){
	if(x<=0||y<=0||x>n||y>m||ju[x][y]=='x')
		return 0;
	return 1;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.ans","w",stdout);
	int t;
	cin>>t;
	for(int a=1;a<=t;++a){
		bool close[1001][1001];
		memset(close,0,sizeof(close));
		
		int n,m,k,ans=1;
		cin>>n>>m>>k;
		
		int x,y,d;
		cin>>x>>y>>d;
		close[x][y]=1;
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>ju[i][j];
		
		for(int i=0;i<k;++i){
			int x1=x,y1=y;
			if(d==0) ++y1;
			if(d==1) ++x1;
			if(d==2) --y1;
			if(d==3) --x1;
			if(ifin(x1,y1,n,m)){
				x=x1;y=y1;
				if(!close[x][y]){
					++ans;
					close[x][y]=1;
				}
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
