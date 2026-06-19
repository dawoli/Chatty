#include<bits/stdc++.h>
using namespace std;
int T,n,col[2009],a[2009],c[2009],top;
int dp[103][103][103],d[2003][2003];
int easy(int h,int now){
	if(h>n){top=max(now,top);return 0;}
	col[h]=0;int temp=now;
	for(int q=h-1;q>=1;q--){
		if(col[q]==0){
			if(a[q]==a[h]) temp+=a[h];
			break;
		}
	}
	easy(h+1,temp);
	col[h]=1;temp=now;
	for(int q=h-1;q>=1;q--){
		if(col[q]==1){
			if(a[q]==a[h]) temp+=a[h];
			break;
		}
	}
	easy(h+1,temp);
	return 0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int haha=1;haha<=T;haha++){
		n=0;cin>>n;
		if(n<=15){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			top=0;
			easy(1,0);
			cout<<top<<endl;
			continue;
		}
		else if(n<=100){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						dp[i][j][k]=0;
					}
				}
			}
			for(int i=2;i<=n;i++){
				for(int one=1;one<=i-2;one++){
					if(a[i]==a[one]) dp[i][i-1][i]=max(dp[i-1][i-1][one]+a[i],dp[i][i-1][i]);
					else dp[i][i-1][i]=max(dp[i-1][i-1][one],dp[i][i-1][i]);
					if(a[i]==a[i-1]) dp[i][i][one]=max(dp[i-1][i-1][one]+a[i],dp[i][i][one]);
					else dp[i][i][one]=max(dp[i-1][i-1][one],dp[i][i][one]);
				}
				for(int zero=1;zero<=i-2;zero++){
					if(a[i]==a[zero]) dp[i][i][i-1]=max(dp[i-1][zero][i-1]+a[i],dp[i][i][i-1]);
					else dp[i][i][i-1]=max(dp[i-1][zero][i-1],dp[i][i][i-1]);
					if(a[i]==a[i-1]) dp[i][zero][i]=max(dp[i-1][zero][i-1]+a[i],dp[i][zero][i]);
					else dp[i][zero][i]=max(dp[i-1][zero][i-1],dp[i][zero][i]);
				}
			}
			
			int ans=0;
			for(int k=1;k<=n-1;k++) ans=max(ans,dp[n][n][k]);
			for(int k=1;k<=n-1;k++) ans=max(ans,dp[n][k][n]);
			cout<<ans<<endl;
			continue;
		}
		else if(n<=2000){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=1;i++){
				for(int j=1;j<=n;j++){
					for(int k=1;k<=n;k++){
						d[j][k]=0;
					}
				}
			}
			for(int i=2;i<=n;i++){
				for(int one=1;one<=i-2;one++){
					if(a[i]==a[one]) d[i-1][i]=max(d[i-1][one]+a[i],d[i-1][i]);
					else d[i-1][i]=max(d[i-1][one],d[i-1][i]);
					if(a[i]==a[i-1]) d[i][one]=max(d[i-1][one]+a[i],d[i][one]);
					else d[i][one]=max(d[i-1][one],d[i][one]);
				}
				for(int zero=1;zero<=i-2;zero++){
					if(a[i]==a[zero]) d[i][i-1]=max(d[zero][i-1]+a[i],d[i][i-1]);
					else d[i][i-1]=max(d[zero][i-1],d[i][i-1]);
					if(a[i]==a[i-1]) d[zero][i]=max(d[zero][i-1]+a[i],d[zero][i]);
					else d[zero][i]=max(d[zero][i-1],d[zero][i]);
				}
			}
			
			int ans=0;
			for(int k=1;k<=n-1;k++) ans=max(ans,d[n][k]);
			for(int k=1;k<=n-1;k++) ans=max(ans,d[k][n]);
			cout<<ans<<endl;
		}
	}
	return 0;
}
