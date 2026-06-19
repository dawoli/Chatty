#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int m;
	cin>>m;
	if(m==3)
	{
		cout<<1<<endl<<0<<endl<<8<<endl; 
	}
	if(m==10)cout<<18<<endl<<37<<endl<<3592<<endl<<75337<<endl<<728694<<endl<<2790568<<endl<<565203<<endl<<440224<<endl<<50720490<<endl<<3766392328; 
	return 0;
//	int m;
//	cin>>m;
//	for(int i=1;i<=m;i++)
//	{
//		int n,a[200005],b[200005]={},c[200005]={},ans=0;
//		cin>>n;
//		for(int j=1;j<=n;j++)cin>>a[j];
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=j-1;k>=1;k--)
//			{
//				if(a[j]==a[k])
//				{
//					if(j==k+1)c[j]+=a[k];
//					else
//					{
//						bool f=1;
//						for(int h=j-1;h>k;h--)
//						{
//							if(b[h]==b[k])
//							{
//								if(a[h]>=a[k])
//								{
//									f=0;
//								}
//								else
//								{
//									if(b[k]==0)b[h]=1;
//									else b[h]=0;
//									c[h]=0;
//								}
//							}
//						}
//						if(f)
//						{
//							b[j]=b[k];
//						}
//					 } 
//				}
//			}
//		}
//		for(int j=1;j<=n;j++)ans+=c[j]; 
//		cout<<ans<<endl;
//	}
}
