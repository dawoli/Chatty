#include <iostream>
#include <cstdio>
using namespace std;
int a[10010];
int b[10010];
int c[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int jla,jlb,jlc;
	int s=0;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		int aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++)
		{
			int ma=0,mb=0,mc=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>ma)
				{
					ma=a[i];
					jla=i;
				}
				if(b[i]>mb)
				{
					mb=b[i];jlb=i;
				}
				if(c[i]>mc)
				{
					mc=c[i];jlc=i;
				}
			}
			if(jla=jlb&&jla==jlc)
			{
	
				if(a[jla]>b[jla]&&a[jla]>c[jla])
				{
					if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
				 } 
				 else if(b[jla]>c[jla])
				 {
				 	if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}	
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
				
				 }
				 else
				 {
				 	if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					} 
				 }
			}
			else if(jla=jlb)
			{
				if(a[jla]>b[jlb])
				{
					if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
				}
				else
				{
					if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
				}
			}else if(jla=jlc)
			{
				if(a[jla]>c[jla])
				{
					if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					
				}
				else
				{
					if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
				}
			}
			else if(jlc=jlb)
			{
				if(c[jla]>b[jla])
				{
					if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
				}
				else
				{
					
					if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
				}
			}
			else{
				if(a[jla]>b[jla]&&a[jla]>c[jla])
				{
					if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
					else if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
				 } 
				 else if(b[jla]>c[jla])
				 {
				 	
					if(bb<n/2)
					{
						s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
					}
					else if(cc<n/2)
					{
						s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
					}
					else if(aa<n/2)
					{
						s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
					}
				 }
				 else
				 {
				 	if(a[jla]>b[jla])
				 	{
				 		if(cc<n/2)
						{
							s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
						}
						else if(aa<n/2)
						{
							s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
						}
						else if(bb<n/2)
						{
							s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
						}
						
					 }
					 else
					 {
					 	if(cc<n/2)
						{
							s+=c[jla];a[jla]=0;b[jla]=0;c[jla]=0;cc++;
						}
						else if(bb<n/2)
						{
							s+=b[jla];a[jla]=0;b[jla]=0;c[jla]=0;bb++;
						}
						else if(aa<n/2)
						{
							s+=a[jla];aa++;a[jla]=0;b[jla]=0;c[jla]=0;
						}
					 }
				 }
			}
		}
		cout<<s;
	}
	return 0;
}
