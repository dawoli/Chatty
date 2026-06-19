#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[100010][3],num[3],kkk[100010];
int biggest(int x)
{
	for(int i = 0;i <= 2;i++)
	{
		bool flag = true;
		for(int j = 0;j <= 2;j++) if(a[x][i] < a[x][j]) flag = false;
		if(flag) return i;
	}
	return -1;
}
int middle(int x,int y)
{
	if(y == 0) return max(a[x][1],a[x][2]);
	else if(y == 1) return max(a[x][0],a[x][2]);
	else return max(a[x][0],a[x][1]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,x,ans = 0;
		num[0] = num[1] = num[2] = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			num[biggest(i)]++;
			ans += a[i][biggest(i)];
		}
		for(int i = 0;i <= 2;i++)
		{
			bool flag = true;
			for(int j = 0;j <= 2;j++) if(num[i] < num[j]) flag = false;
			if(flag)
			{
				x = i;
				break;
			}
		}
		if(num[x] * 2 > n)
		{
			int cnt = 0;
			for(int i = 1;i <= n;i++) if(biggest(i) == x)
				kkk[++cnt] = a[i][x] - middle(i,x);
			sort(kkk + 1,kkk + cnt + 1);
			for(int i = 1;i <= num[x] - n / 2;i++) ans -= kkk[i];
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
