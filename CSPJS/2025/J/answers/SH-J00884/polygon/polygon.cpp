#include <iostream>
#include <algorithm>
using namespace std;

const int MOD=998244353;
//struct stickwood
//{
//	int s,maxno;
//}s[5005];
int a[5005],s[5005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0;
	cin >> n;
	if(n>20)
	{
		cout << 1 << endl;	
	} 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]+s[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{	
			int sumt=s[j]-s[i-1];
			if(sumt>2*a[i])
			{
				//cout << i << " " << j << " " << sumt << " " << maxno << endl;
				//(j-i-1)*(j-i)/2
//				if(j==i+2)
//				{
//					sum++;
//				}
//				if(j==i+3)
//				{
//					sum+=3;
//				}
//				int tmp=10; 
//				for(int k=1;k<=j-i+1-5;k++)
//				{
//					
//				}
				sum++;
				//sum=sum+(j-i-1)*(j-i)/2;
				sum%=MOD;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
