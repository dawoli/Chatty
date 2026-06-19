#include<bits/stdc++.h>
using namespace std;
int t,k,num=0,ans=1,n,m,x,y,d;
char mp[1005][1005];
dfs(int x,int y,int d){
	if(num==k) return ans;
	num++;
	if(d==0&&x>=0&&x<n&&y+1>=0&&y+1<m&&mp[x][y+1]=='.'){
		
		ans++;
		dfs(x,y+1,d);
	}else if(d==1&&x+1>=0&&x+1<n&&y>=0&&y<m&&mp[x+1][y]=='.'){
		
		ans++;
		dfs(x+1,y,d);
	}else if(d==2&&x>=0&&x<n&&y-1>=0&&y-1<m&&mp[x][y-1]=='.'){
		
		ans++;
		dfs(x,y-1,d);
	}else if(d==3&&x-1>=0&&x-1<n&&y>=0&&y<m&&mp[x-1][y]=='.'){
		
		ans++;
		dfs(x-1,y,d);
	}else{
		num++;
		dfs(x,y,(d+1)%4);
	}

}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	cin>>t;
	for(int i=0;i<t;i++){
		int num=0,ans=1;
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>mp[i][j];
			}
		}
		dfs(x,y,d);
		cout<<ans<<endl;
	}
	
	return 0;
}
