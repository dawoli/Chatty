#include<bits/stdc++.h>
using namespace std;
int n;int k;
int x[1010];
int minu(int x,int y){//x=y^z 求z O(log2(x))
	int d=max(ceil(log2(x)),ceil(log2(y)));
	int ret=0;
	for(int i=0;i<=d;i++){
		bool di=y&int(pow(2,i));
		if(x&(int(pow(2,i))))
			ret+=!di*int(pow(2,i));
		else ret+=di*int(pow(2,i));
	}
	return ret;	
}
int l[1010];//dp[i]表示以i结尾的最大j，使得[j,i]异或和为k 
int dp[1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool p13=false;int cnt1=0;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		if(a!=0 && a!=1) p13=false;
		else cnt1++;
		x[i]=x[i-1]^a;
	}
	if(p13){
		cout<<cnt1<<endl;
		return 0;
	}
	memset(l,-1,sizeof(l));
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;j--)
			if(minu(x[i],x[j-1])==k){
				l[i]=max(l[i],j);
				break;
			}
	int ans=0;
	dp[1]=(x[1]==k ? 1 : 0);
	for(int i=2;i<=n;i++){
		for(int j=0;j<l[i];j++)
			dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
