#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,lim;
int a[N][3];
int b[N];
int dp[202][102][102];
int ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		lim=n/2;
		bool flag=true;
		for(int i=1;i<=n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			b[i]=a[i][0];
			if(a[i][1]!=0||a[i][2]!=0){
				flag=false;
			}
		}
		if(flag==true){
			sort(b+1,b+n+1);
			for(int i=n;i>=lim+1;--i){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		dp[1][1][0]=a[1][0];
		dp[1][0][1]=a[1][1];
		dp[1][0][0]=a[1][2];
		for(int i=2;i<=n;++i){
			for(int x=0;x<=i;x++){
				if(x>lim)	break;
				for(int y=0;y<=i-x;y++){
					if(y>lim)	break;
					if(i-x-y>lim)	continue;
					int d1,d2,d3;
					if(x==0){
						d1=0;
					}else{
						d1=dp[i-1][x-1][y]+a[i][0];
					}
					if(y==0){
						d2=0;
					}else{
						d2=dp[i-1][x][y-1]+a[i][1];
					}
					if(i-x-y==0){
						d3=0;
					}else{
						d3=dp[i-1][x][y]+a[i][2];
					}
					dp[i][x][y]=max(d1,max(d2,d3));
				}
					
			}
			
		}
		for(int x=0;x<=lim;++x){
			for(int y=lim-x;y<=lim;++y){
				
				if(dp[n][x][y]>ans){
					ans=dp[n][x][y];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
