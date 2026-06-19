#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("detect3.in","r",stdin);
	//freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	int round;
	for(round=1;round<=t;round++)
	{
		int n,m;
		int l,v;
		cin>>n>>m>>l>>v;
		double c_list_d[n+1],c_list_v[n+1],c_list_a[n+1];
		int d[m+1];
		
		int i,j;
		for(i=1;i<=n;i++)
		{
			cin>>c_list_d[i]>>c_list_v[i]>>c_list_a[i];
		}
		for(i=1;i<=m;i++)
		{
			cin>>d[i];
		}
		//cin part
		
		
		
		if(c_list_a[1]>0)
		{
			double start[n+1];
			for(i=1;i<=n;i++)
			{
				double calculate=v*v-c_list_v[i]*c_list_v[i];
				calculate/=2;
				calculate/=c_list_a[i];
				if(c_list_a[i]>v)
				{
					start[i]=c_list_d[i]+calculate;
				}
			}
			int speed_car=0;
			for(i=1;i<=n;i++)
			{
				
				if(start[i]<d[m])
				{
					speed_car+=1;
				}
			}
			cout<<speed_car<<" ";
			if(speed_car==0)
			{
				cout<<m;
			}
			else
			{
				cout<<m-1;
			}
			cout<<endl;
		}
		else if(c_list_a[1]==0)
		{
			int start[n+1];
			for(i=1;i<=n;i++)
			{
				if(c_list_a[i]>v)
				{
					start[i]=c_list_d[i];
				}
			}
			int speed_car=0;
			int maxd=0;
			for(i=1;i<=m;i++)
			{
				if(maxd<d[i])
				{
					maxd=d[i];
				}
			}
			for(i=1;i<=n;i++)
			{
				if(start[i]<maxd)
				{
					speed_car+=1;
				}
			}
			cout<<speed_car<<" ";
			if(speed_car==0)
			{
				cout<<m;
			}
			else
			{
				cout<<m-1;
			}
			cout<<endl;
		}
		/*else
		{
			
		}*/
	}
	return 0;
}
