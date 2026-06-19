#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5010,mod=998244353;
int a[N];
long long ans=0;
__int128 p(int n){
	__int128 ans=1;
	for(int i=1;i<=n;i++) ans*=i;
	return ans;
}
__int128 p2(int n,int m){
	__int128 ans=1;
	for(int i=m+1;i<=n;i++) ans*=i;
	return ans;
}
void dfs(int x,int s,int maxs,int cnt){
	if(x>n){
		if(cnt>2&&s>2*maxs) ans++;
		ans%=mod;
		return;
	}
	dfs(x+1,s+a[x],max(maxs,a[x]),cnt+1);
	dfs(x+1,s,maxs,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<500){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else{
		unsigned long long ans=0;
		for(int i=3;i<=n;i++){
//			cout<<p(n)/p(n-i)/p(n)<<"\n";
			ans+=p2(n,n-i)/p(i);
			ans%=mod; 
		}
		cout<<ans;
	}
	return 0;
}

/*
5
1 2 3 4 5
5
2 2 3 8 10

*/
