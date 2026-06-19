#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
int arr[5005];
void dfs(int i,int tot,int maxn){	
	if(i>n){
		if(tot>maxn*2){
			cnt++;
		}
		return;
	}
	dfs(i+1,tot,maxn);
	dfs(i+1,tot+arr[i],max(maxn,arr[i]));
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1,0,0);
	cout<<cnt%998244353;
	return 0;
}

