#include<bits/stdc++.h>
using namespace std;
int n,m,ansn=0,ma[100005]={0};
void f(int *x,int *y,int *z,int ans,int x2,int y2,int z2,int i)
{
	if(i>=m)
	{
		if(ans>ansn)
		{
			ansn=ans;
			return;
		}
	}
	if(ans<ma[i]/3)
	{
		return;
	}
	if(ans>ma[i])
	{
		ma[i]=ans;
	}
	if(x2<m/2)f(x,y,z,ans+x[i],x2+1,y2,z2,i+1);
	if(y2<m/2)f(x,y,z,ans+y[i],x2,y2+1,z2,i+1);
	if(z2<m/2)f(x,y,z,ans+z[i],x2,y2,z2+1,i+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		/*short*/int x[100005]={0},y[100005]={0},z[100005]={0}/*,x2[100005]={0},y2[100005]={0},z2[100005]={0}*/;
		short r[100005]={0};
		int ans=0;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			//x2[i]=x[i];y2[i]=y[i];z2[i]=z[i];
			
		}
		f(x,y,z,0,0,0,0,0);
		/*
		sort(x2,x2+m);
		sort(y2,y2+m);
		sort(z2,z2+m);
		for(int i=0,v=0;i<m;i++)
		{
			if(x[i]>=x2[m/2]&&v<=m/2)
			{
				ans+=x[i];
				v++;
				r[i]=1;
			}
		}
		for(int i=0,v=0;i<m;i++)
		{
			if(y[i]>=y2[m/2]&&v<=m/2)
			{
				if(r[i])
				{
					if(y[i]-x[i]>0)
					{
						ans+=y[i]-x[i];
						v++;
					}
				}
				else
				{
					r[i]=1;
					ans+=y[i]-x[i];
						v++;
				}
				
			}
		}
		for(int i=0,v=0;i<m;i++)
		{
			if(z[i]>=z2[m/2]&&v<=m/2)
			{
				if(r[i])
				{
					if(z[i]-max(x[i],y[i])>0)
					{
						ans+=z[i]-max(x[i],y[i]);
						v++;
					}
				}
				else
				{
					r[i]=1;
					ans+=y[i]-x[i];
						v++;
				}
				
			}
		}/*
		for(int q=m-1,w=m-1,e=m-1,k=0;k<m;k++)
		{
			if(q+1==m/2){q=m;}
			if(w+1==m/2){w=m;}
			if(e+1==m/2){e=m;}
			if(x[q]>=y[w]&&x[q]>=z[e]){ans+=x[q];y[q]=z[q]=0;q--;}
			else if(y[w]>=x[q]&&y[w]>=z[e]){ans+=y[w];x[w]=z[w]=0;w--;}
			else{ans+=z[e];y[e]=x[e]=0;e--;}
		}*/
		printf("%d\n",ansn);
		ansn=0;
		for(int i=0;i<m;i++)
		{
			if(ma[i])
			{
				ma[i]=0;
			}
		}
	}
	return 0;
} 
