#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int x,y,d;
int main(){
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		char s[1009][1009]={{}};
		int a[1009][1009]={{}};
		for(int i=1;i<=n;i++){
			string str;
			cin>>str;
			for(int j=1;j<=m;j++){
				s[i][j]=str[j-1];
			}
		}
		a[x][y]=1;
		while(k--){
			if(d==0&&x>=1&&x<=n&&y+1>=1&&y+1<=m&&s[x][y+1]=='.'){
				y+=1;
				if(a[x][y]==0)
					ans++;
				a[x][y]=1;
			}
			else if(d==1&&x+1>=1&&x+1<=n&&y>=1&&y<=m&&s[x+1][y]=='.'){
				x+=1;
				if(a[x][y]==0)
					ans++;
				a[x][y]=1;
			}
			else if(d==2&&x>=1&&x<=n&&y-1>=1&&y-1<=m&&s[x][y-1]=='.'){
				y-=1;
				if(a[x][y]==0)
					ans++;
				a[x][y]=1;
			}
			else if(d==3&&x-1>=1&&x-1<=n&&y>=1&&y<=m&&s[x-1][y]=='.'){
				x-=1;
				if(a[x][y]==0)
					ans++;
				a[x][y]=1;
			}
			else d=(d+1)%4;
			//cout<<x<<" "<<y<<" "<<d<<endl;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}


