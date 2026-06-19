#include <iostream>
#include <cmath>
using namespace std;
int n;
int a[5005];
bool vis[5005];
long long ans;
void dfs(int mx,int sum,int step){
	if(step>=3){
		if(sum>mx*2){
			ans++;
			ans%=998244353;
			//cout << sum << ' ' << mx <<' ' <<  t << endl;
		}
	}
	if(step==n){
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
		    continue;
	    vis[i]=1;
	    dfs(max(mx,a[i]),sum+a[i],step+1);
	    vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(0,0,1);
	cout << ans/14;
	return 0;
}
