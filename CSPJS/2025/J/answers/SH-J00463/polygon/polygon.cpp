#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int mod=998244353;
int n,cnt;
int a[N];
bool flag=true;
void dfs(int idx,int vis,int sum,int maxn,bool b){
	if(vis>=3 && b){
		cnt++;
		cnt%=mod;
	}
	if(idx==n+1) return ;
	if(sum>a[idx]){
		dfs(idx+1,vis+1,sum+a[idx],max(maxn,a[idx]),true);
	} else {
		dfs(idx+1,vis+1,sum+a[idx],max(maxn,a[idx]),false);
	}
	dfs(idx+1,vis,sum,maxn,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	for(int i=3;i<=n;i++){
		long long aa=1;
		for(int aaa=n,j=i;j>=1;j--,aaa--){
			aa=aa/j*(aaa%mod)*mod;
		}
		cnt+=aa;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0,true);
	cout<<cnt;
	return 0; 
}
