#include<bits/stdc++.h>
using namespace std;
long long a[100006][4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		memset(a,sizeof(a),0);
		int n,ans = 0;
		cin >> n;
		int bumen[100006];
		int bu1 = 0;
		int bu2 = 0;
		int bu3 = 0;
		for(int j = 0;j < n;j++)
		{

			cin >> a[j][0] >> a[j][1] >> a[j][2];
			int minn = min(min(a[j][0],a[j][1]),a[j][2]);
			a[j][0] -= minn;
			a[j][1] -= minn;
			a[j][2] -= minn;
			ans += minn;
			int maxn = max(max(a[j][0],a[j][1]),a[j][2]);
			if(a[j][0] == maxn)
			{
				bumen[j] = 0;
				bu1++;
			}else if(a[j][1] == maxn)
			{
				bumen[j] = 1;
				bu2++;
			}else
			{
				bumen[j] = 2;
				bu3++;
			}
		}
		while(bu1 > n/2)
		{
			long long mintrans = 1000000;
			int minind;
			int trans;
			for(int j = 0,ind = 0;j < bu1;j++)
			{
				ind ++;
				if(bumen[ind-1] != 0)
				{
					j--;
					continue;
				}
				mintrans = min(mintrans,a[ind-1][0]-a[ind-1][1]);
				if(mintrans == a[ind-1][0]-a[ind-1][1]) {
					minind = ind-1;
					trans = 1;
				}
				mintrans = min(mintrans,a[ind-1][0]-a[ind-1][2]);
				if(mintrans == a[ind-1][0]-a[ind-1][2]){
					minind = ind-1;
					trans = 2;
				}
			}
			bumen[minind] = trans;
			bu1--;
		}
		while(bu2 > n/2)
		{
			long long mintrans = 1000000;
			int minind;
			int trans;
			for(int j = 0,ind = 0;j < bu2;j++)
			{
				ind++;
				if(bumen[ind-1] != 1)
				{
					j--;
					continue;
				}
				mintrans = min(mintrans,a[ind-1][1]-a[ind-1][0]);
				if(mintrans == a[ind-1][1]-a[ind-1][0]){
					minind = ind-1;
					trans = 0;
				}
				mintrans = min(mintrans,a[ind-1][1]-a[ind-1][2]);
				if(mintrans == a[ind-1][1]-a[ind-1][2]){
					minind = ind-1;
					trans = 2;
				}
			}
			bumen[minind] = trans;
			bu2--;
		}
		while(bu3 > n/2)
		{
			long long mintrans = 1000000;
			int minind;
			int trans;
			for(int j = 0,ind = 0;j < bu3;j++)
			{
				
				ind ++;
				if(bumen[ind-1] != 2)
				{
					j--;
					continue;
				}
				mintrans = min(mintrans,a[ind-1][2]-a[ind-1][1]);
				if(mintrans == a[ind-1][2]-a[ind-1][1]){
					minind = ind-1;
					trans = 1;
				}
				mintrans = min(mintrans,a[ind-1][2]-a[ind-1][0]);
				if(mintrans == a[ind-1][2]-a[ind-1][0]){
					minind = ind-1;
					trans = 0;
				}
			}
			bumen[minind] = trans;
			bu3--;
		}
		for(int j = 0;j < n;j++)
		{
			ans += a[j][bumen[j]];
		}
		cout << ans << endl;
	}
	return 0;
}
