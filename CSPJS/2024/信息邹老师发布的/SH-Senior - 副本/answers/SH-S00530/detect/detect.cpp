#include<bits/stdc++.h>
using namespace std;
int zu,n,m,l,v,zongshu,ga,lai,qu,jianceyi;
float t,sbian,s;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>zu>>n>>m>>l>>v;
	int di[n],vi[n],ai[n],pm[m];
	int silela[n][m],aa[n],gongju[n][2];
	for(int siba=0;siba<zu;siba++)
	{
		for(int i=0;i<n;i++)
	{
		cin>>di[i]>>vi[i]>>ai[i];
		aa[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>pm[i];
	}
	for(int i=0;i<n;i++)
	{
		if(ai[i]==0)
		{
			if(vi[i]>v)
			{
				if(di[i]<=pm[m-1])
				{
					zongshu=zongshu+1;
					for(int wu=m-1;wu>=0;wu--)
					{
						if(pm[wu]>=di[i]) silela[i][wu]=1;
						else silela[i][wu]=0;
					}
				}
			}
		}
		else
		{
			if(ai[i]>0)
			{
				if(vi[i]>v)
				{
					if(di[i]<=pm[m-1])
					{
						zongshu=zongshu+1;
						for(int wu=m-1;wu>=0;wu--)
						{
							if(pm[wu]>=di[i]) silela[i][wu]=1;
							else silela[i][wu]=0;
						}
					}
				}
				if(vi[i]==v)
				{
					if(di[i]<pm[m-1])
					{
						zongshu=zongshu+1;
						for(int wu=m-1;wu>=0;wu--)
						{
							if(pm[wu]>di[i]) silela[i][wu]=1;
							else silela[i][wu]=0;
						}
					}
				}
				if(vi[i]<v)
				{
					t=(v*1.0000-vi[i]*1.0000)/ai[i];
					sbian=v*1.0000*t+0.5*ai[i]*1.0000*t*t;
					s=di[i]*1.0000+sbian;
					if(s<pm[m-1]*1.0000)
					{
						zongshu=zongshu+1;
						for(int wu=m-1;wu>=0;wu--)
						{
							if(pm[wu]*1.0000>s) silela[i][wu]=1;
							else silela[i][wu]=0;
						}
					} 
				}
			}
			else
			{
				if(vi[i]>v)
				{
					t=0-(vi[i]*1.0000-v*1.0000)/ai[i];
					sbian=v*1.0000*t+0.5*ai[i]*1.0000*t*t;
					for(int j=0;j<m;j++)
					{
						if(di[i]*1.0000<=pm[j]*1.0000&&pm[j]*1.0000<di[i]*1.0000+sbian)
						{
							ga=1;
							silela[i][j]=1;
						}
						else silela[i][j]=0;
					}
					if(ga==1) zongshu=zongshu+1;
					ga=0;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(silela[i][j]=1) aa[i]=aa[i]+1;
		}
		gongju[i][0]=i;
		gongju[i][1]=aa[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(gongju[i][1]<gongju[j][1])
			{
				lai=gongju[i][0];
				qu=gongju[i][1];
				gongju[i][0]=gongju[j][0];
				gongju[i][1]=gongju[j][1];
				gongju[j][0]=lai;
				gongju[j][1]=qu;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(gongju[i][1]==0)
		jianceyi=jianceyi+1;
	}
	cout<<zongshu<<" "<<jianceyi<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
