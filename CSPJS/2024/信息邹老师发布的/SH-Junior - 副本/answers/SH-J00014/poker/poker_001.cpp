#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char p[2];
	int n,x=0,y=0,cnt = 0,num = 0;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin  >> p;

		if(p[0] == 'D')
		{
			x = 0;
		}
		if(p[0] == 'H')
		{
			x = 1;
		}
		if(p[0] == 'S')
		{
			x = 2;
		}
		if(p[0] == 'C')
		{
			x = 3;
		}
		if(p[1] == 'A')
		{
			y = 1;
		}
		if(p[1] == 'T')
		{
			y = 10;
		}
		if(p[1] == 'J')
		{
			y = 11;
		}
		if(p[1] == 'Q')
		{
			y = 12;
		}
		if(p[1] == 'K')
		{
			y = 13;
		}
        if(p[1] == '2')
        {
        	y = 2;
		}
		if(p[1] == '3')
        {
        	y = 3;
		}
		if(p[1] == '4')
        {
        	y = 4;
		}
		if(p[1] == '5')
        {
        	y = 5;
		}
		if(p[1] == '6')
        {
        	y = 6;
		}
		if(p[1] == '7')
        {
        	y = 7;
		}
		if(p[1] == '8')
        {
        	y = 8;
		}
		if(p[1] == '9')
        {
        	y = 9;
		}
		cnt = x*13+y;
		a[cnt]++;
		if(a[cnt] > 1)
		{
			a[cnt] = 1;
		}
	}
	for(int i = 1;i<=52;i++)
	{
		if(a[i] == 1)
		{
			num++;
		}
	}
	cout << 52-num;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
