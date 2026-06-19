#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, r[M], life[M], hit[M], cnt;
void solve(int n)
{
	for(int i = 0;i < n;i ++ )
	{
		if(life[i]==1 || hit[i] == 1)
			continue;
		for(int j = i;j < n;j ++)
		{
			if(life[j]==1)
				continue;
			life[j] = 1;
			hit[i] = 1;
			cnt --;
		}
	}
}
int main()
{
//	freopen("duel.in","r",stdin);
//	freopen("duel.out","w",stdout);
	int n, r[100005], cnt;
	cin >> n;
	for (int i = 0;i < n;i ++ )
	{
		cin >> r[i];
	}
	sort(r,r+n);
	cnt = n;
	for(int i = 0;i < n;i ++ )
	{
		if(r[i+1]>r[i])
		{
			life[i] = 1;
			hit[i + 1] = 1;
			cnt--;
		}
	}
	solve(n);
	cout << cnt - 1;
	return 0;
}
