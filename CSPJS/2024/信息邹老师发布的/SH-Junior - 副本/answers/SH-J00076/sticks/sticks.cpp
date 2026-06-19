#include <bits/stdc++.h>
using namespace std;

int nb[10]={6,2,5,5,4,5,6,3,7,6};
int nm[7]={8,10,18,23,20,28,68};

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		cin >> x;
		if(x<2) cout << -1;
		else if(x%7==0)
		{
			int c=x/7;
			for(int i=1;i<=c;i++)
			{
				cout << 8;
			}
		}
		else if(x%7==1)
		{
			int c=x/7-1;
			cout << 10;
			for(int i=1;i<=c;i++)
			{
				cout << 8;
			}
		}
		else if(x<=20)
		{
			int m=1;
			while(1)
			{
				int cnt=0;
				int k=m;
				while(k>0)
				{
					cnt+=nb[k%10];
					k/=10;
				}
				if(cnt==x)
				{
					cout << m;
					break;
				}
				m++;
			}
		}
		else if(x>20)
		{
			int q=x%7;
			int c=x/7-1;
			cout << nm[q];
			for(int i=1;i<=c;i++)
			{
				cout << 8;
			}
		}
		cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
