#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node
{
	double d,vc,a;
	int flag;
}arr[100005];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,l,v,cnt=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].d>>arr[i].vc>>arr[i].a;
			if(arr[i].vc<=v&&arr[i].a<=0) arr[i].flag=1;
			else if(arr[i].vc<=v&&arr[i].a>0) arr[i].flag=2;
			else if(arr[i].vc>=v&&arr[i].a<0) arr[i].flag=3;
			else if(arr[i].vc>=v&&arr[i].a>=0) arr[i].flag=4;
		}
		int p[100005]={};
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		double d2[100005]={};
		int pp[100005]={};
		for(int i=1;i<=n;i++)
		{
			if(arr[i].flag==2||arr[i].flag==3)
			{
				d2[i]=(9-arr[i].vc*arr[i].vc)/(2*arr[i].a);
				cout<<d2[i]<<endl;
				for(int j=1;j<=m;j++)
				{
					if(arr[i].flag==2)
					{
						if(p[j]>=arr[i].d+d2[i])
						{
							cnt++;
							//cout<<i<<endl;
							pp[j]++;
							break;
						}
					}
					else
					{
						if(p[j]>=arr[i].d&&p[j]<=arr[i].d+d2[i])
						{
							cnt++;
							//cout<<i<<endl;
							pp[j]++;
							break;
						}
					}
				}
			}
			else if(arr[i].flag==4) 
			{
				cnt++;
				//cout<<i<<endl;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
} 

//1 4 2 3 3
