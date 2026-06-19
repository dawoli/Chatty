#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int A[200010];
// long long score;
// 0 = red, 1 = blue

bool getcolor(unsigned *x, int y)
{
	return (x[(y - 1) / 32] & (1 << ((y - 1) % 32)));
}

void setcolor(unsigned *x, int y, int z)
{
	if (z)
		x[(y - 1) / 32] |= (1 << ((y - 1) % 32));
	else
		x[(y - 1) / 32] &= ~(1 << ((y - 1) % 32));
}

void solve()
{
	long long ans = 0;
	unsigned state[1];
	for (state[0] = 0; state[0] < (1 << n); state[0]++)
	{
		int red = 0, blue = 0;
		long long score = 0;
		for (int i = 1; i <= n; i++)
		{
			if (getcolor(state, i))
			{
				if (i != 1 && blue == A[i])
					score += A[i];
				blue = A[i];
			}
			else
			{
				if (i != 1 && red == A[i])
					score += A[i];
				red = A[i];
			}
		}
		ans = max(ans, score);
	}
	cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
	
	cin >> T;
    for (int i = 1; i <= T; i++)
    {
    	cin >> n;
    	for (int j = 1; j <= n; j++)
    		cin >> A[j];
    	
    	solve();
	}
	
    return 0;
}
