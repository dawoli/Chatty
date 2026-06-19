#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll val,id;
}d[N];
ll a[N],b[N],c[N];
ll dp[202][101][101];
int T,n;
bool cmp(node a,node b){
	return a.val<b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) flag1=0;
			if(c[i]!=0) flag2=0;
		}
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					for(int k=0;k<=min(i,n/2);k++){
						if(i-j-k>n/2) continue;
						if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
						if(i-j-k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
						/*
						if(j==0&&k==0) dp[i][j][k]=dp[i-1][j][k]+c[i];
						else if(j==0) dp[i][j][k]=max(dp[i-1][j][k-1]+b[i],dp[i-1][j][k]+c[i]);
						else if(k==0) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k]+c[i]);
						else if(i-j-k==0) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k-1]+b[i]);
						else dp[i][j][k]=max(max(dp[i-1][j-1][k]+a[i],dp[i-1][j][k-1]+b[i]),dp[i-1][j][k]+c[i]);
						cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
						*/ 
					}
				}
			}
			ll ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-i-j>n/2) continue;
					ans=max(ans,dp[n][i][j]);
					//cout<<i<<" "<<j<<" "<<dp[n][i][j]<<endl;
				}
			}
			cout<<ans<<endl; 
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++) dp[i][j][k]=0;
				}
			}
		}
		else if(flag1){
			ll ans=0;
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++) ans+=a[i];
			cout<<ans<<endl;
		}
		else if(flag2){
			ll ans=0;
			for(int i=1;i<=n;i++) d[i].val=a[i]-b[i],d[i].id=i;
			sort(d+1,d+n+1,cmp);
			for(int i=n/2+1;i<=n;i++) ans+=a[d[i].id];
			for(int i=1;i<=n/2;i++) ans+=b[d[i].id];
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[++cnt];
			}
			e[cnt-2]=e[cnt-2]-e[cnt];
			e[cnt-1]=e[cnt-1]-e[cnt];
			ans+=e[cnt];
			d[i].val=e[cnt-2]-e[cnt-1];
			d[i].id=i;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) cout<<d[i].val<<endl;
		ll haf=n/2;
		sort(d+1,d+n+1,cmp);
		if(d[haf+1].val>=0){
			cout<<"01010"<<endl;
			for(int i=haf+1;i<=n;i++) ans+=e[(d[i].id-1)*3+1],cout<<d[i].id<<" "<<e[(d[i].id-1)*3+1]<<" "<<ans<<endl;
			//cout<<ans<<endl;
			for(int i=haf;i>=1;i--){
				if(d[i].val<=0) ans+=e[(d[i].id-1)*3+2],cout<<d[i].id<<" "<<e[(d[i].id-1)*3+2]<<" "<<ans<<endl;
			}
			//cout<<ans<<endl;
		}
		else{
			cout<<"02020"<<endl;
			for(int i=haf;i>=1;i--) ans+=e[(d[i].id-1)*3+2],cout<<d[i].id<<" "<<e[(d[i].id-1)*3+2]<<" "<<ans<<endl;
			for(int i=haf+1;i<=n;i++){
				if(d[i].val>=0) ans+=e[(d[i].id-1)*3+1],cout<<d[i].id<<" "<<e[(d[i].id-1)*3+1]<<" "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
		ans=0; cnt=0;
	}
*/
