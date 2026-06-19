#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int n;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int flag[N]={0};
		int road[N]={0};
		long long number_of_cars=0,number_of_machines=0,road_length=0,limit=0,position=0,begin_speed=0,acceleration[N]={0},machine_position=0,ans=0,cnt=0,acceleration1=0; 
		cin>>number_of_cars>>number_of_machines>>road_length>>limit;
		for(int i=0;i<number_of_cars;i++)
		{
			cin>>position>>begin_speed>>acceleration1;
			road[position]=begin_speed;
			acceleration[position]=acceleration1;
		}
		for(int i=0;i<number_of_machines;i++)
		{
			cin>>machine_position;
			flag[machine_position-1]=1;
		}
		for(int i=0;i<road_length;i++)
		{
			if(road[i]!=0)
			{
				for(int j=0;i<road_length;i++)
				{
					road[i+road[i]*j+acceleration[i]*j*j/2]=sqrt(road[i]*road[i]+2*acceleration[i]*(road[i]*j+acceleration[i]*j*j/2));
					if(i<=(i+road[i]*j+acceleration[i]*j*j/2)&&road[i+road[i]*j+acceleration[i]*j*j/2]>limit)
					{
						ans++;
						for(int k=i;k>=0;k--)
						{
							if(flag[i]==1)
							{
								flag[i]++;
							}
						}
					}
				}
			}
		}
		for(int i=0;i<road_length;i++)
		{
			if(flag[i]!=0&&flag[i]==1)
			{
				cnt++;
			}
		}	
		cout<<ans<<" "<<cnt-2<<endl;
	}
	return 0;
}

