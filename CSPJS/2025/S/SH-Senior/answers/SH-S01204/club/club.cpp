#include<bits/stdc++.h>
using namespace std;
int t,n;
const int maxn=1e5+5;
int na,nb,nc;
int a[maxn],b[maxn],c[maxn],m[maxn],mc[maxn];
int dp[2][maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		na=0,nb=0,nc=0;
		long long ans=0;
		cin>>n;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0){
				flag=0;
			}
			m[i]=max(max(a[i],b[i]),c[i]);
			ans+=m[i];
			if(a[i]==m[i]) na++;
			if(b[i]==m[i]) nb++;
			if(c[i]==m[i]) nc++;
		}
		if(flag==1){
			sort(a+1,a+1+n);
			for(int i=n;i>n/2;i--){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(na<=n/2 && nb<=n/2 && nc<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		ans=0;
		int pc=0;
		if(na>=nb && na>=nc){
			pc=1;
		}
		if(nb>=na && nb>=nc){
			pc=2;
		}
		if(nc>=na && nc>=nb){
			pc=3;
		}
//		cout<<"***"<<pc<<"\n";
		for(int i=1;i<=n;i++){
			if(pc==1){
				if(m[i]!=a[i]){
					if(b[i]>c[i]){
						ans+=b[i];
					}
					else{
						ans+=c[i];
					}
				}
				else{
					//v=a[i],w=1;
					for(int j=1;j<=n/2;j++){
						dp[1][j]=max(dp[0][j]+max(b[i],c[i]),dp[0][j-1]+a[i]);
					}
					dp[1][0]+=max(b[i],c[i]);
					for(int j=0;j<=n/2;j++){
						dp[0][j]=dp[1][j];
					}
				}
			}
			if(pc==2){
				if(m[i]!=b[i]){
					if(a[i]>c[i]){
						ans+=a[i];
					}
					else{
						ans+=c[i];
					}
				}
				else{
					//v=b[i],w=1;
					for(int j=1;j<=n/2;j++){
						dp[1][j]=max(dp[0][j]+max(a[i],c[i]),dp[0][j-1]+b[i]);
					}
					dp[1][0]+=max(a[i],c[i]);
					for(int j=0;j<=n/2;j++){
						dp[0][j]=dp[1][j];
					}
				}
			}
			if(pc==3){
				if(m[i]!=c[i]){
					if(a[i]>b[i]){
						ans+=a[i];
					}
					else{
						ans+=b[i];
					}
				}
				else{
					//v=c[i],w=1;
					for(int j=1;j<=n/2;j++){
						dp[1][j]=max(dp[0][j]+max(b[i],a[i]),dp[0][j-1]+c[i]);
					}
					dp[1][0]+=max(b[i],a[i]);
					for(int j=0;j<=n/2;j++){
						dp[0][j]=dp[1][j];
					}
				}
			}
		}
		cout<<ans+dp[1][n/2]<<"\n";
	}
	return 0;
}
