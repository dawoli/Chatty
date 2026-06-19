#include<bits/stdc++.h> 
using namespace std;
int a[100005][5],bianhao[4][100005],totalppl[4],sum,n,t,maxppl,cnt,minnum,minbianhao,minn[100005],yy,xx,nn[100005],uu;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int dbe=0;dbe<t;dbe++)
	{
	
		cin>>n;
		a[100005][5]={};
		bianhao[4][100005]={};//先按照所有人都去最大的来 
		totalppl[4]={0};
		sum=0;
		for(int i=1;i<=3;i++)
		{
			totalppl[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				//cout<<a[i][1]<<" is the max"<<endl;
				//cout<<"max position: "<<1<<endl;
				totalppl[1]++;
				//cout<<"totalppl[1]: "<<totalppl[1]<<endl;
				bianhao[1][totalppl[1]]=i;
				sum+=a[i][1];
				
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				//cout<<a[i][2]<<" is the max"<<endl;
				//cout<<"max position: "<<2<<endl;
				totalppl[2]++;
				//cout<<"totalppl[2]: "<<totalppl[2]<<endl;
				bianhao[2][totalppl[2]]=i;
				sum+=a[i][2];
				
			}
			else
			{
				//cout<<a[i][3]<<" is the max"<<endl;
				//cout<<"max position: "<<3<<endl;
				totalppl[3]++;
				//cout<<"totalppl[3]: "<<totalppl[3]<<endl;
				bianhao[3][totalppl[3]]=i;
				sum+=a[i][3];
				
			}
		}//此时sum是每一个人选的最优 
		
		/*for(int i=1;i<=3;i++)
		{
			cout<<"Group "<<i<<": "; 
			for(int j=1;j<=totalppl[i];j++)
			{
				cout<<bianhao[i][j]<<" "; 
			}
			cout<<" totalppl: "<<totalppl[i];
			cout<<endl;
		}*/
		maxppl=n/2;
		for(int i=1;i<=3;i++)
		{
			int qq,ww;
			if(i==1)
			{
				qq=2;
				ww=3;
			}
			if(i==2)
			{
				qq=3;
				ww=1;
			}
			if(i==3)
			{
				qq=1;
				ww=2;
			}
			if(totalppl[i]>maxppl)
			{
				cnt=0;
				minnum=200005;
				minbianhao=0;
				minn[100005];
				//bianhao[i][j]为当前在这个组里面的人的编号 
				for(int j=1;j<=totalppl[i];j++)
				{
					if(cnt<maxppl) 
					{
						cnt++;
						minn[cnt]=a[bianhao[i][j]][i];
						sort(minn,minn+cnt);
						//cout<<"最大: "<<minn[cnt]<<endl;
					}
					else
					{
						if(a[bianhao[i][j]][i]>minn[1])
						{
							minn[1]=a[bianhao[i][j]][i];
							sort(minn,minn+cnt);
							//cout<<"最大: "<<minn[cnt]<<endl;
						}
					}//minn[1]为最小可以进的数字 
				}
				//cout<<"cnt: "<<cnt<<endl;
				yy=totalppl[i];
				for(int j=1;j<=totalppl[i];j++)
				{
					if(a[bianhao[i][j]][i]<minn[1])
					{
						yy--;
						
						if(a[bianhao[i][j]][qq]>a[bianhao[i][j]][ww]&&totalppl[qq]<maxppl)
						{
							totalppl[qq]++;
							sum-=a[bianhao[i][j]][i];
							sum+=a[bianhao[i][j]][qq];
							bianhao[qq][totalppl[qq]]=bianhao[i][j];
						}
						else
						{
							totalppl[ww]++;
							sum-=a[bianhao[i][j]][i];
							sum+=a[bianhao[i][j]][ww];
							bianhao[ww][totalppl[ww]]=bianhao[i][j];
						}
					}
				 } 
				if(yy>maxppl)
				{
					xx=yy-maxppl;
					nn[100005]={};
					uu=0;
					for(int j=0;j<totalppl[i];j++)
					{
						if(a[bianhao[i][j]][i]==minn[0])
						{
							if(uu<xx)
							{
								nn[uu]=max(a[bianhao[i][j]][qq],a[bianhao[i][j]][ww]);
								uu++;
								sort(nn,nn+uu);
							}
							else if(max(a[bianhao[i][j]][qq],a[bianhao[i][j]][ww])>nn[0])
							{
								nn[0]=max(a[bianhao[i][j]][qq],a[bianhao[i][j]][ww]);
								sort(nn,nn+uu);
							}
						}//nn[0]存最小可以进
					}
					for(int j=0;j<totalppl[i];j++)
					{
						if(max(a[bianhao[i][j]][qq],a[bianhao[i][j]][ww])<nn[0])
						{
							xx--;
							if(a[bianhao[i][j]][qq]>a[bianhao[i][j]][ww]&&totalppl[qq]<maxppl)
							{
								totalppl[qq]++;
								sum-=a[bianhao[i][j]][i];
								sum+=a[bianhao[i][j]][qq];
								bianhao[qq][totalppl[qq]]=bianhao[i][j];
							}
							else
							{
								totalppl[ww]++;
								sum-=a[bianhao[i][j]][i];
								sum+=a[bianhao[i][j]][ww];
								bianhao[ww][totalppl[ww]]=bianhao[i][j];
							}
						}
					}
					if(xx>0)
					{
						for(int j=0;j<totalppl[i];j++)
						{
							if(max(a[bianhao[i][j]][qq],a[bianhao[i][j]][ww])==nn[0])
							{
								xx--;
								if(a[bianhao[i][j]][qq]>a[bianhao[i][j]][ww]&&totalppl[qq]<maxppl)
								{
									totalppl[qq]++;
									sum-=a[bianhao[i][j]][i];
									sum+=a[bianhao[i][j]][qq];
									bianhao[qq][totalppl[qq]]=bianhao[i][j];
								}
								else
								{
									totalppl[ww]++;
									sum-=a[bianhao[i][j]][i];
									sum+=a[bianhao[i][j]][ww];
									bianhao[ww][totalppl[ww]]=bianhao[i][j];
								}
							}
							if(xx==0)
							{
								break;
							}
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
}
