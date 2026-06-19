#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5005];
ll mod=998244353;
ll ans;
bool vis[5005];
void dfs(int t,int l,ll sum,int num){
	if(t>n) return;
	for(int i=l;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(t>=3&&sum>a[i]){
				ans++;
				ans%=mod;
			}
			dfs(t+1,i,sum+a[i],a[i]);
			vis[i]=0;
		}
	}

}
bool is1=1;
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) is1=0;
	}
	sort(a+1,a+n+1);
	dfs(1,1,0,0);
	cout<<ans<<endl;
	return 0;
} 
