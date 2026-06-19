#include <cstdio>
#include <iostream>
using namespace std;
string a[53];
int a1[14] = {},a2[14] = {},a3[14] = {},a4[14] = {};
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		if (a[i][0] == 'D')
			switch(a[i][1])
			{
				case 'A': a1[1]++; break;
				case '2': a1[2]++; break;
				case '3': a1[3]++; break;
				case '4': a1[4]++; break;
				case '5': a1[5]++; break;
				case '6': a1[6]++; break;
				case '7': a1[7]++; break;
				case '8': a1[8]++; break;
				case '9': a1[9]++; break;
				case 'T': a1[10]++; break;
				case 'J': a1[11]++; break;
				case 'Q': a1[12]++; break;
				case 'K': a1[13]++; break;
			}
		else if (a[i][0] == 'C')
			switch(a[i][1])
			{
				case 'A': a2[1]++; break;
				case '2': a2[2]++; break;
				case '3': a2[3]++; break;
				case '4': a2[4]++; break;
				case '5': a2[5]++; break;
				case '6': a2[6]++; break;
				case '7': a2[7]++; break;
				case '8': a2[8]++; break;
				case '9': a2[9]++; break;
				case 'T': a2[10]++; break;
				case 'J': a2[11]++; break;
				case 'Q': a2[12]++; break;
				case 'K': a2[13]++; break;
			}
		else if (a[i][0] == 'H')
			switch(a[i][1])
			{
				case 'A': a3[1]++; break;
				case '2': a3[2]++; break;
				case '3': a3[3]++; break;
				case '4': a3[4]++; break;
				case '5': a3[5]++; break;
				case '6': a3[6]++; break;
				case '7': a3[7]++; break;
				case '8': a3[8]++; break;
				case '9': a3[9]++; break;
				case 'T': a3[10]++; break;
				case 'J': a3[11]++; break;
				case 'Q': a3[12]++; break;
				case 'K': a3[13]++; break;
			}
		else
			switch(a[i][1])
			{
				case 'A': a4[1]++; break;
				case '2': a4[2]++; break;
				case '3': a4[3]++; break;
				case '4': a4[4]++; break;
				case '5': a4[5]++; break;
				case '6': a4[6]++; break;
				case '7': a4[7]++; break;
				case '8': a4[8]++; break;
				case '9': a4[9]++; break;
				case 'T': a4[10]++; break;
				case 'J': a4[11]++; break;
				case 'Q': a4[12]++; break;
				case 'K': a4[13]++; break;
			}
	}
	int l = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (a1[i] == 0) l++;
		if (a2[i] == 0) l++;
		if (a3[i] == 0) l++;
		if (a4[i] == 0) l++;
	}
	cout << l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
