#include<bits/stdc++.h>
using namespace std;
int test,n,m,k,x,y,d;
string s[1001];
bool b[1001][1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&test);
	for(;test--;){
		memset(b,false,sizeof(b));
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		x--;
		y--;
		for(int i=1;i<=k;i++){
			b[x][y]=true;
			if(d==0){
				if(y+1<m&&s[x][y+1]=='.'){
					y++;
				}
				else{
					d=1;
					continue;
				}
			}
			if(d==1){
				if(x+1<n&&s[x+1][y]=='.'){
					x++;
				}
				else{
					d=2;
					continue;
				}
			}
			if(d==2){
				if(y-1>=0&&s[x][y-1]=='.'){
					y--;
				}
				else{
					d=3;
					continue;
				}
			}
			if(d==3){
				if(x-1>=0&&s[x-1][y]=='.'){
					x--;
				}
				else{
					d=0;
					continue;
				}
			}
		}
		b[x][y]=true;
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(b[i][j]==true){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	printf("%d",clock());
	return 0;
}
