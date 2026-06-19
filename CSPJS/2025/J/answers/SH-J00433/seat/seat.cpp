#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sc[120];
int seat[15][15];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int sc1;
	cin >> sc1;
	sc[1] = sc1;
	int t = 0;
	for(int i = 2 ; i <= n*m ; i++) cin >> sc[i];
	sort(sc+1,sc+1+n*m,cmp);
	for(int i = 1 ; i <= n*m ; i++)
	{
		if(sc[i] == sc1)
		{
			t = i;
			break;
		}
	}
	int c = 0, r = 0;
	if(t % n == 0)
	{
		r = t/n;
		if((t/n) % 2 == 0) c = 1;
		else if((t/n) % 2 == 1) c = n;
	}
	else if((t-1) % n == 0)
	{
		r = t/n + 1;
		if(((t-1) / n) % 2 == 0) c = 1;
		else if(((t-1) / n) % 2 == 1) c = n;
	}
	else
	{
		r = t/n + 1;
		if(r % 2 == 0)
		{
			c = n-(t%n)+1;
		}
		else
		{
			c = t%n;
		}
	}
	cout << r << " " << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

