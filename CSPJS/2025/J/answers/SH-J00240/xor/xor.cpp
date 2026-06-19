#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e3+10;
int a[N];
 
int ksm(int a,int b){
	int	ans=a;
	while(b){
		if(b&1){
			ans=ans*a*1ll;
			a=1ll*a*a; 
		}
		b>>=1;
	}
	return ans;
}

int xorf(int a,int b){
	int ans=0;
	int cur=0;
	while(a>0 || b>0){
		if((a&1==1 && b&1==0) ||(a&1==0 && b&1==1)) ans+=ksm(2,cur);
		a>>=1; 
		b>>=1;
		cur++;
	}
	return ans;
}

int calc(int l,int r){
	int temp=a[l];
	for(int i=l+1;i<=r;i++) {
		temp=xorf(temp,a[i]);
	}
	return temp;
}

int dp[N][N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
//	cout<<ksm(3,2)<<endl; 
//	cout<<xorf(3,4)<<endl;
//	cout<<calc(1,3)<<endl; 
	for(int i=1;i<=n;i++){
		dp[1][i]=0;
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(calc(i,j)==k){
				for(int c=1;c<j;c++){
					dp[i][j]=max(dp[j][c]+1,dp[i][j]);
				}
			} 
		}
	} 
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(dp[i][n],ans);
	}
	cout<<ans;
	return 0;
}
