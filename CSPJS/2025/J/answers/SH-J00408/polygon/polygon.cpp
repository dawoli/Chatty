#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod =  998244353;
const int N = 5005;
int n,m,t,ans,a[N],s[N];

int dfs(int id,int sum,int k){		//当前下标，目前和，目标值
	int res = 0;
	if(sum > k) res++;
	for(int i=1;i<id;i++){
		res += dfs(i,sum+a[i],k);
	}	
	return res%mod;
	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i] = s[i-1] + a[i];
	}
	sort(a+n,a+1+n);
	
	for(int i=1;i<=n;i++){			//封顶元素 
		if(s[i-1] <= a[i]) continue;
		ans += dfs(i,0,a[i])%mod;
		ans %= mod;
	}
	
	cout<<ans;
	return 0;
}

