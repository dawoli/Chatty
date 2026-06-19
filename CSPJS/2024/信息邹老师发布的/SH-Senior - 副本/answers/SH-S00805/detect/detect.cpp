#include <bits/stdc++.h>
using namespace std;
int t,n,m,L,V,p,d[100005],v[100005],a[100005],visc[100005],visn[3005][3005],visnn[100005],anscar,ansnum;
void check(int x,int numm)
{
	int add=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>x)
		{
			continue;
		}
		float vv=sqrt((x-d[i])*2*a[i]+pow(v[i],2));
		if(vv>V)
		{
			visn[numm][i]=1;
			if(visc[i]==0)
			{
				add=1;
				visc[i]=1;
			}
		}
	}
	if(!add)
	{
		ansnum++;
		visnn[numm]=1;
		return; 
	}
	for(int i=1;i<numm;i++)
	{
		if(visnn[i])
		{
			continue;
		}
		int del = 1;
		for(int j=1;j<=n;j++)
		{
			if(visn[i][j]==1&&visn[numm][j]==0)
			{
				del=0;
			}
		}
		if(del)
		{
			visnn[i]=1;
			ansnum++;
		}
	}
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--)
	{
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(visc,0,sizeof(visc));
		memset(visn,0,sizeof(visn));
		memset(visnn,0,sizeof(visnn));
		anscar=0;
		ansnum=0;
		cin >> n >> m >> L >> V;
		for(int i=1;i<=n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin >> p;
			check(p,i);
		}
		for(int i=1;i<=n;i++)
		{
			if(visc[i]>0)
			{
				anscar++;
			}
		}
		cout << anscar << " " << ansnum << endl;
	}
	return 0;
}
