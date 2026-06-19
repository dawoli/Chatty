#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20,M=(1<<18)+5,mod=998244353;
int n,m,a[N],dp[2][M][N],cur,lst;
string c;
int l[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=c.size();
		if(a[i]==0) {
			l[i]=0;
			continue;
		}
		int count=0;
		for(int j=0;j<c.size();j++){
			if(c[j]=='0') {
				count++;
				if(count>=a[i]){
					l[i]=j;
					break;
				}
			}
		}
	//	cout<<i<<" "<<l[i]<<endl;
	} 
	dp[0][0][0]=1;
	cur=0,lst=1;
	for(int i=1;i<=n;i++){
		swap(cur,lst);
		for(int S=0;S<(1<<n);S++) for(int j=0;j<=n;j++) dp[cur][S][j]=0;
		for(int S=0;S<(1<<n);S++){
		//	cout<<"SSSS"<<i<<" "<<S<<endl;
			for(int j=0;j<=n;j++){
				for(int k=0;k<n;k++){
					if((S>>k)&1) continue;
					int now=0;
					if(i-j<=a[k+1]&&c[i-1]=='1')now=1;
			//		if(i==n&&(S|(1<<k))==((1<<n)-1)&&j+now==2){
			//			cout<<S<<" "<<j<<" "<<dp[i-1][S][j]<<" "<<k<<" "<<now<<endl; 
			//		}
		//	cout<<i<<" "<<(S|(1<<k))<<" "<<j+now<<" "<<dp[i-1][S][j]+dp[i][S|(1<<k)][j+now]<<endl;
					dp[cur][S|(1<<k)][j+now]=(dp[lst][S][j]+dp[cur][S|(1<<k)][j+now])%mod;		
				}
			}
		}
	}
	int cnt=0;
//	cout<<dp[2][3][1]<<endl;
	for(int j=m;j<=n;j++){
	//	cout<<j<<" "<<dp[n][(1<<n)-1][j]<<endl;
		cnt=(cnt+dp[cur][(1<<n)-1][j])%mod;
	}
	cout<<cnt<<endl;
}
/*10 5
1101111011
6 0 4 2 1 2 5 4 3 3


3 2
101
1 1 2

*/
