#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n); // smaller length, smaller size 
		if(n < 7)
		{
			switch(n)
			{
				case 1:
				{
					puts("-1");
					break;
				}
				case 2:
				{
					puts("1");
					break;
				}
				case 3:
				{
					puts("7");
					break;
				}
				case 4:
				{
					puts("4");
					break;
				}
				case 5:
				{
					puts("2");
					break;
				}
				case 6:
				{
					puts("6");
					break;
				}
				default:
				{
					 puts("roammer AK CSP-J/S, NOIP, CTSC, APIO, CCPC, ICPC, IOI");
					 break;
				}
			}
		}
		else
		{
			switch(n % 7)
			{
				case 0:
				{
					for(int i = 1; i <= n / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 1:
				{
					putchar('1');
					putchar('6');
					for(int i = 1; i <= (n - 8) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 2:
				{
					putchar('1');
					for(int i = 1; i <= (n - 2) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 3:
				{
					putchar('2');
					putchar('2');
					for(int i = 1; i <= (n - 10) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 4:
				{
					putchar('2');
					putchar('0');
					for(int i = 1; i <= (n - 11) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 5:
				{
					putchar('2');
					for(int i = 1; i <= (n - 5) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				case 6:
				{
					putchar('6');
					for(int i = 1; i <= (n - 6) / 7; i++)
					{
						putchar('8');
					}
					puts("");
					break;
				}
				default:
				{
					puts("roammer AK CSP-J/S, NOIP, CTSC, APIO, CCPC, ICPC, IOI");
					break;
				}
			}
		}
	}
	return 0;
}
