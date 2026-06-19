#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
	int sa,sb,sc;
} s[int(1.1e5)];
int t[int(3.1e5)];
int idx=0;
#define ll long long
//17:06 RIP
//17:43 RIP
vector<stu> pa,pb,pc;
bool cmpa(stu x,stu y){
	return x.a>y.a;
}
bool cmpb(stu x,stu y){
	return x.b>y.b;
}
bool cmpc(stu x,stu y){
	return x.c>y.c;
}
ll dp[300][300][300]={0},ans=-1;
void test(void){
	long long spec2=1,summa=0;
	idx=0;
	int n;
	cin>>n;
	ans=-1;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].b!=0 or s[i].c!=0){
			spec2=0;
		} 
		summa+=s[i].a;
	}
	if(spec2){
		cout<<summa<<"\n";
		return;
	}
	dp[1][1][0]=s[1].a;
	dp[1][0][0]=s[1].c;
	dp[1][0][1]=s[1].b;
	for(int i=2;i<=n;i++){
		for(int a=0;a<=n/2;a++){
			for(int b=0;b<=n/2;b++){
				int c=i-a-b;
				
				if(c>n/2 or c<0){
					continue;
				}else{
					// as a
					dp[i][a][b]=-1;
					if(a-1>=0) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a-1][b]+s[i].a);
					if(b-1>=0) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b-1]+s[i].b);
					if(c-1>=0) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b]+s[i].c);
					//printf("dp[%d][%d][%d](%d)=%d\n",i,a,b,c,dp[i][a][b]);
					if(i==n){
						ans=max(ans,dp[i][a][b]);
					}
				}
			}
		}
	} 
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		//clog<<"Test #"<<T<<"\n";
		test();	
	}
}
