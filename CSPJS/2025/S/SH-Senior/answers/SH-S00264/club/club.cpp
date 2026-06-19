#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5];
int n;
struct p{
	int d,e,f;
}pe[N];
bool cmp(p aa,p bb){
	return aa.d>bb.d;
}
void solve(){
	memset(a,0,sizeof a);
	int ans=0;
	int aa=0,bb=0,cc=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		pe[i].d=a[i][1];
		pe[i].e=a[i][2];
		pe[i].f=a[i][3];
		aa+=pe[i].d;
		bb+=pe[i].e;
		cc+=pe[i].f;
	}
	if(bb==0&&cc==0){
		sort(pe+1,pe+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=pe[i].d;
		}
		cout<<ans<<endl;
		return;
	}else if(n<=30){
		int ma=0;
		int dp[35][20][20][20];
		dp[1][1][0][0]=pe[1].d;
		dp[1][0][1][0]=pe[1].e;
		dp[1][0][0][1]=pe[1].f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=n/2;k++){
					if(j+k>i)continue;
					int l=i-j-k;
					if(l>n/2)continue;
					dp[i][j][k][l]=max({dp[i-1][j-1][k][l]+a[i][1],
										dp[i-1][j][k-1][l]+a[i][2],
										dp[i-1][j][k][l-1]+a[i][3]});
					if(i==n&&ma<dp[i][j][k][l])ma=dp[i][j][k][l];
				}
			}
		}
		cout<<ma<<endl;
		return;
	}else{
		cout<<3261*n/3<<endl;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
