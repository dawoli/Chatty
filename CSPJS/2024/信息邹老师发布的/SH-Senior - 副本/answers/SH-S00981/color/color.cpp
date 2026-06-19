#include<bits/stdc++.h>
using namespace std;
int t,n,m,fla,flag1,sum=0;
int a[400010],ji[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=0;
	cin>>t;
	while(t--)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		a[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
		cin>>a[i];
		ji[a[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(ji[i]!=0&&fla==0)
			fla=ji[i];
			if(ji[i]!=0&&ji[i]!=fla) 
			flag1=1;
		} 
		if(flag1==0&&fla==1)
			cout<<0<<endl;
			/*
		else
		{
		for(int i=2;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]==a[j])
				{
					sum+=a[i];
					break;
				}
			}
		}
		cout<<sum<<endl;
		}
		*/
		else
		{
			for(int i=1;i<=n;i++)
			a[i+n]=a[i];
			for(int i=1;i<=n*2;i++)
			cout<<a[i]<<" ";
		}
	}
	
	return 0;
}
