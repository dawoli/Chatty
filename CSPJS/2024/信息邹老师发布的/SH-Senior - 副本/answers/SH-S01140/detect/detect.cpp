#include<bits/stdc++.h>
using namespace std;
double speed(int m,int d,int v,int a)
{
	int tmp=m-d;
	if(v*v+2*a*tmp<0) return -1;
	return sqrt(v*v+2*a*tmp);
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int useful[100005];
	memset(useful,0,sizeof(useful));
	int T;
	int max,fl;
	scanf("%d",&T);
	int n,m,V,L;//n车数 m检测仪数 V限速 L路长 
	int d[100005],v[100005],a[100005],moni[100005];
	for(int k=0;k<T;k++)
	{
		int ans=0;
		scanf("%d %d %d %d",&n,&m,&L,&V);
		for(int i=0;i<n;i++) scanf("%d %d %d",&d[i],&v[i],&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&moni[i]);
		sort(moni,moni+m);
		for(int i=0;i<n;i++)
		{
			if(d[i]>moni[m-1]) continue;
			int tmp=-1;
			for(int j=m-1;j>0;j--)
			{
				if(moni[j]<d[i]) break; 
				tmp=j;
			}
			if(a[i]>0) 
			{
				if(v[i]>V) 
				{
					ans++;
					max=-1;
					
					for(int j=tmp;j<m;j++) if(useful[j]>max) 
					{
						max=useful[j];
						fl=j;
					}
					useful[fl]++;
				}
				else if(speed(moni[m-1],d[i],v[i],a[i])>V)
				{
					ans++;
					useful[m-1]=1;
					max=-1;
					for(int j=tmp;j<m;j++) if(useful[j]>max) 
					{
						max=useful[j];
						fl=j;
					}
					useful[fl]++;
				}
			}
			else if(a[i]<0)
			{
				if(v[i]>V)
				{
					int tmp2=0;
					for(int j=m-1;j>0;j--)
					{
						if(speed(moni[j],d[i],v[i],a[i])>V) break;
						tmp2=j;
					}
					if(speed(moni[tmp],d[i],v[i],a[i])>V)
					{
						ans++;
						useful[tmp]=1;
						max=-1;
						for(int j=tmp;j<tmp2;j++) if(useful[j]>max) 
						{
							max=useful[j];
							fl=j;
						}
					useful[fl]++;
					} 
				}
			}
			else if(a[i]==0&&v[i]>V) 
			{
				ans++;
				max=-1;
				for(int j=tmp;j<m;j++) if(useful[j]>max) 
					{
						max=useful[j];
						fl=j;
					}
					useful[fl]++;
			}
		}
		int ans2=0;
		for(int i=0;i<m;i++) 
			if(useful[i]==0) ans2++;
		cout<<ans<<" "<<ans2<<endl;
	}
	return 0;
}
