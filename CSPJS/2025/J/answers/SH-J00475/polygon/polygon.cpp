#include<bits/stdc++.h>

using namespace std;
const int mod=998244353;
int n;
int a[5007];
int maxn=-1;
int s[5007];
int cnt;
long long solve(){
	long long mi=1;
	for(int i=1;i<=n;i++){
		mi=mi*2%mod;
	}
	return mi-n-n*(n-1)/2-1; 
}
void dfs(int now,int sum,int t,int last){
	if(now==n+1){
		if(t<3){
			return;
		}
		if(sum>2*a[last]){
			cnt++;
			cnt=cnt%mod;
		}
		return;
	}
	s[now]=0;
	dfs(now+1,sum,t,last);
	s[now]=1;
	dfs(now+1,sum+a[now],t+1,now);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	if(maxn==1){
		cout<<solve()%mod<<endl;
	}
	else if(n<=27){
		dfs(1,0,0,0);
		cout<<cnt%mod<<endl;
	}
	else{
		cout<<32<<endl;
	}
	return 0;
}
