#include<bits/stdc++.h>
using namespace std;
int t;
double length,limit;
int n,m; 
int ans1;
int ans2;
struct jihes{
	double bianjieqian;
	double bianjiehou;
}jihe[11451];
int jihenum=1;
struct cars{
	double chushi;
	double chusu;
	double jiasudu;
}car[100005];
double monitor[100005];

void jisuan1()
{
	jihe[1]={-1,114514};
	cin>>n>>m>>length>>limit;
	for(int i=1;i<=n;i++)
	{
		cin>>car[i].chushi;
		cin>>car[i].chusu;
		cin>>car[i].jiasudu;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>monitor[i];
	}
	for(int i=1;i<=n;i++)
	{
		//cout<<"执行第"<<i<<"次"<<endl; 
		if(car[i].chusu>limit)
		{
		//	cout<<"初速大"<<" "<<i<<endl; 
			if(car[i].jiasudu>=0)
			{
				if(monitor[m]>=car[i].chushi)
				{
					ans1++;
					
					
					for(int j=1;j<=jihenum;j++)
					{
						int flag=false;
						if(car[i].chushi>jihe[j].bianjieqian&&car[i].chushi<jihe[j].bianjiehou||jihe[j].bianjieqian>car[i].chushi)
						{
							for(int k=1;k<=m;k++)
							{
								if(monitor[k]>=max(car[i].chushi,jihe[j].bianjieqian)&&monitor[k]<=jihe[j].bianjiehou)
								{
									jihe[j].bianjieqian=max(car[i].chushi,jihe[j].bianjieqian);
									flag=true;
									break;
								}
							}
							
						}
						if(flag==true) break;
						else if(j==jihenum)
						{
							jihenum++;
							jihe[jihenum]={car[i].chushi,114514};
							break;
						}
					}
					
				} 
				
			}
			else
			{
				double end=(car[i].chusu+limit)/2*(car[i].chusu-limit)/car[i].jiasudu*-1+car[i].chushi;
				for(int j=1;j<=m;j++)
				{
					if(monitor[j]>=car[i].chushi&&monitor[j]<end)
					{
						ans1++;
					//	cout<<"情况2"<<endl;
						
						for(int j=1;j<=jihenum;j++)
						{
							int flag=false;
							if(car[i].chushi>jihe[j].bianjieqian&&car[i].chushi<jihe[j].bianjiehou||end>jihe[j].bianjieqian&&end<jihe[j].bianjiehou||jihe[j].bianjieqian>car[i].chushi&&jihe[j].bianjieqian<end)
							{
								
								
								
								for(int k=1;k<=m;k++)
								{
									if(monitor[k]>=max(car[i].chushi,jihe[j].bianjieqian)&&monitor[k]<=jihe[j].bianjiehou)
									{
										jihe[j].bianjieqian=max(jihe[j].bianjieqian,car[i].chushi);
										
										flag=true;
										if(monitor[k]<=min(end,jihe[j].bianjiehou))
										{
											jihe[j].bianjiehou=min(jihe[j].bianjiehou,end);
											
											
										}
										break;
									}
									
								}
						
							}
							if(flag==true) break;
							else if(j==jihenum)
							{
								jihenum++;
								jihe[jihenum]={car[i].chushi,end};
								break;
							}
						}
						break;
					}
				}
			}
		}
		else if(car[i].chusu==limit&&car[i].jiasudu>0)
		{
			//cout<<"初速等"<<" "<<i<<endl; 
			if(monitor[m]>car[i].chushi)
			{
				ans1++;
			//	cout<<"情况3"<<endl;
				for(int j=1;j<=jihenum;j++)
				{	int flag=false;
					if(car[i].chushi>jihe[j].bianjieqian&&car[i].chushi<jihe[j].bianjiehou||jihe[j].bianjieqian>car[i].chushi)
					{
						
						
						for(int k=1;k<=m;k++)
						{
							if(monitor[k]>=max(car[i].chushi,jihe[j].bianjieqian)&&monitor[k]<=jihe[j].bianjiehou)
							{
								jihe[j].bianjieqian=max(car[i].chushi,jihe[j].bianjieqian);
								flag=true;
								break;
							}
						}
						
					}
					if(flag==true) break;
					else if(j==jihenum)
					{
						jihenum++;
						jihe[jihenum]={car[i].chushi,114514};
						break;
					}
				}
				
			} 
		}
		else if(car[i].chusu<limit)
		{
		//	cout<<"初速小"<<" "<<i<<endl; 
			if(car[i].jiasudu>0)
			{
				double start=(car[i].chusu+limit)/2*(car[i].chusu-limit)/car[i].jiasudu*-1+car[i].chushi;
				for(int j=1;j<=m;j++)
				{
					if(monitor[m]>=start)
					{
						ans1++;
						
						for(int j=1;j<=jihenum;j++)
						{
							int flag=false;
							if(start>jihe[j].bianjieqian&&start<jihe[j].bianjiehou||jihe[j].bianjieqian>start)
							{
								
								for(int k=1;k<=m;k++)
								{
									if(monitor[k]>=max(car[i].chushi,jihe[j].bianjieqian)&&monitor[k]<=jihe[j].bianjiehou)
									{
										jihe[j].bianjieqian=max(start,jihe[j].bianjieqian);
										flag=true;
										break;
									}
								}
			
							}
							if(flag==true) break;
							else if(j==jihenum)
							{
								jihenum++;
								jihe[jihenum]={start,114514};
								break;
							}
						}
						break;
					}
				}
			}
		}
		
	}
	cout<<ans1<<" "<<n-jihenum<<endl;
	jihenum=0;
	ans1=0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		jisuan1();
	}
		
	return 0;
}
