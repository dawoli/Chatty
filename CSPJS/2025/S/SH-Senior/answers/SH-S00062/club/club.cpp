#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int t,n,dp[N][3]; 
struct temp{
	int a,b,c;
}inpt[N];
bool cmp(const temp &u,const temp &v){
	if(u.a>v.a)return 1;
	else if(u.a==v.a&&u.b>v.b)return 1;
	else if(u.a==v.a&&u.b==v.b&&u.c>v.c)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>inpt[i].a>>inpt[i].b>>inpt[i].c;
		}
		if(n==2){
			int a1=inpt[1].a+inpt[2].b;
			int a2=max(a1,inpt[1].a+inpt[2].c);
			int a3=max(a2,inpt[1].b+inpt[2].a);
			int a4=max(a3,inpt[1].b+inpt[2].c);
			int a5=max(a4,inpt[1].c+inpt[2].a);
			int a6=max(a5,inpt[1].c+inpt[2].b);
			cout<<a6<<endl;
		}
		else if(n<=10){
			int res=0;
			for(int i=0;i<pow(3,n);i++){
				int t=i,choose[19];
				for(int j=0;j<n;j++){
					choose[j]=t%3;
					t/=3;
				}
				int cnt0=0,cnt1=0,cnt2=0;
				for(int j=0;j<n;j++){
					if(choose[j]==0)cnt0++;
					if(choose[j]==1)cnt1++;
					if(choose[j]==2)cnt2++;
				}
				if(cnt0>n/2||cnt1>n/2||cnt2>n/2)continue;
				int ans=0;
				for(int j=0;j<n;j++){
					if(choose[j]==0)ans+=inpt[j+1].a;
					if(choose[j]==1)ans+=inpt[j+1].b;
					if(choose[j]==2)ans+=inpt[j+1].c;
				}
				res=max(res,ans);
			}
			cout<<res<<"\n";
		}
		else{
			sort(inpt+1,inpt+1+n,cmp);
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				int p=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
				dp[i][1]=p,dp[i][2]=p,dp[i][3]=p;
				if(cnt1+1<=n/2)dp[i][1]+=inpt[i].a;
				if(cnt2+1<=n/2)dp[i][2]+=inpt[i].b;
				if(cnt3+1<=n/2)dp[i][3]+=inpt[i].c;
				int p2=max(dp[i][1],max(dp[i][2],dp[i][3]));
				if(dp[i][1]==p2)cnt1++;
				if(dp[i][2]==p2)cnt2++;
				if(dp[i][3]==p2)cnt3++;
			}
			ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
			cout<<ans<<endl;
		}
	}
	return 0;
} 
