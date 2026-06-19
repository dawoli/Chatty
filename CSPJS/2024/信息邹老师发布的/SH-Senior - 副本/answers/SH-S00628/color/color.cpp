#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005],c[1000005];
long long dp[1000005],qzh[1000005];
void init(){
	memset(dp,0,sizeof(dp));
	memset(qzh,0,sizeof(qzh));
	memset(c,0,sizeof(c));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		init();
		for(int i=1;i<=n;i++){ 
			cin>>a[i];
			b[i]=c[a[i]];
			c[a[i]]=i;
			qzh[i]=(a[i]==a[i-1]?a[i]:0)+qzh[i-1];
		}
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				dp[i]=dp[i-1];
			}else{
				if(i-b[i]>=2){
					dp[i]=max(dp[i-1],a[i]+dp[b[i]+1]+qzh[i-1]-qzh[b[i]]);
				}else{
					dp[i]=max(dp[i-1],a[i]+dp[b[i]]);
				}
			}
		}
		cout<<dp[n]<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
