#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vm,ansn,ansm;
int d[100100];
int v[100100];
int a[100100];
int p[100100];
double t1;
int main()
{
	//freopen("detect3.in","r",stdin);
	//freopen("detect.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ansn=0,ansm=0;
		cin>>n>>m>>l>>vm;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		if(n>20||m>20)
		{
				int x=1;
			    for(int i=1;i<=n;i++)
			    {
				    if(v[i]<=vm||d[i]>p[m])d[i]=0;
				    else ansn=ansn+1;
			    }
			    for(int i=1;i<=n;i++)
		        {
		    	    if(d[x]<d[i])x=i;
			    }
			    if(ansn==0)ansm=m;
			    else ansm=m-1;
			    cout<<ansn<<" "<<ansm<<endl;
		}
		
	}
	return 0;
}
