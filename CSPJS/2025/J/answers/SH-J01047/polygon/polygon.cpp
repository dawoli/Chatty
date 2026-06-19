#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=1e6+10;
const int mod=998244353;

int a[N];
int n;
int ans=0;

void dfs(int now,int maxx,int sum,int num){
	if(now>n) return;
	if(num>=3&&sum>2*maxx) ans++;
	ans%=mod;
	dfs(now+1,max(maxx,a[now]),sum+a[now],num+1);
	dfs(now+1,maxx,sum,num);
}

int c(int a,int b){
	int ans=1;
	for(int i=a;i>=a-b+1;i--){
		ans*=i;
		ans%=mod;
	}
	for(int i=1;i<=b;i++){
		ans/=i;
		ans%=mod;
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(n==3){
		int maxx1=0;
		int sum1=0;
		for(int i=1;i<=n;i++){
			maxx1=max(maxx1,a[i]);
			sum1+=a[i];
		}
		if(sum1>2*maxx1) cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		dfs(1,0,0,0);
		cout<<(ans%mod)<<endl;
	}
	else{
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans%=mod;
		}
		cout<<ans<<endl;
	}
}
