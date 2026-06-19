#include<bits/stdc++.h>

using namespace std;

int t;

long long a[100005][4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2)
		{
			int max1,max2,m,n;
			max1=max(a[1][1],max(a[1][2],a[1][3]));
			max2=max(a[2][1],max(a[2][2],a[2][3])); 
			int min1,min2;
			if(max1==a[1][1])
			{
				min1=min(max1-a[1][2],max1-a[1][3]);
				m=1;
			}
			else if(max1==a[1][2])
			{
				min1=min(max1-a[1][1],max1-a[1][3]);
				m=2;
			}
			else
			{
				min1=min(max1-a[1][2],max1-a[1][1]);
				m=3;
			}
			if(max2==a[2][1])
			{
				min2=min(max2-a[2][2],max2-a[2][3]);
				n=1;
			}
			else if(max2==a[2][2])
			{
				min2=min(max2-a[2][1],max2-a[2][3]);
				n=2;
			}
			else
			{
				min2=min(max2-a[2][2],max2-a[2][1]);
				n=3;
			}
			if(m!=n)
			{
				cout<<max1+max2<<endl;
			}
			else
			{
				if(min1==min2)
				{
					cout<<max1+max2-min1<<endl;
				}
				else if(min1<min2)
				{
					cout<<max1+max2-min1<<endl;
				}
				else
				{
					cout<<max1+max2-min2<<endl;
				}
			}
		}
		else if(n==4)
		{
			int max1,max2,max3,max4,m1,m2,m3,m4;
			max1=max(a[1][1],max(a[1][2],a[1][3]));
			max2=max(a[2][1],max(a[2][2],a[2][3]));
			max3=max(a[3][1],max(a[3][2],a[3][3]));
			max4=max(a[4][1],max(a[4][2],a[4][3]));
			int min1,min2,min3,min4;
			if(max1==a[1][1])
			{
				min1=min(max1-a[1][2],max1-a[1][3]);
				m1=1;
			}
			else if(max1==a[1][2])
			{
				min1=min(max1-a[1][1],max1-a[1][3]);
				m1=2;
			}
			else
			{
				min1=min(max1-a[1][2],max1-a[1][1]);
				m1=3;
			}
			if(max2==a[2][1])
			{
				min2=min(max2-a[2][2],max2-a[2][3]);
				m2=1;
			}
			else if(max2==a[2][2])
			{
				min2=min(max2-a[2][1],max2-a[2][3]);
				m2=2;
			}
			else
			{
				min2=min(max2-a[2][2],max2-a[2][1]);
				m2=3;
			}
			if(max3==a[3][1])
			{
				min3=min(max3-a[3][2],max3-a[3][3]);
				m3=1;
			}
			else if(max3==a[3][2])
			{
				min3=min(max3-a[3][1],max3-a[3][3]);
				m3=2;
			}
			else
			{
				min3=min(max3-a[3][2],max3-a[3][1]);
				m3=3;
			}
			if(max4==a[4][1])
			{
				min4=min(max4-a[4][2],max4-a[4][3]);
				m4=1;
			}
			else if(max4==a[4][2])
			{
				min4=min(max4-a[4][1],max4-a[4][3]);
				m4=2;
			}
			else
			{
				min4=min(max4-a[4][2],max4-a[4][1]);
				m4=3;
			}
			if((m1==m2&&m1!=m3&&m1!=m4)||(m1==m3&&m1!=m2&&m1!=m4)||(m1==m4&&m1!=m3&&m1!=m2)||(m3==m2&&m1!=m3&&m3!=m4)||(m4==m2&&m2!=m3&&m1!=m2)||(m3==m4&&m1!=m3&&m2!=m4))//2same
			{
				cout<<max1+max2+max3+max4<<endl;
			}
			else if((m1==m2&&m1==m3&&m1!=m4))//123same
			{
				int m;
				m=min(min1,min(min2,min3));
				cout<<max1+max2+max3+max4-m<<endl;
			}
			else if((m1==m2&&m1==m4&&m1!=m3))//124same
			{
				int m;
				m=min(min1,min(min2,min4));
				cout<<max1+max2+max3+max4-m<<endl;
			}
			else if((m1==m4&&m1==m3&&m1!=m2))//134same
			{
				int m;
				m=min(min1,min(min4,min3));
				cout<<max1+max2+max3+max4-m<<endl;
			}
			else if((m4==m2&&m4==m3&&m1!=m4))//234same
			{
				int m;
				m=min(min4,min(min2,min3));
				cout<<max1+max2+max3+max4-m<<endl;
			}
			else//1234same
			{
				int m,n;
				m=min(min4,min(min2,min(min3,min1)));
				if(m==min1)
				{
					n=min(min4,min(min2,min3));
					cout<<max1+max2+max3+max4-m-n<<endl;
				}
				else if(m==min2)
				{
					n=min(min4,min(min1,min3));
					cout<<max1+max2+max3+max4-m-n<<endl;
				}
				else if(m==min3)
				{
					n=min(min4,min(min2,min1));
					cout<<max1+max2+max3+max4-m-n<<endl;
				}
				else
				{
					n=min(min1,min(min2,min3));
					cout<<max1+max2+max3+max4-m-n<<endl;
				}
			}
		}
	}
	return 0;
}
