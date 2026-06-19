#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void dfs(int m,int t,int sum){
	if(m==t-1)    return;
	if(sum>a[m]&&m==t){
		ans++;
	} 
	if(m>t)    dfs(m,t+1,sum+a[t]);
	dfs(m,t+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>=100){
		for(int i=3;i<=n;i++){
			long long t=1;
			for(int j=n;j>=n-i+1;j--){
				t*=j;
				t/=(n-j+1);
				t%=998244353;
			}
			ans+=t;
			ans%=998224353;
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		dfs(i,0,0);
		if(ans>998244353)    ans%=998244353;
	}
	cout<<ans;
	return 0;
}
