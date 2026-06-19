#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
int main()
{
	freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
	cin >> n >> m;              
	for (int i = 1;i <= 100; i++)
    {
    	cin >> a[i];
    	if(a[i]= n*m - i + 1)
		{
			if (a[i]=i) 
    		{	
    			if (m%2==1)
    			{
    				cout << m << " " << n;
    				return 0;
				}
				if(m%2 ==0)
				{
					cout << m << " " << "1";
					return 0;
				}
			}
			else
			{
				cout << "1" << " " << "1" ;
				return 0;
			}
		}
		else
		{
			cout << "1" << " " << "2";
			return 0;
		}
	}
}















 
