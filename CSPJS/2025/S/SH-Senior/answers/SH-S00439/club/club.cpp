#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;

typedef long long ll;

int t,n,maxx;
int a[N],b[N],c[N];
int cnt[4];
ll ans,cntt;

void dfs(int dep)
{
	if (dep==n+1)
	{
		ans=max(ans,cntt);
		return;
	}
	for (int i=1;i<=3;i++)
	{
		if (cnt[i]<maxx)
		{
			cnt[i]++;
			if (i==1)	cntt+=a[dep];
			else if (i==2)	cntt+=b[dep];
			else	
				cntt+=c[dep];
			dfs(dep+1);
			cnt[i]--;
			if (i==1)	cntt-=a[dep];
			else if (i==2)	cntt-=b[dep];
			else	
				cntt-=c[dep];
		}
	} 
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		ans=0;
        cin>>n;
        maxx=(n/2);
		bool flag1=true,flag2=true;
		for (int i=1;i<=n;i++)
        {
        	cin>>a[i]>>b[i]>>c[i];
        	if (b[i]!=0)
        		flag1=false;
        	if (c[i]!=0)
        		flag2=false;
		}
 		if (n<=30)
		{
			cntt=0;
			dfs(1);
			cout<<ans<<endl;
		}
		else if (flag1 && flag2)
		{
			sort(a+1,a+n+1,cmp);
			for (int i=1;i<=maxx;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			
		}
	}
	
	return 0;
}
