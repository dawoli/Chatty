#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5014],res;
void dfs(int step,int sum,int maxn,int cnt){
	if(step==n){
		if(sum>2*maxn && cnt>=3)res=(res+1)%998244353;
		return;
	}
	if(cnt+n-step+1<3)return;
	dfs(step+1,sum+a[step+1],max(maxn,a[step+1]),cnt+1);
	dfs(step+1,sum,maxn,cnt);
}
int f(int a,int b){
	int ans=a,k=2;
	for(int i=a-1;i>a-b;i--){
		ans=ans*i/(k++)%998244353;
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>20){
		for(int i=3;i<=n;i++){
			res+=f(n,i)%998244353;
		}
	}
	else{
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1,a[1],a[1],1);
		dfs(1,0,0,0);
		cout<<res;
	}
} 
