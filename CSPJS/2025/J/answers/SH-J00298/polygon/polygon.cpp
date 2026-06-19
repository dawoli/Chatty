#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;  
int n;
ll a[5005],ans=0;
void dfs(int x,int f,ll l){
	if(f==n) return;
	for(int i=f+1;i<=n;i++){
		if(x>=3&&l>a[i]){
			ans=(ans+1)%mod;
		}
		dfs(x+1,i,l+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		unsigned ll n1=1;
		for(int i=3;i<=n;i++){
			n1=(n1*i)%mod;
		}
		for(int i=3;i<=n;i++){
			n1=(n1/i)%mod; 
			ans=(ans+n1)%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
