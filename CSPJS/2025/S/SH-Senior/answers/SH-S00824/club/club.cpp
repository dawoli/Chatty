#include <bits/stdc++.h>
using namespace std;
const int maxn=100001;
int a[maxn][4],k[maxn],tt[4],m[maxn];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,ans,maxnnn,maxnn;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		ans=0;
		tt[1]=0;
		tt[2]=0;
		tt[3]=0;
		tt[4]=0;
		for(int x=1;x<=n;x++)
		{
			for(int y=1;y<=4;y++)
				a[x][y]=0;
			k[x]=0;
			m[x]=0;
		}
		cin>>n;
		for(j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3])	m[j]=1;
			else
			{
				if(a[j][2]>=a[j][3])	m[j]=2;
				else	m[j]=3;
			}
			tt[m[j]]++;
			sort(a[j],a[j]+n);
			ans+=a[j][3];
			//cout<<ans<<endl;
		}
		int p=max(tt[1],max(tt[2],tt[3]));
		int ttt;
		if(p==tt[1])	ttt=1;
		else
		{
			if(p==tt[2])	ttt=2;
			else	ttt=3;
		}
		while(2*p>n)
		{
			//cout<<"p:"<<p<<endl;
			maxnn=200001;
			for(int q=1;q<=n;q++)
			{
				//cout<<"a[q][3]-a[q][2]"<<a[q][3]-a[q][2]<<endl;
				//cout<<m[q]<<" "<<ttt<<endl;
				if(a[q][3]-a[q][2]<maxnn&&m[q]==ttt)
				{
					maxnnn=q;
					maxnn=a[q][3]-a[q][2];
					//cout<<endl<<"maxnn:"<<maxnn<<endl;
				}
			}
			//cout<<a[maxnnn][3]<<" "<<a[maxnnn][2]<<" "<<a[maxnnn][1]<<endl;
			ans-=a[maxnnn][1];
			ans+=a[maxnnn][2];
			p--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
