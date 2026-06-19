#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,a[5005],sum=0;
bool f[5005];
bool check(){
	int maxn=0,sum=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
	}
	if(sum>2*maxn){
		return 1;
	}
	return 0;
}
void dfs(int x,int cnt){
	if(x==n+1){
		if(cnt>=3 and check()){
			sum++;
		}
		return ;
	}
	dfs(x+1,cnt);
	f[x]=1;
	dfs(x+1,cnt+1);
	f[x]=0;
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<sum<<endl;
	return 0;
}
