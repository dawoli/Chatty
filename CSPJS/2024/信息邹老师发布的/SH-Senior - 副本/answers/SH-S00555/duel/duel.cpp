#include <bits/stdc++.h>
using namespace std;
int n,i,m,hp[100000],atk[100000],j,du[2],sum,h;
int main()
{
	freopen(duel.in,"r",stdin);
	freopen(duel.out,"w",stdout);
	memset(hp,0,sizeof(hp));
	memset(atk,0,sizeof(atk));
	cin>>n;
	h=0;
	j=1; 
	for(i=1;i<=n;i++)
	{
		cin>>m;
		if(h<m) h=m;
		hp[m]++;
		atk[m]++;
	}
	for(i=1;i<=h+1;i++)
	{
		if(j==3)//¾ö¶· 
		{
			if(atk[du[2]]>=hp[du[1]]) 
			{
			atk[du[1]]=0;
			atk[du[2]]-=hp[du[1]];
			hp[du[1]]=0;
			du[1]=du[2];
			j=2;
			}
			else 
			{
			hp[du[1]]-=atk[du[2]];
			atk[du[2]]=0;
			hp[du[1]]+=hp[du[2]];
			hp[du[2]]=0;
			j=2;
			}
		}
		if(hp[i]>0) 
		{
			du[j]=i;
			j++;
		}
	}
	sum=0;
	for(i=1;i<=h;i++) sum+=hp[i];
	cout<<sum<<endl;
	return 0;
	
}
