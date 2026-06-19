#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],vis[N];
int dp[N][N];
int n;
int ans;
void dfs(int k,int x,int cnt,int sum,int mx){ //选到第几个、要选几个、已经选了几个、目前总和、目前最大值 
	if(cnt==x){
		if(sum>2*mx){
			ans++;
		}
		return;
	}
	if(k>n){
		return;
	}
	vis[k]=1;
	dfs(k+1,x,cnt+1,sum+a[k],max(a[k],mx));
	vis[k]=0;
	dfs(k+1,x,cnt,sum,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}//输入木棍 
	
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(1,i,0,0,0);
	}
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
