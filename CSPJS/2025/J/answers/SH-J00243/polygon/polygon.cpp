#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
//前p根木棍选ch根，总长为sumnow，最长为maxnow时
void dfs(int p,int ch,int sumnow,int maxnow){
	if(p==n+1) return ;
	if(sumnow+a[p]>max(maxnow,a[p])*2&&ch+1>=3){
		ans++;
		ans%=998244353;
//		cout<<ch<<" "<<sumnow<<" "<<maxnow<<" "<<endl;
		dfs(p+1,ch+1,sumnow+a[p],max(maxnow,a[p]));
	}
	else{
		dfs(p+1,ch+1,sumnow+a[p],max(maxnow,a[p]));
	}
	dfs(p+1,ch,sumnow,maxnow);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
} 
