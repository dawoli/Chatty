#include<bits/stdc++.h>
using namespace std;
int n,m,seat[15][15],score[110];
bool cmp(int a,int b)
{
	return a >= b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> score[i];
	}
	int t = score[1];
	sort(score + 1,score + (n * m) + 1,cmp);
	int id;
	for(int i = 1;i <= n * m;i++)
	{
		if(score[i] == t)id = i;
	}
	int ans1 = 0,ans2;
	while(id > n * 2)
	{
		ans1 += 2;
		id -= n * 2;
	}
	if(id > n)
	{
		ans1 += 2;
		id -= n;
		ans2 = n - id + 1;
	}
	else
	{
		ans1++;
		ans2 = id;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
