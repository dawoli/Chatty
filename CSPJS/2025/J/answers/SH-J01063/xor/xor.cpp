#include<bits/stdc++.h>
using namespace std;
int a[500010];
int jishu[5000010];
int n,k;
long long xorh[500010];
int nodesum=0;
vector <int> dp(5000010);
int nowr=0;
struct node{
	int l,r;
}lr[5000010];
bool cmp1(node x,node y){
	return x.r<y.r;
}
bool cmp2(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(xorh,0,sizeof(xorh));
	memset(jishu,-1,sizeof(jishu));
	jishu[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xorh[i]=xorh[i-1]^a[i];
		if(jishu[xorh[i]^k]!=-1){
			if(jishu[xorh[i]^k]<i){
				nodesum++;
				lr[nodesum].l=jishu[xorh[i]^k]+1;
				lr[nodesum].r=i;
			}
		}
		jishu[xorh[i]]=i;
	}
	if(nodesum==0){
		cout<<0;
		return 0;
	}
	sort(lr+1,lr+1+nodesum,cmp1);
	sort(lr+1,lr+1+nodesum,cmp2);
	for(int i=1;i<=nodesum;i++){
		dp[lr[i].r]=max(dp[lr[i].r-1],dp[lr[i].l-1]+1);
		for(int j=lr[i].r;j<=n;j++){
			dp[j]=max(dp[j],dp[j-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
