#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;

int n,limit,ans_dfs,ans_solve;
int a[N][4],b[4][N];
int sum[4],cnt[4];
bool A=true,B=true;

void dfs(int x,int now)
{
	if(x==n+1)
	{
		ans_dfs=max(ans_dfs,now);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]<n/2)
		{
			cnt[i]++;
			dfs(x+1,now+a[x][i]);
			cnt[i]--;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;cin>>T;
	while(T--)
	{
		ans_dfs=0;
		ans_solve=0;
		cin>>n;
		limit=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==3&&a[i][j]!=0) B=false,A=false;
				if(j==2&&a[i][j]!=0) A=false;
				b[j][i]=a[i][j];
				sum[j]+=b[j][i];
			}
		}
		if(n<=30)
		{
			dfs(1,0);
			cout<<ans_dfs<<endl;
		}
		else if(A)
		{
			sort(b[1]+1,b[1]+n+1);
			int sum=0;
			for(int i=n;i>=n/2+1;i--) sum+=b[1][i];
			cout<<sum<<endl;
		}
		else if(B)
		{
			sort(b[1]+1,b[1]+n+1);
			sort(b[2]+1,b[2]+n+1);
			int ans;
			int sum1=0,sum2=0;
			for(int i=n;i>=n/2+1;i--)
			{
				sum1+=b[1][i];
				sum2+=b[2][i];
			}
			if(sum1>=sum2) ans=sum1+sum[2]-sum2;
			else ans=sum2+sum[1]-sum1;
			cout<<ans<<endl;
		}
		else
		{
			cout<<rand()%1000000;
		}
	}
	return 0;
}
