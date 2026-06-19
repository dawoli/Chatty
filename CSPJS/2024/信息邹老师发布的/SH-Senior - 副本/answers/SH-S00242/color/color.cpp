#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005][2],mx[2005][2],cal[2005][2005],a[2005],t,n,ans;
inline int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k*f;
}
void init(){
	memset(dp,0,sizeof(dp));
	memset(mx,0,sizeof(mx));
	memset(cal,0,sizeof(cal));
	ans=0;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--){
		init();
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			int tmp=0;
			for(int j=i;j<=n;j++){
				if(a[j]==a[j-1]) tmp+=a[j];
				cal[i][j]=tmp;
			}
		}
		for(int i=1;i<=n;i++){//now
			for(int k=1;k<=i-2;k++){
				dp[i][i-1][0]=dp[i-1][k][0]+(a[i]==a[i-1])?a[i]:0;
				dp[i][i-1][1]=dp[i-1][k][1]+(a[i]==a[i-1])?a[i]:0;
			}
			for(int j=1;j<=i-2;j++){
				dp[i][j][0]=max(dp[i][j][0],cal[j+2][i-1]+((a[i]==a[j])?a[i]:0)+mx[j+1][1]);
				dp[i][j][1]=max(dp[i][j][1],cal[j+2][i-1]+((a[i]==a[j])?a[i]:0)+mx[j+1][0]);
			}
			for(int j=1;j<=i-2;j++){
				mx[i][0]=max(mx[i][0],dp[i][j][0]);
				mx[i][1]=max(mx[i][1],dp[i][j][1]);
			}
		}
		for(int i=1;i<n;i++) ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
		if(n==2&&a[1]==a[2]) ans+=a[1]; 
      	cout<<ans<<"\n";
	}
	return 0;
}
