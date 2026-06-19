#include<bits/stdc++.h>
using namespace std;
const int N=1009;
bool mp[N][N],vst[N][N];
unsigned long long k,ans;
bool check(int x,int y){
	return 1-mp[x][y];
}
void dfs(int x,int y,int d,int p){
	if(p==k+1)return;
	//cout<<x<<" "<<y<<endl;
	if(!vst[x][y])ans++;
	vst[x][y]=1;
	if(d==0){
		if(check(x,y+1))
			dfs(x,y+1,d,p+1);
		else dfs(x,y,(d+1)%4,p+1);
	}
	else if(d==1){
		if(check(x+1,y))
			dfs(x+1,y,d,p+1);
		else dfs(x,y,(d+1)%4,p+1);
	}
	else if(d==2){
		if(check(x,y-1))
			dfs(x,y-1,d,p+1);
		else dfs(x,y,(d+1)%4,p+1);
	}
	else if(d==3){
		if(check(x-1,y))
			dfs(x-1,y,d,p+1);
		else dfs(x,y,(d+1)%4,p+1);
	}
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long T;
	cin>>T;
	while(T--){
		for(int i=1;i<=1009;i++)
			for(int j=1;j<=1009;j++)vst[i][j]=0;
		int n,m,x,y,d;
		ans=0;
		cin>>n;
		cin>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				if(c=='x') mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
		for(int i=0;i<=n+1;i++)mp[i][0]=mp[i][m+1]=1;
		for(int i=0;i<=m+1;i++)mp[0][i]=mp[n+1][i]=1;
		//for(int i=0;i<=n+1;i++){
		//	for(int j=0;j<=m+1;j++)cout<<mp[i][j]<<" ";
		//	cout<<endl;
		//}
		dfs(x,y,d,0);
		cout<<ans<<endl;
	//	cout<<endl;
	}
	return 0;
} 
