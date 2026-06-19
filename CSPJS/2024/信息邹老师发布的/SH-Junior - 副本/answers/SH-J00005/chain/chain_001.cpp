#include <bits/stdc++.h>
#include <queue>
using namespace std;
int times;
const int qq=10020;
int app[200020][2];
int app1[200020][2];
int num[qq][qq];
int l[qq];
int r[qq],c[qq],ans[qq];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>times;
	while(times>0)
	{
		times--;
		int n,k,q;
		cin>>n>>k>>q;
		memset(l,0,sizeof(l));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
				cin>>num[i][j];
		}
		int rmax=1;
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		for(int pl=0;pl<q;pl++)
		{
			cin>>r[pl]>>c[pl];
			rmax=max(rmax,r[pl]);
		}
		for(int mmm=0;mmm<rmax;mmm++)
		{
			memset(app,0,sizeof(app));
			memset(app1,0,sizeof(app1));
			for(int i=0;i<200010;i++)
			{
				app1[i][0]=app[i][0];
				app1[i][1]=app[i][1];
				app[i][0]=0;
				app[i][1]=0;
			}
			if(mmm==0)
			{	
				app1[1][0]=1;
				app1[1][1]=-1;
			}
			for(int i=1;i<k;i++)
			{
				for(int p=1;p<=n;p++)
				{
					for(int loc=1;loc+i<=l[p];loc++)
					{
						if(app1[num[p][loc]][0]&&app1[num[p][loc]][1]!=p)
						{
							app[num[p][loc+i]][0]++;
							if(app[num[p][loc+i]][1]==0)
								app[num[p][loc+i]][1]=p;
							else
								app[num[p][loc+i]][1]=-1;
						}
					}
				}
			}
			for(int pl=0;pl<q;pl++)
			{
				if(r[pl]==mmm)
				{
					if(app[c[pl]][0]>0)
						ans[pl]=1;
					else
						ans[pl]=0;
				}
			}
		}
		for(int pl=0;pl<q;pl++)
		{
			cout<<ans[pl]<<endl;
		}
	}
}
