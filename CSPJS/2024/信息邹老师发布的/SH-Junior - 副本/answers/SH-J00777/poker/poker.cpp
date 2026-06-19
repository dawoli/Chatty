#include <bits/stdc++.h>
using namespace std;
int gt(string s1)
{
	if(s1[1] == 'A')return 1;
	if(s1[1] == 'T')return 10;
	if(s1[1] == 'J')return 11;
	if(s1[1] == 'Q')return 12;
	if(s1[1] == 'K')return 13;
	else return s1[1] - '0';
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n, flg = 0;
	cin >> n;
	bool poker[53] = {0};
	string pok;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> pok;
		if(pok[0] == 'C')
		{
			if(poker[gt(pok)] == 0)
			{
				poker[gt(pok)] = 1;
				flg ++;
			}else continue;
		}else if(pok[0] == 'S')
		{
			if(poker[gt(pok) + 13] == 0)
			{
				poker[gt(pok) + 13] = 1;
				flg ++;
			}else continue;
		}else if(pok[0] == 'H')
		{
			if(poker[gt(pok) + 26] == 0)
			{
				poker[gt(pok) + 26] = 1;
				flg ++;
			}else continue;
		}else
		{
			if(poker[gt(pok) + 39] == 0)
			{
				poker[gt(pok) + 39] = 1;
				flg ++;
			}else continue;
		}
	}
	cout << 52 - flg;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
