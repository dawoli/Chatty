#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[100010][3];
int x[100010],y[100010];
int dp[100010][4];
int cnt[10];
struct node{
	int p,q,r;
}c[100010];

bool cmp2(node a,node b){
	return a.r<b.r;
}

//15:58 5 X 5=25 tps
//18:20 8 X 5=40 tps

//18:20 ALL=40+[10,25]+48+[8,12]=[106,124]
//hope me have CSP 2025 S 1=

void dfs(int x,int now){
	if(cnt[1]>n/2 || cnt[2]>n/2 || cnt[3]>n/2)return;
	if(x==n+1){
		ans=max(ans,now);
		return;
	}
	cnt[1]++;
	dfs(x+1,now+a[x][1]);
	cnt[1]--;
	cnt[2]++;
	dfs(x+1,now+a[x][2]);
	cnt[2]--;
	cnt[3]++;
	dfs(x+1,now+a[x][3]);
	cnt[3]--;
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		ans=0;
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)flag1=0;
			if(a[i][3]!=0)flag2=0;
		}
		if(flag1==1 && flag2==1){
			for(int i=1;i<=n;i++)x[i]=a[i][1];
			sort(x+1,x+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=x[i];
			}
            cout<<ans<<endl;
            continue;
		}
		if(flag2==1){
			for(int i=1;i<=n;i++){
				c[i].p=a[i][1];
				c[i].q=a[i][2];
				c[i].r=a[i][1]-a[i][2];
			}
			sort(c+1,c+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=n/2){
				    ans+=c[i].q;
				}
				else ans+=c[i].p;
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0);/*
		for(int i=1;i<=n;i++){
			int m1=0,m2=0,m3=0;
			for(int j=n/2;j>=1;j--){
				dp[j][1]=max(dp[j-1][1],max(dp[j-1][2],dp[j-1][3]))+a[i][1];
				dp[j][2]=max(dp[j-1][1],max(dp[j-1][2],dp[j-1][3]))+a[i][2];
				dp[j][3]=max(dp[j-1][1],max(dp[j-1][2],dp[j-1][3]))+a[i][3];
				cout<<dp[j][1]<<" "<<dp[j][2]<<" "<<dp[j][3]<<endl;
				m1=max(m1,max(dp[j][2],dp[j][3]));
				m2=max(m2,max(dp[j][1],dp[j][3]));
				m3=max(m3,max(dp[j][2],dp[j][1]));
			}
			//dp[0][1]=m1,dp[0][2]=m2,dp[0][3]=m3;
		}
		for(int j=1;j<=n/2;j++){
			ans=max(ans,max(dp[j][1],max(dp[j][2],dp[j][3])));
		}*/
		cout<<ans<<endl;
	}
	return 0;
}
