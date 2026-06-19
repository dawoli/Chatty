#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int g;
	cin>>g;
	for(int i=0;i<g;i++)
	{
		int ans=0;//chao che shu
		double n,m,L,V;
		int road[100010];
		cin>>n>>m>>L>>V;
		//cout<<n<<m<<L<<V;
		double d,v,a;
		for(int k=0;k<L;k++)
		{
			road[i]=0;
		}
		for(int p=0;p<n;p++)
		{
			//double d,v,a;
			cin>>d>>v>>a;
			
			if(a==0)
			{
				if(v>V)
				{
					ans++;
					for(int j=d-1;j<L;j++)
					{
						road[j]++;
					}
				}	
			}
			if(a>0)
			{
				if(sqrt(v*v+(2*a*L))>0)
				{
					double S=(v*(V-v))/a+((V-v)*(V-v)/2*a)+d;
					if(S<=L)
					{
						ans++;
						for(int j=int(S);j<L;j++)
						{
							road[j]++;
						}
					}
				}
			}
			if(a<0)
			{
				if(v>V)
				{
					double S=(V*V-v*v)/(2*a)+d;
					ans++;
					if(S>L)
					{
						for(int j=d-1;j<L;j++)
						{
							road[j]++;
						}
						for(int j=d;int(S);j++)
						{
							road[j]++;
						}
					}
				}
			}
		}
		cout<<ans<<" ";
		int cameras[100010];
		int ans1=0;
		for(int q=0;q<m;q++)
		{
			cin>>cameras[q];
			if(road[cameras[q]]==0)
			{
				ans1++;	
			}
		}
		cout<<ans1<<endl;
		
	}
	return 0;
}
