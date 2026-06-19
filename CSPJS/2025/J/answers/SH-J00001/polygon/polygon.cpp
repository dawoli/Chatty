#include<bits/stdc++.h>
using namespace std;
const int MOD= 998244353;
long long n,a[5005],ans;
void dfs(long long mx,long long cnt,long long x){
	if(x==0){
		if(cnt>mx){
			ans++;
			ans%=MOD;
		}return;
	}dfs(mx,cnt+a[x],x-1);
	dfs(mx,cnt,x-1);
}
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}if(flag){
		cout<<pow(2,n)-(n*(n-1)/2+n+1);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		dfs(a[i],0,i-1);
	}cout<<ans;
	return 0;
}

