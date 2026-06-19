#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
	int x,y,z,id;
}num[N];
int a[N][3];
int dp[N][3];
int cnt[N][3][3];
bool cmp(stu x,stu y){
	return x.id>y.id;
}
long long dfs_ans;
void dfs(int id,long long sum,int n,int cnt1,int cnt2,int cnt3){
	if(id==n + 1){
		dfs_ans=max(dfs_ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&cnt1==n/2) continue;
		if(i==2&&cnt2==n/2) continue;
		if(i==3&&cnt3==n/2) continue;
		if(i==1) dfs(id+1,sum+a[id][i],n,cnt1+1,cnt2,cnt3);
		if(i==2) dfs(id+1,sum+a[id][i],n,cnt1,cnt2+1,cnt3);
		if(i==3) dfs(id+1,sum+a[id][i],n,cnt1,cnt2,cnt3+1);
		
	}
	
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
				scanf("%d",&num[i].x);scanf("%d",&num[i].y);scanf("%d",&num[i].z);
//				cin>>num[i].x>>num[i].y>>num[i].z;
				num[i].id=max(num[i].x,max(num[i].y,num[i].z));
			
		}
		sort(num+1,num+1+n,cmp);
		memset(a,0,sizeof(a));	
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			a[i][1]=num[i].x;
			a[i][2]=num[i].y;
			a[i][3]=num[i].z;
		}
		if(n<=10){
			dfs_ans=0;
			dfs(1,0,n,0,0,0);
			cout<<dfs_ans<<endl;
			continue;
		}
		dp[1][1]=a[1][1],dp[1][2]=a[1][2],dp[1][3]=a[1][3];
		for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) cnt[1][i][j]=0;
		cnt[1][1][1]=1,cnt[1][2][2]=1,cnt[1][3][3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[i-1][1][j]<n/2){
					if(dp[i][j]<dp[i-1][1]+a[i][j]){
						dp[i][j]=dp[i-1][1]+a[i][j];
						for(int k=1;k<=3;k++){
							if(k!=j)
							cnt[i][j][k]=cnt[i-1][1][k];
							else cnt[i][j][k]=cnt[i-1][1][k]+1;
						}
					}
				}
				if(cnt[i-1][2][j]<n/2){
					if(dp[i][j]<dp[i-1][2]+a[i][j]){
						dp[i][j]=dp[i-1][2]+a[i][j];
						for(int k=1;k<=3;k++){
							if(k!=j)
							cnt[i][j][k]=cnt[i-1][2][k];
							else cnt[i][j][k]=cnt[i-1][2][k]+1;
						}
					}
				}
				if(cnt[i-1][3][j]<n/2){
					if(dp[i][j]<dp[i-1][3]+a[i][j]){
						dp[i][j]=dp[i-1][3]+a[i][j];
						for(int k=1;k<=3;k++){
							if(k!=j)
							cnt[i][j][k]=cnt[i-1][3][k];
							else cnt[i][j][k]=cnt[i-1][3][k]+1;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			ans=max(ans,dp[n][i]);
		}
		cout<<ans<<endl;
	}
}
