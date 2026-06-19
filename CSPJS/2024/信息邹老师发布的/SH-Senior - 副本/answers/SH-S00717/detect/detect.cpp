#include<bits/stdc++.h>
using namespace std;
int t, n, m, L, V;
int d[100100], v[100100], a[100100], p[100100];
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int i = 0; i < n; i++)
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
		for(int i = 0; i < m; i++)
			scanf("%d", &p[i]);
			
		int ans = 0, mma = 0, mmb = 999999;	
			
		if(n * m <= 1000)
		{
			bool cxk = false, cxk2 = false;
			for(int i = 0; i < n; i++)
			{
				
				if(a[i] >= 0)
				{
					cxk2 = true;
					int tm = 0;
					bool flag = false;
					for(int j = m - 1; j >= 0; j--)
					{
						
						if(p[j] >= d[i])
						{
							long long tmp = 1;
							tmp = tmp * 2 * a[i] * (p[j] - d[i]);
//							cout << "tmp:" << tmp << endl;
							tmp += v[i] * v[i];
							if(V * V < tmp && !flag)
							{
								ans++;
								flag = true;
//								printf("I:%d P:%d tmp:%d a:%d\n", i, p[j], tmp, a[i]);
							}
							if(V * V < tmp)
								tm = j;
						}
						
					}
					if(flag)
						mma = max(mma, tm);
				}
				
				
				else
				{
					cxk = true;
					int tm = 0;
					bool flag = false;
					for(int j = 0; j < m; j++)
					{
						if(p[j] >= d[i])
						{
							long long tmp = 1;
							tmp = tmp * 2 * a[i] * (p[j] - d[i]);
//							cout << "tmp:" << tmp << endl;
							tmp += v[i] * v[i];        //这里可能可以二分 
							if(V * V < tmp && !flag)
							{
								ans++;
								flag = true;
//								printf("I:%d P:%d tmp:%d a:%d\n", i, p[j], tmp, a[i]);
							}
							if(V * V < tmp)
								tm = j;
						}
					}
					if(flag)
						mmb = min(mmb, tm);
				}
			}
			if(m == 1 || !cxk) //|| !cxk || !cxk2
				printf("%d 1\n", ans);
//			else if(mma == 0)
//				printf("%d %d\n", ans, m - mmb);
//			else if(mmb == 999999)
//				printf("%d %d\n", ans, mma);
			else
				printf("%d %d\n", ans, mma- mmb);
		}
		
		
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(p[m - 1] >= d[i])
				{
					long long tmp = 1;
					tmp = tmp * 2 * a[i] * (p[m - 1] - d[i]);
					tmp += v[i] * v[i];
					if(V * V < tmp)
						ans++;
				}
			}	
			printf("%d %d\n", ans, max(m - 1, 1));
		}
	}
	return 0;
}
