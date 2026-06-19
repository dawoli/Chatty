#include<bits\stdc++.h>
using namespace std;
int n,a[5050],ans;
const int mod=998244353;
void dfs(int step,int sum,int maxn,int tol){
	if(step==n+1)return ;
	if(tol==0){
		if(sum>2*maxn)ans++;
		return ;
	}
	dfs(step+1,sum+a[step],a[step],tol-1);
	dfs(step+1,sum,maxn,tol);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*max(max(a[1],a[2]),a[3]))cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag){
		int x=n-2;
		cout<<(x+1)*x/2%mod;
		return 0;
	} 
	for(int i=3;i<=n;i++)dfs(1,0,0,i); 
	cout<<ans%mod;
	return 0;
}
