#include<bits/stdc++.h>
using namespace std;
long long d[1000005],v[1000005],a[1000005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long T,n,m,L,V;
	bool check=0;
	cin>>T;
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		long long out=0,ld=0,lm=-1;
		cin>>n>>m>>L>>V;
		for(long long i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)check=1;
		}
		for(long long i=1;i<=m;i++)
		{
			long long c;
			cin>>c;
			lm=max(c,lm);
		}
		if(check==0){
			for(long long i=1;i<=n;i++)
			{
				if(d[i]<=lm&&v[i]>V)
				{
					out++;
				}
			}
		}else
		{
			for(long long i=1;i<=n;i++)
			{
				double x=sqrt(v[i]*v[i]+2*a[i]*(lm-d[i]));
				if(x>V&&d[i]<=lm)
				{
					out++;
				}
			}
		}
		cout<<out<<" ";
		if(out==0)
		{
			cout<<m;
		}else cout<<m-1;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

