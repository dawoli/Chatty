#include<bits/stdc++.h>
using namespace std;
int dp[500010],pre[500010],n,k,a[500010],rmx=0;
int buc[2100010];
//si ren bang,dou shi huai dongxi!!
//pantu tewu yexinjia dajunfa 

//const int LUOGU=909552;
/*
prob 3 too hard, cant ak

gonna use 60pts method

IAFO maybe

*10:43 got some idea,but not sure

*11:39 the idea is correct! (use bucket)

ren min wan sui!!!!!! 
*/


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	pre[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	buc[k^0]=1;
	rmx=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i],buc[pre[i]]);
		dp[i]=max(dp[i],rmx);
		rmx=max(rmx,dp[i]);
		buc[k^pre[i]]=max(buc[k^pre[i]],dp[i]+1);
	}cout<<dp[n];
	return 0;
}
