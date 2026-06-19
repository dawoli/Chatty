#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
#define ll long long
int g[N][N];
int n,m,k; 
int x,y,d;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(g,0,sizeof g);
		cin>>n>>m>>k>>x>>y>>d;
		string str;
		for(int i=1;i<=n;i++){
			cin>>str;
			for(int j=1;j<=m;j++)
				if(str[j-1]=='.')g[i][j]=1;
		}
		ll cnt=1;g[x][y]=2;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(g[x][y+1])y=y+1;
				else d=(d+1)%4;
			}
			else if(d==1){
				if(g[x+1][y])x=x+1;
				else d=(d+1)%4;
			}
			else if(d==2){
				if(g[x][y-1])y=y-1;
				else d=(d+1)%4;
			}
			else if(d==3){
				if(g[x-1][y])x=x-1;
				else d=(d+1)%4; 
			}
			if(g[x][y]==1){
				g[x][y]=2;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
