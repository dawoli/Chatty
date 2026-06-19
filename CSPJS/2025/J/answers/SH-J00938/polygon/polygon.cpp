#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int ls[5009];
//剪枝搜索，当目前之和大于最大值时直接计算排列组合 
bool cmp(int a,int b){
	return a>b;
}
__int128 C(int a,int b){//还是排列组合大佬 
	__int128 ans=1;
	a=min(a,b-a); 
	for(int i=1;i<=a;i++){
		ans=ans*(b-i+1)/i;
	}
	ans=ans%mod;
	return ans;
}
int dfs(int nw,int mx,int cnt){//下一个的下标，最大值，目前和 
	int res=0;
	if(cnt>mx){
		for(int i = 0;i <= n-nw;i ++){
			res+=C(i,n-nw);
			res=res%mod;
		}
		return res;
	}
	if(nw>=n){
		return 0;
	}
	res=dfs(nw+1,mx,cnt+ls[nw]) + dfs(nw+1,mx,cnt);
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>> n;
	for(int i = 0;i < n;i ++){
		cin>>ls[i];
	}
	sort(ls,ls+n,cmp);
	int ans=0;
	if (ls[0]==1)for(int i = 0;i <= n;i ++){ans+=C(i,n);ans=ans%mod; }
	else for(int i = 0;i < n-1;i ++){ans+=dfs(i+1,ls[i],0);ans=ans%mod; }
	cout<<ans; 
	return 0;
}

