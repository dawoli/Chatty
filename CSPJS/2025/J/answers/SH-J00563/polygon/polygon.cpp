#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int N = 5010;

int n;
int sticks[N];
bool mark[N];
long long cnt = 0;

void dbg(vector<int> v)
{
	for (const int &i : v)
		cout << i << " ";
	cout << endl;
}

void dfs(vector<int> choice = {}, int maxL = 0, int sumL = 0, int step = 1)
{
	if (step > n)
	{
		if (choice.size() > 2 && sumL > 2 * maxL)
		{
			++cnt;
//			cout << step << ":";
//			dbg(choice);
		}
		return;
	}
	//-----------------------
	if (!mark[step])
	{
		mark[step] = true;
		choice.push_back(sticks[step]);
		dfs(choice,
			max(maxL, sticks[step]),
			sumL + sticks[step],
			step + 1);
		choice.pop_back();
		mark[step] = false;
	}

	dfs(choice,
		maxL,
		sumL,
		step + 1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> sticks[i];
	}
	
	dfs();
	
	cout << cnt % MOD << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
5
1 2 3 4 5

ans = 9

5
2 2 3 8 10

ans = 6

*/
