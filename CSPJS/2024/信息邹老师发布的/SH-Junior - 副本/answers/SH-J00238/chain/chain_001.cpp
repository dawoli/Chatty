#include<bits/stdc++.h>
using namespace std;
int q_[200001],h[1001],l[1001],s,tmp;
int T,n,k,q,a,b,d,i,j;
int r[1001],c[1001],max_r;
bool dp[11][2001][1001],ans[1001];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++)
	{
		memset(q_,0,sizeof(q_));
		memset(ans,false,sizeof(ans));
		memset(dp,false,sizeof(dp));
		cin>>n>>k>>q;
		tmp=1;
		max_r=0;
		for(j=1;j<=n;j++)
		{
			cin>>l[i];
			h[i]=tmp;
			for(a=1;a<=l[i];a++)
			{
				cin>>s;
				q_[tmp]=s;
				tmp++;
			}
		}
		for(j=1;j<=q;j++)
		{
			cin>>r[j]>>c[j];
			max_r=max(max_r,r[j]);
		}
		if(max_r==1)
		{
			for(j=1;j<=n;j++)
			{
				for(a=h[j];a<h[j]+l[j];a++)
				{
					if(q_[a]!=1)continue;
					for(b=1;b<=k;b++)
					{
						if(a+b<h[j]+l[j])
						{
							for(d=1;d<=q;d++)
								if(q_[a+b]==c[d])
									ans[d]=true;
						}
					}
				}
			}
			for(j=1;j<=q;j++)
				if(ans[j])cout<<1<<endl;
				else cout<<0<<endl;
		}
		for(j=1;j<=n;j++)
		{
			for(a=h[j];a<h[j]+l[j];a++)
			{
				if(q_[a]!=1)continue;
				for(b=1;b<=k;b++)
				{
					if(a+b<h[j]+l[j])
						dp[1][a+b][i]=true;
				}
			}
		}
		for(j=2;j<=max_r;j++)
		{
			
		}
	}
	return 0;
}
