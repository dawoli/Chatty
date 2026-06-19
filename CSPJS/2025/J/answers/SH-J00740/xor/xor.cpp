#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxk=(1<<20)+10;
int n,k,a[maxn],dp[maxn],ans,sum[maxn];
int dpm[maxn],top[maxk];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(top,-1,sizeof(top));
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	top[0]=0;dp[0]=0;dpm[0]=0; 
	for(int i=1;i<=n;i++){
		int pre=top[sum[i]^k];
		if(pre!=-1){
			dp[i]=1+dpm[pre];
		}
		top[sum[i]]=i;
		dpm[i]=max(dpm[i-1],dp[i]); 
	}
	cout<<dpm[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
