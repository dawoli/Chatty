#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool box[5][15];

int turn1 (char co)
{
	if (co == 'D')	return 1;
	if (co == 'C')	return 2;
	if (co == 'H')	return 3;
	if (co == 'S')	return 4;
}

int turn2 (char num)
{
	if ('2' <= num && num <= '9')	return num - '0';
	if (num == 'A')	return 1;
	if (num == 'T')	return 10;
	if (num == 'J')	return 11;
	if (num == 'Q')	return 12;
	if (num == 'K')	return 13;
}

int main()
{
	freopen ("poker.in", "r", stdin);
	freopen ("poker.out", "w", stdout);
	cin >> n;//输入卡牌个数 
	for (int i = 1; i <= n; i++)
	{
		char co, num;// co 是花色, num 是点数 
		cin >> co >> num;
		box[turn1(co)][turn2(num)] = true;//标记为拥有 
	}
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			if (!box[i][j])	ans++;// 如果没有就要去借 
	cout << ans;
	return 0;
}

// 1. 08:48 可以过所有样例 
// 2. 10:10 完成简单注释标记 
