#include<iostream>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin >> n;
		int e=0;
		while(n>=14)
		{
			n-=7;
			e++;
		}
		if(n==7)
		{
			cout << "8";
		}
		if(n==8)
		{
			cout << "10";
		}
		if(n==9)
		{
			cout << "18";
		}
		if(n==10)
		{
			cout << "22";
		}
		if(n==11)
		{
			cout << "20";
		}
		if(n==12)
		{
			cout << "28";
		}
		if(n==13)
		{
			cout << "68";
		}
		if(n==1)
		{
			cout << "-1";
		}
		if(n==2)
		{
			cout << "1";
		}
		if(n==3)
		{
			cout << "7";
		}
		if(n==4)
		{
			cout << "4";
		}
		if(n==5)
		{
			cout << "2";
		}
		if(n==6)
		{
			cout << "6";
		}
		for(int i=0;i<e;i++)
		{
			cout << "8";
		}
	}
	return 0;
}
