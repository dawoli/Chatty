#include<iostream>
#include<cstdio>

using namespace std;

int n,sum,tag,temp;
int r[100005],minu[100005],book[100005] = {0};
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	sum = n;
	for (int i = 1;i <= n;i++)
	{
		cin >> r[i];
	}
	for (int i = 1;i <= n;i++)
	{
		temp = 0;
		minu[tag] = 100005;
		for (int j = 1;j <= n;j++)
		{
			if (r[j] == -1 || book[j] == 1)
			{
				continue;
			}
			minu[j] = r[j] - r[i];
			if (minu[j] >= 1 && book[j] == 0 && minu[tag] > minu[j])
			{
				tag = j;
				temp = 1;
			}
		}
		if (temp == 1)
		{
			book[tag] = 1;
			sum = sum - 1;
			r[i] = -1;
		}
	}
	cout << sum << endl;
	
	return 0;
}
