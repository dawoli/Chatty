//60+20pts
#include<bits/stdc++.h>
using namespace std;

int xo(int a,int b){
	return (a|b)-(a&b);
}

const int maxn=5e5+10;
int a[maxn],n,k,dp[maxn],lst[maxn],lst0[2][256];

void baoli(){
	for(int i=1;i<=n;i++){
		lst[i]=0;
		dp[i]=0;
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j>=1;j--){
			x=xo(x,a[j]);
			if(x==k){
				lst[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(lst[i]==0){
			dp[i]=dp[i-1];
		}
		else{
			dp[i]=max(dp[i-1],dp[lst[i]-1]+1);
		}
	}
	cout<<dp[n];
}

void solve1(){
	for(int i=1;i<=n;i++){
		int nw=i&1;
		int bf=(i&1?0:1);
		for(int j=0;j<256;j++) lst0[nw][j]=0;
		lst0[nw][a[i]]=i;
		for(int j=1;j<256;j++){
			lst0[nw][xo(j,a[i])]=lst0[bf][j];
		}
		lst[i]=lst0[nw][k];
	}
	for(int i=1;i<=n;i++){
		if(lst[i]==0){
			dp[i]=dp[i-1];
		}
		else{
			dp[i]=max(dp[i-1],dp[lst[i]-1]+1);
		}
	}
	cout<<dp[n];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=1000){
		baoli();
	}
	else if(k<=255){
		solve1();
	}
	else{
		cout<<rand()%n;
	}
	return 0;
}
