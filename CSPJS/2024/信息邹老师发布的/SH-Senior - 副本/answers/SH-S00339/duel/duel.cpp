#include<bits/stdc++.h>
using namespace std;
int mons[2][100005];
int pre[100005];
int ind;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		pre[a]++;
	}
	for(int i = 0;i < 100001;i++)
	{
		if(pre[i]>0){
			mons[0][ind] = pre[i];//สฃำเสÞสý
			mons[1][ind] = pre[i];//นฅป๗สÞสý
			ind++;
		}
	}
	int i = 0;
	while(mons[0][i])
	{
		for(int j = 0;j<i;j++){
			if(mons[0][j]<mons[1][i])
			{
				mons[1][i] -= mons[0][j];
				mons[0][j] = 0;
				mons[1][j] = 0;
			}else
			{
				mons[0][j] -= mons[1][i];
				mons[1][i] = 0;
				mons[1][j] = 0;
				break;
			}
		}
		i++;
	}
	int ans = 0;
	for(int j = 0;j < ind;j++)
	{
		ans += mons[0][j];
	}
	cout << ans;
	return 0;
}
