#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char s[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;++i){
		ans=0;
		memset(s,0,sizeof(s));
		cin>>n>>m>>k>>x>>y>>d;
		for(int j=1;j<=n;++j){
			for(int l=1;l<=m;++l){
				cin>>s[j][l];
			}
		}
		for(int j=1;j<=k+1;++j){
			if(s[x][y]=='.') ++ans;
			s[x][y]='0';
//			cout<<x<<" "<<y<<" "<<d<<" "<<ans<<endl;
			if(d==0&&(s[x][y+1]=='.'||s[x][y+1]=='0')){
				y++;
			}
			else if(d==1&&(s[x+1][y]=='.'||s[x+1][y]=='0')){
				x++;
			}
			else if(d==2&&(s[x][y-1]=='.'||s[x][y-1]=='0')){
				y--;
			}
			else if(d==3&&(s[x-1][y]=='.'||s[x-1][y]=='0')){
				x--;
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
