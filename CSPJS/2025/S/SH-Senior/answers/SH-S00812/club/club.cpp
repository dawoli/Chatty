#include<bits/stdc++.h>
using namespace std;
const int N=1e5+19;
int T,n,a[N][4],ans,lst[N],cnt;
void dfs(int step,int s1,int s2,int s3,int sum){
	if(step==n+1){
		ans=max(ans,sum);
	}
	int sb;
	int t=min(a[step][1],min(a[step][2],a[step][3]));
	if(a[step][1]==t)sb=1;
	else if(a[step][2]==t)sb=2;
	else sb=3;
	if(a[step][1]==a[step][2]||a[step][1]==a[step][3]||a[step][2]==a[step][3])sb=0;
	if(s1+1<=n/2&&sb!=1)dfs(step+1,s1+1,s2,s3,sum+a[step][1]);
	if(s2+1<=n/2&&sb!=2)dfs(step+1,s1,s2+1,s3,sum+a[step][2]);
	if(s3+1<=n/2&&sb!=3)dfs(step+1,s1,s2,s3+1,sum+a[step][3]);
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0,cnt=0;
		memset(lst,0,sizeof(lst));
		cin>>n;
		int flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]>0||a[i][3]>0)flag2=0;
			lst[++cnt]=a[i][1];
		}
		if(flag2){
			sort(lst+1,lst+cnt+1);
			for(int i=1+n/2;i<=n;i++){
				ans+=lst[i];
			}
			cout<<ans<<endl;
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
