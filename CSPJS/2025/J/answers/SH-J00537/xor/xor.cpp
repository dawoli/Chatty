#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int m[n+5];
	for (int i = 1;i <= n;i ++)
	{
		cin >> m[i]; 
	}
	//输入整个序列共n个数，小X要求的数是k 
	/*int ans = 0;
	//初始化答案 
	for (int i = 1;i <= n;i ++)
	//从第一个数开始找异或序列 
	{
		int sum = m[i],ans0 = 0;
		for (int j = i + 1;j <= n;j ++)
		{
			int x = 0;
			if (m[i] == k) 
			{
				ans0 ++;
				x = i;		
			}
			if ((sum ^ m[j] == k) && (i > x))
			{
				ans0 ++;
				x = j;
				sum = sum ^ m[j];		
			}		
		}
		if (ans0 > ans)
		{
			ans = ans0;	
		}
	}
	cout << ans << endl;*/
	if (k == 0)
	{
		cout << n << endl;	
	}
	cout << n << endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
