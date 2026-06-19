#include <bits/stdc++.h>
using namespace std;
int n, a[10005], t, num[8]= {0, -1, 1, 7, 4, 2, 6, 8};
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out","w", stdout);
	cin>>t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		int n, pos=0;
		cin >> n;
		if(n < 7)
		{
			cout << num[n]<< endl;
			continue;
		}

		while(n>=7)
		{
			a[++pos] = 8;
			n -= 7;
		}
		if(n == 0)
		{
			for(int i=1;i<=pos;i++) cout << a[i];
			cout << endl;
			continue;
		}
		
		if(n == 2)
		{
			a[1] = 1;
			a[++pos]=8;
			for(int i=1;i<=pos;i++) cout << a[i];
			cout << endl;
			continue;
		}
		if(n == 1)
		{
			if(pos ==1)
			{
				cout<< 10<< endl;
				continue;
			}
			else
			{
				a[1]=1;
				a[2]=0;
				a[++pos] = 8;
				for(int i=1;i<=pos;i++) cout << a[i];
				cout << endl;
			}
		}
	
		if(n == 6)
		{
			if(pos==1)
			{
				cout << 68<< endl;
			}
			else
			{
				a[1] = 6;
				a[++pos] = 8;
				for(int i=1;i<=pos;i++) cout << a[i];
				cout << endl;
			}
		}
		if(n==5)
		{
			a[1]=2;
			a[++pos] = 8;
			for(int i=1;i<=pos;i++) cout << a[i];
			cout << endl;
		}
		if(n == 4)
		{
			if(pos == 1)
			{
				cout<<20<<endl;
				continue;
			}
			else
			{
				a[1] = 2;
				a[2] = 0;
				a[++pos] = 8;
				for(int i=1;i<=pos;i++) cout << a[i];
				cout << endl;
			}
		}
		if(n == 3)
		{
			if(pos == 1)
			{
				cout<<22<<endl;
				continue;
			}
			else if(pos == 2)
			{
				cout<< 200 << endl;
				continue;
			}
			else
			{
				a[1] = 2;
				a[2] =a[3] = 0;
				a[++pos] = 8;
				for(int i=1;i<=pos;i++) cout << a[i];
				cout << endl;
			}
		}
	}
	return 0;
}
