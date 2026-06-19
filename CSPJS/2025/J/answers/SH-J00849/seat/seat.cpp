#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> score(n * m + 1);
    for(int i = 1; i <= n * m; i++)
    {
    	cin >> score[i];
	}
	int tool = score[1];
	int c = 1, r = 0;
	int i = 1;
	sort(score.begin(), score.end());
	for(; i <= n * m; i++)
	{
		if(score[i] == tool)
		{
			break;
		}
	}
	i = n * m - i + 1;
	for(int index = 1; index <= i; index++)
	{
		if(c % 2 == 1)
		{
			r++;
			if(r > n)
			{
				c++;
				r--;
			}
		}
		else
		{
			r--;
			if(r < 1)
			{
				c++;
				r++;
			}
		}
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
