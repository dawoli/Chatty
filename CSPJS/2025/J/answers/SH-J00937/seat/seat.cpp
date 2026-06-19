#include <bits/stdc++.h>

using namespace std;

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
	bool down = true;
	vector<int> v(n*m,0);
	int target;
	for(int i = 0;i < n*m;i++)
	{
		cin >> v[i];
		if(i == 0)
		{
			target = v[i];
		}
	}
	sort(v.begin(),v.end(),cmp);
	int num = 0;
	for(int i = 1;i <= n;i++)
	{
		if(down)
		{
			for(int j = 1;j <= m;j++)
			{
				if(v[num] == target)
				{
					cout << i << ' ' << j;
					return 0;
				}
				num++;
			}
			down = !down;
		}else{
			for(int j = m;j >= 1;j--)
			{
				if(v[num] == target)
				{
					cout << i << ' ' << j;
					return 0;
				}
				num++;
			}
			down = !down;
		}
	}
	return 0;
}
