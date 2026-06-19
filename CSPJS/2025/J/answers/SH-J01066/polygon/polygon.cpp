#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],ans=0;
void dfs(long long x,long long num,long long maxx,long long cnt){
	if(cnt==n&&num<=maxx*2)return;
	if(cnt>=3&&num>maxx*2){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<n;i++){
		dfs(i,num+a[i],max(maxx,a[i]),cnt+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		dfs(i,a[i],a[i],1);
	}
	cout<<ans;
	return 0;
}
