#include <bits/stdc++.h>
using namespace std;
bool b[10005]={0};
int c[100006]={0};
int d[100006];
int v1[100005];
int a[100005];
int p[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,v2,chao,sig,num=0,ans=0;
	cin>>t;
	while(t--)
	{
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v1[i]>>a[i];
		}
		for(int j=1;j<=m;j++)
		{
			cin>>p[j];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||a[i]>=0&&v1[i]>v)
			{
				if(v1[i]<=v) continue;
				else
				{
					for(int j=1;j<=m;j++)
		            {
			            if(p[j]>=d[i])
			            {
			            	b[i]=1;
			    	        c[p[j]]++;
			    	    }
			    	} 
				}
			}
			else if(v1[i]<v&&a[i]>0){
			chao=(v*v-v1[i]*v1[i])/(2*a[i]);
			sig=d[i]+chao;
			for(int j=1;j<=m;j++)
		    {
			    if(p[j]>sig)
			    {
			    	b[i]=1;
			    	c[p[j]]++;
				}
		    }
		    }
		    else
		    {
		    	chao=(v*v-v1[i]*v1[i])/(2*a[i]);
			    sig=d[i]+chao;
			    for(int j=1;j<=m;j++)
		        {
			        if(p[j]<sig&&p[j]>=d[i])
			        {
			        	b[i]=1;
			        	c[p[j]]++;
			    	}
		        }
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1) num++;
		}
		cout<<num<<" ";
		for(int i=1;i<=m;i++)
		{
			cout<<c[p[i]]<<" ";
			if(c[p[i]]!=num) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
