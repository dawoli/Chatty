#include<bits/stdc++.h>
using namespace std;
const int N=5050,M=998244353;
int n,a[N],ans;
void dfs(int step,int sum,int maxx,int q){
	if(step>=3&&sum>2*maxx)ans=(ans+1)%M;
	if(step==n+1)return;
	for(int i=q;i<=n;i++){
		dfs(step+1,sum+a[i],max(maxx,a[i]),i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag1=0;
	}
	if(flag1)cout<<(n-1)*(n-2)/2;
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
} 
