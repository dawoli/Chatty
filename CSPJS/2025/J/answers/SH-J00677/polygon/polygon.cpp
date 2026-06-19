#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
const int MOD=998244353;
int n,cnt=0;
int a[MAXN],dp[MAXN][MAXN];//dp[i][j]表示最多选i条边，第j条边为最大边时的多边形数量 
bool vis[MAXN];
int dfs(int target,int a[],int min,int sum,int max,int edge,int maxedge){//计算情况数 
    if(edge>maxedge){
    	return 0;
    }
	if(sum>target&&edge==maxedge){
		cout<<"a";
		return dfs(target,a,min+1,0,max,0,maxedge)+1;
	}
	for(int i=min;i<=max;i++){
		if(!vis[i]){
			vis[i]=1;
		    dfs(target,a,i+1,sum+a[i],max,edge+1,maxedge);
		}
	}
}
int jiecheng(int a,int b){
	int sum=1;
	for(int i=b;i>=a;i--){
		sum*=i;
		sum%=MOD;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2)
	    cout<<0;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a-b<c)
		    cout<<1;
		else
		    cout<<0;
	}
	else{
		long long ans=0;
		for(int i=3;i<=n;i++)
		    ans=(ans+jiecheng(i+1,n))%MOD;
		cout<<ans;
	}
	/*for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			memset(vis,0,sizeof(vis));
			dp[i][j]=dp[i-1][j]+dfs(a[i],a,1,0,i-1,i,j);
			if(dp[i][j-1]>0){
				memset(vis,0,sizeof(vis));
			    dp[i][j]=dp[i][j-1]+dfs(a[i],a,1,0,i-1,0,j);
			    for(int i=1;i<=n;i++)
			        cout<<vis[i]<<" ";
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
		    cout<<dp[i][j]<<" ";
	cout<<ans;*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
