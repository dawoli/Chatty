#include<bits/stdc++.h>
using namespace std;
int n,a[30],ans;
bool vis[30];
int pow(long long a,long long b,long long p){
	long long ans=1;
	while(b>0){
		if(b&1==1) ans=(long long)ans*a%p;
		a=(long long)a*a;
		b>>=1;
	}
	return ans%p;
}
void dfs(int now,int maxi,int sum,int all){
	if(now==n+1){
		if(sum>=3 && all>maxi*2) ans++;
		return ;
	}
	else{
		vis[now]=1;
		dfs(now+1,max(maxi,a[now]),sum+1,all+a[now]);
		vis[now]=0;
		dfs(now+1,maxi,sum,all);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
	    cout<<ans%998244353;
	}
    else{
    	int ll=(long long)pow(2,n,998244353)-n*(n-1)-n;
    	cout<<ll;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
