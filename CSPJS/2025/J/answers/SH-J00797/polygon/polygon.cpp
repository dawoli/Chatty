#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5,mod=998244353;
int n,m,a[maxn],cnt=0;
int dfs(int l,int x,int s){
	ll ans=0;
	if(s>2*a[l]&&s>a[n-1]){
//		cout<<'a'<<' '<<x<<' '<<a[l+1]<<' '<<int(pow(2,n-l-1))%mod<<endl;
		return int(pow(2,n-l-1))%mod;
	}
	
	else for(int i=l+1;i<n;i++){
//		cout<<x<<' '<<a[i]<<endl;
		ans+=dfs(i,x+1,s+a[i])%mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	cout<<dfs(-1,1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
