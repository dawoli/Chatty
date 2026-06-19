#include<bits/stdc++.h>
using namespace std;
const int maxs=100001;
int d[maxs],a[maxs],v[maxs];
struct ha
{
	int fro;
	int las;
}sad[maxs];
int p[maxs];
int T,n,m,l,V,ansspeed=0;
bool cmp(ha a,ha b)
{
	if(a.fro<b.fro)
	{
		return 1;
	}
	else if(a.fro==b.fro&&a.las<b.las)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int asdf=0;asdf<T;asdf++)
	{
		ansspeed=0;
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]>0)
			{
				double lastone=double((V-v[i])*(V+v[i]))/(a[i]*2.0);
				if(lastone<=(long double)V)
				{
					if(lastone!=int(lastone))
					{
						lastone+=1;
					}
					sad[i].fro=d[i]+lastone;
					sad[i].las=l;
				}
				else
				{
					sad[i].fro=-1;
					sad[i].las=-1;
					continue;
				}
			}
			else if(v[i]>V)
			{
				if(a[i]<0)
				{
					double lastone=double((V-v[i])*(V+v[i]))/(a[i]*(2.0));
					if(lastone==int(lastone))
					{
						lastone+=1;
					}
					sad[i].fro=d[i];
					sad[i].las=d[i]+lastone;
				}
				else
				{
					
					sad[i].fro=d[i];
					sad[i].las=l;
				}
			}
			else
			{
				sad[i].fro=-1;
				sad[i].las=-1;
				continue;
			}
			if(sad[i].las>l)
			{
				sad[i].las=l;
			}
			
		}
		sort(sad,sad+n,cmp);
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
		}
		int ans=0,j=0;
		int last_=-1;
		int last=0;
		for(int i=0;i<m&&j<n;)
		{ 
			last=j;
//			cout<<i<<" "<<j<<" "<<ansspeed<<" "<<ans<<endl;
			while(p[i]>sad[j].las&&i<m&&j<n)
			{
				j++;
			}
			while(p[i]<sad[j].fro&&i<m&&j<n)
			{
				i++;
				while(p[i]>sad[j].las)
				{
					j++;
				}
			}//ȡI p[i]>=fro
			
			last_=sad[j].las;
			while(p[i]>=sad[j+1].fro&&i<m&&j<n)
			{
				j++;
				ansspeed++;
				last_=min(sad[j].las,last_);
			}
			while(p[i]<=last_&&i<m&&j<n)
			{
				last_=min(sad[j].las,last_);
				i++;
				while(p[i]>=sad[j+1].fro&&i<m&&j<n)
				{
					j++;
					ansspeed++;
					last_=min(sad[j].las,last_);
				}
			}
			ans++;
//			cout<<i<<" "<<j<<" "<<ansspeed<<" "<<ans<<endl;
		} 
		cout<<ansspeed<<" "<<n-ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
