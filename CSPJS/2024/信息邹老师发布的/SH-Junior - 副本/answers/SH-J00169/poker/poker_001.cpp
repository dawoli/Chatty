#include <iostream>
using namespace std;
string pokers[55]; string cP; int num=0, isContained = 0, n=0;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int j=1; j<=n; j++)
	{
	cin >> cP;
	if (num == 0)
	{
		pokers[1] = cP;
		num = 1;
	}
	else
	{
		for (int i=1; i<=num; i++)
		{
			if (pokers[i]==cP)
			{
				isContained = 1;
				break;
			}
		}
		if (!isContained)
		{
			pokers[num+1] = cP;
			num++;
		}
	}
	isContained = 0;
	}	
	cout << 52 - num;
	return 0;
} 
