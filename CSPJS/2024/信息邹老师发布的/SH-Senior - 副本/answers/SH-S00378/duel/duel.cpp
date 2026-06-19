#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r[100001];
	int sor[100001];
	int ans = 0;
	int maxn = 0;
	int left = -1,right = 0;
	memset(sor,0,sizeof(sor));
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> r[i];
		maxn = max(maxn,r[i]);
		sor[r[i]]++;
	}
	for(int i = 0;i < maxn+1;++i)
	{
		if(sor[i] > 0)//发现这一个大小存在一定数量的r[i] 
		{
			if(left == -1)//发现这是第一个
				left = sor[i];
			else
			{
				right = sor[i];
				if(right > left)
				{
					left = right;
				}
			} 
		}
	}
	cout << left << endl;
	return 0;
}
//这道题真的良心，我爱CCF 
