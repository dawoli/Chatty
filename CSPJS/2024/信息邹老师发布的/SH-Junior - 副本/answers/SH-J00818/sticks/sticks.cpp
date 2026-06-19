#include <bits/stdc++.h>
using namespace std;
int a[] = {6,2,5,5,4,5,6,3,7,6};
const int N = 1e5 + 10;
int n,b[] = {0,0,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888,1088,1888,2008,2088,2888,6888,8888};
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n % 7 == 1 && n >= 15)
		{
			cout << 10;
			for(int i = 1;i < n / 7;i++)
				cout << 8;
			puts("");
		}
		else if(n % 7 == 0)
		{
			for(int i = 1;i <= n / 7;i++)
				cout << 8;
			puts("");
		}
		else
		{
			if(n == 1)	puts("-1");
			else
			{
//				if(n <= 8)
//					if(n == 2)	puts("1");
//					else if(n == 3)	puts("7");
//					else if(n == 4)	puts("4");
//					else if(n == 5)	puts("2");
//					else if(n == 6)	puts("6");
//					else if(n == 7)	puts("8");
//					else	puts("10");
//				else
//				{
//					if(n % 7 == 2)	printf("18");
//					else if(n % 7 == 3)	printf("23");
//					else if(n % 7 == 4)	printf("20");
//					else if(n % 7 == 5)	printf("28");
//					else	printf("68");
//					for(int i = 1;i < n / 7;i++)
//						putchar('8');
//					puts("");
//				}
				if(n <= 28)	cout << b[n] << endl;
				else
				{
					int t = n;
					t %= 7;
					while(t + 7 <= 28)	t += 7;
					cout << b[t];
					for(int i = 1;i <= (n - t) / 7;i++)
						putchar('8');
					puts("");
				}
			}
		}
	}
	return 0;
}

