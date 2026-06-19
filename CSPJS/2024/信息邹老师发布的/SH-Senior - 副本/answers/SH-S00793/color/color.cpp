#include<bits/stdc++.h>
using namespace std;
long long T;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T>0)
	{
		int n;
		
		int a[100009]={0};
		
		int len0=0,len1=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int maxans=0;
		for(long long i=0;i<=pow(2,n);i++)
		{
			//cout<<"tag0";
			int num[100009]={0},m0[100009]={0},m1[100009]={0};//m0 m1 -> 1
			long long q=i;
			int ta=n;
			while(ta>=0)
			{
				if(q>=pow(2,ta))
				{
					q-=pow(2,ta);
					num[ta]=1;
				}
				ta--;
			}
			//cout<<"tag1";
			for(int j=0;j<n;j++)
			{
				if(num[j]==0)
				{
					m0[len0]=a[j];
					len0++;
				}
				else
				{
					m1[len1]=a[j];
					len1++;
				}
			}
			//cout<<"tag2";
			int ans=0;
			for(int j=0;j<=len0;j++)
			{
				if(m0[j]==m0[j+1])
					ans+=m0[j];					
			}
			for(int j=0;j<=len1;j++)
			{
				if(m1[j]==m1[j+1])
					ans+=m1[j];					
			}
			//cout<<ans<<endl;
			maxans=max(maxans,ans);
			//cout<<"tag3";
		}
		cout<<maxans<<endl;
		
		
		T--;
	}
	return 0;
}
