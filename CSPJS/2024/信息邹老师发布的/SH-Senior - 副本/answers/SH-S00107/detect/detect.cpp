#include<iostream>
using namespace std;
struct car
{
	int d,v,a;
};
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,l,v;
		cin>>n>>m>>l>>v;
		car c[n];
		int p[m];
		int pp[m];
		int fail=n;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i].a==0&&c[i].v<=v)
			{
				n-=1;
				continue;
			}
			else
			{
				int s=(v*v-c[i].v*c[i].v)/2*c[i].a;
				for(int j=1;j<=m;j++)
				{
					if(s+c[i].d<p[j+1]&&c[i].d>p[j])
					{
						n-=1;
						continue;
					}
					else
					{
						if(c[i].a>0)
						{
							for(int k=1;k<=m;k++)
							{
								if(p[k]>s+c[i].d)
								{
									pp[k]++;
								}
							}
						}
						if(c[i].a<0)
						{
							for(int k=1;k<=m;k++)
							{
								if(p[k]>c[i].d&&p[k]<=c[i].d+s)
								{
									pp[k]+=1;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			int min=i;
			for(int j=i;j<=m;j++)
			{
				if(pp[min]>pp[j])
				{
					min=j;
				}
			}
			swap(pp[min],pp[i]);
		}
		int flag=0;
		int max=pp[m];
		for(int i=1;i<=m;i++)
		{
			if(pp[i]!=max)
			{
				flag++;
			}
		}
		cout<<n<<" "<<flag<<endl;
	}
	return 0;
}
