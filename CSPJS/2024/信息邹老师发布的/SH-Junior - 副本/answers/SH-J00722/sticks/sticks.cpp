#include<bits/stdc++.h>
using namespace std;

int T,n,a[50]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,202,200,208,288,808};

int main()
{
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n<=20) cout << a[n]<<endl;
		else
		{
			int w=ceil(n*1.0/7);		//Î»Êý
			 cout << w;
		}
	}
	
	return 0;
}
