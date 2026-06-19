#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[10001],b[10001],num,sss;
bool flag;
int colour(int s,int q)
{
	b[q]=s;
	if(q==n)
	{
		sss=0;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(b[i]==b[j]&&a[i]==a[j]&&flag==0)
				{
					sss+=a[i];
					flag=1;
				}
			}
			flag=0;
		}
	}
	else num=max(colour(1,q+1),colour(2,q+1));
	return sss;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int r=1;r<=t;r++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		num=max(colour(1,1),colour(2,1));
		cout<<num<<endl;
	}
	
	return 0;
} 
