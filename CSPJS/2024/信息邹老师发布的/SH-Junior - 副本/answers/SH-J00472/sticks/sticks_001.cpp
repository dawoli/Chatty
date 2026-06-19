#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int main ()
{
	freopen ("sticks.in","r",stdin);
	freopen ("sticks.out","w",stdout);
	int T,n,sum=0,m=0;
	cin>>T;
	while(T)
	{
		cin>>n;
		if (n<2)
		{
			cout << "-1" <<endl;
		}
		else if (n%7==0)
		{
			n/=7;
			for (int i=0;i<n;i++)
			{
				sum+=8*pow(10,i);
				cout<<sum<<endl;	
			}
		}
		else 
		{
			n=n%7;
			m=n/7;
			for (int i=1;i<10;i++)
			{
				if (n==s[i])
				{
					for (int j=0;j<m;j++)
					{
						sum+=8*pow(10,j);
					}
					sum+=s[i]*pow(10,m);
					break;
				}
			}
			cout<<sum<<"\n";
		}
		T--;	
	} 
	fclose (stdin);
	fclose (stdout);
	return 0;
}
