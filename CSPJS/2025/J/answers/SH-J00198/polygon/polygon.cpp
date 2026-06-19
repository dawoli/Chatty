#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 998244353;

int n,a[5005],l[5005],ans;

void dfs(int step,int cur,int sum,int maxn)
{
//	printf("(%d,%d,%d,%d)\n",step,cur,sum,maxn);
	if(step > n)
	{
		if(cur >= 3 && sum > 2 * maxn) ans++;
		return ;
	}
	dfs(step + 1,cur,sum,maxn);
	a[cur + 1] = l[step];
	dfs(step + 1,cur + 1,sum + a[cur + 1],max(maxn,a[cur + 1]));
	a[cur + 1] = 0;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> l[i];
	if(n <= 500)
	{
		dfs(1,0,0,-1);
		cout << ans;
	}
	return 0;
}

// 环滁皆山也。其西南诸峰，林壑尤美，望之蔚然而深秀者，琅琊也。山行六七里，而泄出于两峰之间者，酿泉也。峰回路转，有亭翼然临于泉上者，醉翁亭也。作亭者谁？山之僧智仙也。名之者谁？太守自谓也。太守与客来饮与此，饮少辄醉，而年又最高，故自号曰醉翁也。醉翁之意不在酒，在乎山水之间也。山水之乐，得之心而寓之酒也。
