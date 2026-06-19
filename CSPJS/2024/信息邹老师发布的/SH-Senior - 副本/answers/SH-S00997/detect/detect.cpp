#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,v,cnt=0,outputa=0,outputb=0;
int dcar[1000100],vcar[1000100],acar[1000100],decnt[1000100]={},p[1000100]={};
bool pcatched[1000100]={}; 
int sum,over=0;
bool IsOverspeed(int Car_Number)
{
	if(acar[Car_Number]==0)
	{
		if(dcar[Car_Number]>cnt)     return false;
		if(vcar[Car_Number]<=v)      return false;
		return true;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cnt=0,outputa=0,outputb=0;
		cin>>n>>m>>l>>v;
		int dcar[1000100],vcar[1000100],acar[1000100],decnt[1000100]={},p[1000100]={};
		bool pcatched[1000100]={}; 
		for(int i=0;i<n;i++)
		{
			cin>>dcar[i]>>vcar[i]>>acar[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
			sum++;
			for(int j=cnt;j<p[i];j++)
			{
				decnt[j]=sum;
			}
			cnt=p[i];
		}
		sum++;
		for(int j=cnt;j<=l;j++)
		{
			decnt[j]=sum;
		}
		for(int i=0;i<n;i++)
		{
			if(IsOverspeed(i))     outputa++;
		}
		cout<<outputa<<" ";
		if(outputa==0)    cout<<m<<endl;
		else              cout<<m-1<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
