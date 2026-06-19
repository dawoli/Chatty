#include <iostream>
#include<algorithm>
using namespace std;
int a[5005];
int n;
long long cnt;
void dfs(int sum, int pos, int maxm, int n_side){
	if(pos==n+1){
		if(n_side>=3 && sum>2*maxm){
			cnt++;
		}
		return; 
	}
	int new_maxm = max(maxm,a[pos]);
	dfs(sum+a[pos],pos+1,new_maxm,n_side+1);
	dfs(sum,pos+1,maxm,n_side);
	return;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	long long mod = 998244353;
	if(flag){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans = ans<<1;
			ans%=mod;
		}
		ans-=(n+1+(n*(n-1)/2)); 
		cout<<ans<<endl;
		return 0;
	}
	dfs(0,1,0,0);

	cnt%=mod;
	cout<<cnt<<endl;
	return 0; 
}
