#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt[5005],ans;
void dfs(int x,int maxn,int sum,int f){
	if(x>n){
		return ;
	}
	if(sum>maxn*2&&f)ans++;
	x++;
	dfs(x,max(maxn,a[x]),sum+a[x],1);
	dfs(x,maxn,sum,0);  
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans;
}
