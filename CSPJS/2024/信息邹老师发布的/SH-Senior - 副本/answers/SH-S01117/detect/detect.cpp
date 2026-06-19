#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		int n,m,L,V,d[100010],p[100010],v[100010],a[100010];
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int j=1;j<=n;++j) scanf("%d%d%d",&d[j],&v[j],&a[j]);
		for(int j=1;j<=m;++j) scanf("%d",&p[j]);
		int c[100010];//超速的距离 
		int tmp1=0,tmp2=0,tmp3=0;
		for(int j=1;j<=n;++j)
		    if(a[j]==0) tmp1++;
		    else if(a[j]>0) tmp2++;
		    else tmp3++;
	    for(int j=1;j<=n;++j)
	    {
	    	if(a[j]>0&&v[j]<V)
	    	    c[j]=ceil(((V+1)*(V+1)-v[j]*v[j])/(2*a[j]));
	        if(v[j]>V&&a[j]>=0||(a[j]<0&&v[j]<V)) c[j]=0;
	        if(a[j]<0&&v[j]>V) c[j]=ceil(((V+1)*(V+1)-v[j]*v[j])/(2*a[j]));
		}
		sort(p+1,p+n+1);
		int ans1;
	    if(tmp1==n)//A
		{
			ans1=n;
			for(int j=1;j<=n;++j)
			    if(d[j]>p[n]||v[j]<=V)
			        ans1--;
	        printf("%d %d\n",ans1,m-1);//就留最后一个 
		}
		else if(tmp2==n)//B
		{
			ans1=n;
			for(int j=1;j<=n;++j)
			    if(d[j]+c[j]>p[n])
			       ans1--;
			printf("%d %d\n",ans1,m-1);//就留最后一个 
		}
		else
		{
			ans1=0;
			for(int j=1;j<=n;++j)
			    for(int k=1;k<=m;++k)
			        if(d[j]<=p[k]&&p[k]<d[j]+c[j])
			            ans1++;
		    int t=ans1,ans2=0;
		    for(int l=1;l<=m;++l)
		    {
		    	ans1=0;
			    for(int j=1;j<=n;++j)
			        for(int k=1;k<=m&&l!=k;++k)
			            if(d[j]<=p[k]&&p[k]<d[j]+c[j])
			                ans1++;
			    if(ans1==t) ans2++; 
		    }
			printf("%d %d\n",n-t,n-ans2);
		}
	}
    return 0;	
} 
