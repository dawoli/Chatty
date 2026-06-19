#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fr(aaa,bbb,i) for(int i=aaa,i##end=bbb;i<=i##end;++i)
#define rf(bbb,aaa,i) for(int i=bbb,i##end=aaa;i>=i##end;--i)
#define maxn 2007
#define maxv 1000007
int t,n,a[maxn],g[maxn][maxn],dp[maxn][2],now[maxv],bol[maxv],lst[maxv],kk[maxv];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>t;fr(1,1000000,i) now[i]=100000000,kk[i]=100000000;
	while(t--){
		cin>>n;
		fr(1,n,i) cin>>a[i];
		fr(1,n,i){
			if(now[a[i]]!=t){
				now[a[i]]=t;
			}else{
				lst[i]=bol[a[i]];
				kk[i]=t;
			}
			bol[a[i]]=i;
		}
		fr(1,n,i){
			int ans=0;
			fr(i+1,n,j){
				if(a[j]==a[j-1]) ans+=a[i];
				g[i][j]=ans;
			}
		}
		fr(1,n,i){
			if(kk[i]!=t){
				dp[i][0]=dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
				continue;
			}
			else if(i-lst[i]+1>=3){
				dp[i][0]=dp[lst[i]+1][1]+g[lst[i]+1][i-1]+a[i];
				dp[i][1]=dp[lst[i]+1][0]+g[lst[i]+1][i-1]+a[i];
			}else{
				dp[i][0]=a[i];
				dp[i][1]=a[i];
			}
			dp[i][0]=max(dp[i-1][0],(dp[i-1][1],dp[i][0]));
			dp[i][1]=max(dp[i-1][0],(dp[i-1][1],dp[i][1]));
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
} /*

3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

*/
